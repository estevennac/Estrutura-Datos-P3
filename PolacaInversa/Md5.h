#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>           
#include <string.h>  
#include <cmath>
#include "Tabla.hpp"
#include <sstream>
using namespace std;


class MD5 {
private:

	bit32 IV[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
	bit32 CV[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };

	int padding_len; // padding_len = 64n
	vector<bit8> paddingMessage;

	int N;
	int L;
	vector<vector<bit32>> Y;



	void padding(string message) {

		int len = message.length();

		int add = len % 64;
		add = (add < 56) ? (56 - add) : (56 + 64 - add);

		padding_len = len + add + 8;

		for (int i = 0; i < len; i++) {
			paddingMessage.push_back(message[i]);
		}

		paddingMessage.push_back(0x80);
		for (int i = len + 1; i < len + add; i++) {
			paddingMessage.push_back(0x00);
		}
		unsigned int bit_len = len * 8;
		char mask = 0xff;
		for (int i = 0; i < 8; i++) {
			paddingMessage.push_back((bit8)((bit_len)&mask));
			bit_len = bit_len >> 8;
		}

	}


	void blocking() {

		N = padding_len / 4;

		L = N / 16;
		for (int i = 0; i < L; i++) {
			vector<bit32> M;
			for (int j = 0; j < 16; j++) {

				bit32 word = 0;
				for (int k = 0; k < 4; k++) {
					word |= (bit32)(paddingMessage[i * 64 + j * 4 + k]) << (k * 8);
				}
				M.push_back(word);
			}
			Y.push_back(M);
		}

	}


	void HMD5() {
		for (int i = 0; i < Y.size(); i++) {
			bit32 A = CV[0];
			bit32 B = CV[1];
			bit32 C = CV[2];
			bit32 D = CV[3];


			for (int j = 0; j < 4; j++) {

				for (int u = 0; u < 16; u++) {
					bit32 a = A;
					bit32 b = B;
					bit32 c = C;
					bit32 d = D;
					bit32 g;// 
					bit32 x;// 
					bit32 t = T[j * 16 + u + 1];// 
					bit8 s = S[j * 16 + u + 1];// 
					switch (j) {
					case 0:
						g = F(b, c, d);
						x = Y[i][u];
						break;
					case 1:
						g = G(b, c, d);
						x = Y[i][(1 + 5 * u) % 16];
						break;
					case 2:
						g = H(b, c, d);
						x = Y[i][(5 + 3 * u) % 16];
						break;
					case 3:
						g = I(b, c, d);
						x = Y[i][(7 * u) % 16];
						break;
					}

					a = b + leftShitf((a + g + x + t), s);

					A = d;
					B = a;
					C = b;
					D = c;

				}
			}
			CV[0] += A;
			CV[1] += B;
			CV[2] += C;
			CV[3] += D;

		}
	}


	bit32 F(bit32 b, bit32 c, bit32 d) {
		return ((b) & (c)) | ((~b) & (d));
	}
	bit32 G(bit32 b, bit32 c, bit32 d) {
		return ((b) & (d)) | ((c) & (~d));
	}
	bit32 H(bit32 b, bit32 c, bit32 d) {
		return (b) ^ (c) ^ (d);
	}
	bit32 I(bit32 b, bit32 c, bit32 d) {
		return (c) ^ ((b) | (~d));
	}


	bit32 leftShitf(bit32 input, bit8 s) {
		return (input << s) | (input >> (32 - s));
	}


	string getDigest() {
		string result = "";
		bit32 mask[4] = { 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000 };
		for (int i = 0; i < 4; i++) {
			stringstream ioss;
			ioss << hex << CV[i];
			string temp;
			ioss >> temp;
			for (int j = 0; j < 8 - temp.size(); j++)
				temp[j] = '0';
			for (int j = 0; j < 4; j++) {
				string s = temp.substr(6 - j * 2, 2);
				result += s;
			}
		}
		return result;
	}

public:

	string getMD5Digest(string message) {

		int K = message.length() * 8;
		padding(message);
		blocking();
		HMD5();
		return getDigest();
	}
};

