#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>           
#include <string.h>  
#include <cmath>
#include <exception>
#include <sstream>
#include <Windows.h>
#include <algorithm>
#include "Md5.h"
#include "tabla.hpp"

namespace Utils
{
    enum InputType
    {
        USER,
        PASSWORD,
        WORD,
        OTHER
    };

    class Validation
    {
    public:
        static inline bool string_is_valid(const std::string& str);
        static inline int read_int(std::string, int min_digits = 1, int max_digits = 20);
        static inline std::string read_string(std::string label, int state, size_t size = 20);
        static inline bool is_ASCII(std::string& s);
        static inline bool format_password(std::string& password);
        static inline bool string_valid(std::string& str);
    };

    class Login
    {
    public:
        static inline bool login(std::string& user, std::string& password);
        static inline void encrypt(std::string& password);
        static inline void decrypt(std::string& password);
        static inline std::string masking_password(std::string label);
    };
    class File
    {
    public:
        static inline bool write_file(std::string& user, std::string& password);
        static inline bool read_file(std::string& user, std::string& password);
        static inline bool update_file(std::string& user, std::string& password);
        //static inline void load_tree(AvlTree& tree, std::string file_path, int type);
        //static inline void save_tree(AvlTree& tree, std::string file_path);
        //template <typename T, typename U>
        //static inline void load_table(HashTable<T, U>& table, std::string file_path, int language);
        //template <typename T, typename U>
        //static inline void save_table(HashTable<T, U>& table, std::string file_path);
        static inline bool exists_file(const std::string name);
    };


    class Generator
    {
    public:
        static inline void generate_admins(std::string& user, std::string& password);
        static inline void remove_number(std::string& str);
    };

    ///////////////////////////////////////////////////////////////////////////
    inline bool Validation::string_is_valid(const std::string& str)
    {
        //regular expression to validate a string
        std::regex reg(
            "(?:[[:space:]]*"
            "([[:alpha:]_]+)"
            "[[:space:]]*)+");
        return std::regex_match(str, reg);
    }

    inline int Validation::read_int(std::string label, int min_digits, int max_digits)
    {
        int input;
        do
        {
            std::cout << label;
            std::cin >> input;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                continue;
            }

            int total_digits = static_cast<int>((input == 0 ? 1 : std::log10(std::abs(input)) + 1));

            if (total_digits < min_digits || total_digits > max_digits)
            {
                if (min_digits == max_digits)
                {
                    std::cout << std::endl
                        << "[ingrese un valor de " << max_digits << " digitos" << std::endl;
                }
                else
                {
                    std::cout << std::endl
                        << "[ingrese un valor entre "
                        << min_digits << " y " << max_digits << " digitos]" << std::endl;
                }
                continue;
            }
            break;
        } while (true);

        return input;
    }
    
    inline std::string Validation::read_string(std::string label, int state, size_t size)
    {
        std::string input;
        if (state == InputType::USER)
        {
            std::cout << label;
            std::getline(std::cin, input, '\n');
            
            while (input.size() ==0)
            {
                std::cout << "\nFormato incorrecto." << std::endl;
                
                input.clear();
                std::cout << label;
                std::getline(std::cin, input, '\n');
                
               // break;
                //input = Login::masking_password(input);
            }
        }
        if (state == InputType::PASSWORD)
        {
            std::cout << label;
            input = Login::masking_password(input);
            while (input.size()==0)
            {
                std::cout << "\nFormato incorrecto." << std::endl;
                input.clear();
                std::cout << label;
                input = Login::masking_password(input);
            }
        }
        return input;
        
    }

    inline bool Validation::is_ASCII(std::string& s)
    {
        return !std::any_of(s.begin(), s.end(), [](char c)
            { return static_cast<unsigned char>(c) > 127; });
    }

    inline bool Validation::format_password(std::string& password)
    {
        for (char& c : password)
        {
            if (isdigit(c) || isalpha(c))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    inline bool Validation::string_valid(std::string& str)
    {
        return std::all_of(str.begin(), str.end(), ::isalpha);
    }

    //////////////////////////////////////////////////////////////////////////
    inline bool Login::login(std::string& user, std::string& password)
    {
        std::string temp_user = user;
        std::string temp_password;
        if (Utils::File::read_file(temp_user, temp_password))
        {
            if (password == temp_password)
            {
                return true;
            }
        }
        return false;
    }

    inline void Login::encrypt(std::string& password)
    {
        std::string encrypted_password = "";
        std::string::iterator it = password.begin();

        for (; it != password.end(); ++it)
        {
            encrypted_password += static_cast<char>(*it + 1);
        }
        password = encrypted_password;
        //std::cout<<MD5::MD5(password);
    }

    inline void Login::decrypt(std::string& password)
    {
        std::string decrypted_password = "";
        std::string::iterator it = password.begin();
        for (; it != password.end(); ++it)
        {
            decrypted_password += static_cast<char>(*it - 1);
        }
        password = decrypted_password;
    }

    inline std::string Login::masking_password(std::string label)
    {

        std::string result;

        // Set the console mode to no-echo, not-line-buffered input
        DWORD mode, count;
        HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
        HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
        if (!GetConsoleMode(ih, &mode))
            throw std::runtime_error(
                "getpassword: You must be connected to a console to use this program.\n");
        SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

        // Get the password string
        WriteConsoleA(oh, label.c_str(), label.length(), &count, NULL);
        char c;
        while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
        {
            if (c == '\b')
            {
                if (result.length())
                {
                    WriteConsoleA(oh, "\b \b", 3, &count, NULL);
                    result.erase(result.end() - 1);
                }
            }
            else
            {
                WriteConsoleA(oh, "#", 1, &count, NULL);
                result.push_back(c);
            }
        }

        // Restore the console mode
        SetConsoleMode(ih, mode);

        return result;
    }

    ////////////////////////////////////////////////////////////////////////////
    inline bool File::write_file(std::string& user, std::string& password)
    {

        std::ofstream file("user.txt", std::ios::out | std::ios::binary | std::ios::app);
        //Utils::Login::encrypt(password);
       // MD5::MD5(password);
        if (file.is_open())
        {
            MD5 md5 = MD5();
            string md5_password = md5.getMD5Digest(password);
            // cout << "Your MD5 Digest:" << endl << md5_password << endl;
            file << user << ":" << md5_password << std::endl;

            file.close();
        }
        else
        {
            return false;
        }
        return true;
    }
    inline bool File::read_file(std::string& user, std::string& password)
    {
        std::ifstream file("user.txt", std::ios::in | std::ios::binary);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line, '\n'))
            {
                std::string::size_type pos = line.find(':');
                if (pos != std::string::npos)
                {
                    std::string user_read = line.substr(0, pos);
                    if (user_read == user)
                    {
                        user = user_read;
                        password = line.substr(pos + 1);
                        Utils::Login::decrypt(password);
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            file.close();
        }
        return false;
    }

    inline bool File::update_file(std::string& user, std::string& password)
    {
        std::ofstream file("user.txt", std::ios::out | std::ios::binary);
        //Utils::Login::encrypt(password);
        if (file.is_open())
        {
            file << user << ":" << password << std::endl;
            file.close();
        }
        else
        {
            return false;
        }
        return true;
    }





    /* template <typename T, typename U>
     inline void File::load_table(HashTable<T, U>& table, std::string file_path, int language)
     {
         enum Language
         {
             ENGLISH = 1,
             SPANISH = 2,
         };
         std::ifstream file(file_path, std::ios::in);
         std::string line;
         std::string spanish;
         std::string english;
         while (!file.eof())
         {
             std::getline(file, line);
             english = line.substr(0, line.find(","));
             spanish = line.substr(line.find(",") + 1, line.length());
             if (language == Language::ENGLISH)
             {
                 table.insert(english, spanish);
             }
             if (language == Language::SPANISH)
             {
                 table.insert(spanish, english);
             }
         }
         file.close();
     }

     template <typename T, typename U>
     inline void File::save_table(HashTable<T, U>& table, std::string file_path)
     {
         std::wofstream file(file_path, std::ios::out | std::ios::binary);
         table.for_each([&](T key, U value)
             {
                 if (file.is_open())
                 {
                     file << key.data() << "," << value.data() << "\n";
                 };
             });
         file.close();
     }
     */

    inline bool File::exists_file(const std::string name)
    {
        std::ifstream f(name.c_str());
        return f.good();
    }
    //////////////////////////////////////////////////////////////////////
    inline void Generator::generate_admins(std::string& new_user, std::string& new_password)
    {
        Utils::File::write_file(new_user, new_password);
    }

    inline void Generator::remove_number(std::string& str)
    {
        std::string result;
        for (char& c : str)
        {
            if (!isdigit(c))
            {
                result += c;
            }
        }
        str = result;
    }
}