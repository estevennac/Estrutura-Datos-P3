
//ESTEVEN NACIMBA
#include <iostream>
#include "Arbol.h" 
#include <stdlib.h>

Nodo* arbol = NULL; 
void subMenu(){
	Arbol objArbol;
 	int subOpcion = 0; 
 	while (subOpcion != 4){
 		cout << "\n 1. Preorden";
 		cout << "\n 2. Inorden";
 		cout << "\n 3. Postorden";
 		cout << "\n 4. Regresar";
 		cout << "\n\nDigite una opcion: "; 
 		cin >> subOpcion;
 		system("cls");
 		if( subOpcion == 1 ){
 			objArbol.preOrden(arbol);
 			system("pause");
 			system("cls");
 		}
 		else if(subOpcion == 2){
 			objArbol.inOrden(arbol);
 			cout << endl;
 			system("pause");
 			system("cls");
 		}
 		else if(subOpcion == 3){
 			objArbol.postOrden(arbol);
 			cout << endl;
			 system("pause");
			 system("cls");
 		}
 	}
}


void menu(){
	Arbol objArbol;
	int contador = 0, opcion = 0, dato = 0;
	while(opcion != 5){
		cout << "\n 1. Insertar nodo";
		cout << "\n 2. Mostrar arbol";
		cout << "\n 3. Buscar en el arbol";
		cout << "\n 4. Recorridos de un arbol";
		cout << "\n 5. Informacion del arbol";
		cout << "\n 6. Salir";
		cout << "\n\nDigite una opcion: ";
		cin >> opcion;
	 	system("cls");
	 	if(opcion == 1){
			cout << "Ingrese un dato: ";
 			cin >> dato;
			objArbol.insertarNodo(arbol, dato); 
 /*llammos al objeto para usar el metodo*/
 			cout << endl;
 			system("pause");
 			system("cls");
	 	}
		else if(opcion == 2){
	 		cout << "A R B O L \n" << endl;
	 		objArbol.mostrar(arbol, contador); 
	 		/*llammos al objeto para usar el metodo*/
	 		cout << endl;
	 		system("pause");
	 		system("cls");
	 	}
	 	else if(opcion == 3){
	 		cout << "Digite un elemento a buscar: ";
	 		cin >> dato;
	 		if(objArbol.buscar(arbol, dato) == true){
	 			cout << "Elemento " << dato << " encontrado dentro del arbol" << endl; 
	 		}
	 	else{
	 		cout << "Elemento no pertenece al arbol";
	 	}
	 		cout << endl;
	 		system("pause");
	 		system("cls"); 
	 	}
		else if(opcion == 4){
		 	subMenu(); 
		 	cout << endl;
		 	system("pause");
		 	system("cls");
	 	}
	 	else if(opcion == 5){
	 		int hojas = 0;
		 	cout << endl;
		 	cout << "La altura del arbol es: " << altura(arbol)<<endl;
		 	// N�mero de hojas
				
			// Llame a la funci�n para encontrar el n�mero de nodos hoja
			profundidad(arbol,&hojas);
			printf("\nLa cantidad de hojas es: %d\n", hojas);
			cout << endl;
			cout << "El largo del arbol es: " << largo(arbol)<<endl;
		 	system("pause");
		 	system("cls");
	 	}
	}	
}

int main(){
	
	menu(); /* llamando a la funcion menu */
	cout << endl;
	
 	return 0;
}



#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
};

// Recursive function to calculate height of given binary tree
int height(Node* root)
{
    // Base case: empty tree has height 0
    if (root == NULL)
        return 0;

    // recur for left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}



