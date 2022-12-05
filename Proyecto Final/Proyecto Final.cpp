#include<vector>
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x, y, n, dim = 0, dim2 = 0, dim3 = 0, dim4 = 0, dim5 = 0, dim6 = 0;
int j, k, l = 0;															//Variables para pasar a array dedicado
int q = 0, w, temp = 0;														//Variables para invertir array
bool repetidoDone = false, mostrarOriginalDone = false,
parDone = false, imparDone = false, posDone = false, negDone = false, finish = false;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

void agregarPila(Nodo*& pila, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	cout << "\nElemento " << n << " agregado exitosamente" << endl;
}

void pilaTemporal(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void pilaNoRepetidos(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void eliminarNodo(Nodo*& pila, int& n)
{
	Nodo* eliminar = pila;
	n = eliminar->dato;
	pila = eliminar->siguiente;
	delete eliminar;
}

void mostrarPilaOriginal(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void mostrarPilaTemporal(Nodo*& pila, int& n)
{
	Nodo* mostrar2 = pila;
	n = mostrar2->dato;
	pila = mostrar2->siguiente;
}

void pilaOriginal(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void noRepetidos(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void pilaNumPar(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void mostrarPilaNumPar(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void pilaNumImpar(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void mostrarPilaNumImpar(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void pilaNumPos(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void mostrarPilaNumPos(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

void pilaNumNeg(Nodo*& pila, int n)
{
	Nodo* temporal = new Nodo();
	temporal->dato = n;
	temporal->siguiente = pila;
	pila = temporal;
}

void mostrarPilaNumNeg(Nodo*& pila, int& n)
{
	Nodo* mostrar = pila;
	n = mostrar->dato;
	pila = mostrar->siguiente;
}

int main()
{
	Nodo* pila = NULL;
	Nodo* pila2 = NULL;
	Nodo* pila3 = NULL;
	Nodo* pila4 = NULL;
	Nodo* pila5 = NULL;
	Nodo* pila6 = NULL;
	int* arr = new int[dim];			//Arrray pila original
	//arr = 0;
	int* arr2 = new int[dim2];			//Array para no repetidos
	//arr2 = 0;
	int* arr3 = new int[dim3];			//Array para pares
	//arr3 = 0;
	int* arr4 = new int[dim4];			//Array para impares
	//arr4 = 0;
	int* arr5 = new int[dim5];			//Array para positivos
	//arr5 = 0;
	int* arr6 = new int[dim6];			//Array para negativos
	//arr6 = 0;

	do
	{
		system("cls");
		cout << "MENU PILAS\n*************************************" << endl;
		cout << "	1.AGREGAR NODO\n	2.ELIMINAR UN SOLO NODO DE LA PILA ORIGINAL\n	3.VER PILAS" << endl;
		cout << "	4.ELIMINAR TODAS LAS PILAS\n	5.SALIR\n";
		cout << "*************************************" << endl;
		cout << "¿Que opcion elige? ";
		cin >> x;

		switch (x)
		{

		case 1:
			cout << "ELIGIO AGREGAR NODO" << endl;
			cout << "Digite un numero" << endl;
			cin >> n;
			agregarPila(pila, n);
			dim = dim + 1;
			system("pause");
			break;

		case 2:
			cout << "ELIGIO ELIMINAR NODO" << endl;
			if (pila == NULL)
			{
				cout << "ERROR. AUN NO EXISTE UN NODO" << endl;
			}
			else
			{
				dim = dim - 1;
				eliminarNodo(pila, n);
				cout << "Nodo eliminado" << endl;
			}
			system("pause");
			break;

		case 3:
			repetidoDone = false, mostrarOriginalDone = false, parDone = false, imparDone = false, posDone = false, negDone = false, finish = false;
			if (pila == NULL)
			{
				cout << "ERROR. AL MENOS DEBE HABER UN NODO" << endl;
			}
			else
			{
				do {
					system("cls");
					cout << "SUBMENU 3\n*************************************" << endl;
					cout << "	1.TODA LA PILA ORIGINAL\n	2.PILA SIN NUMEROS REPETIDOS\n	3.PILA NUMEROS PARES\n	4.PILA NUMEROS IMPARES\n	5.PILA NUMEROS POSITIVOS\n	6.PILA NUMEROS NEGATIVOS\n	7.REGRESAR AL MENU PRINCIPAL\n";
					cout << "*************************************" << endl;
					cout << "ELIJA OPCION SUBMENU ";
					cin >> y;

					switch (y)
					{
					case 1:
						cout << "ELIGIO VER PILA ORIGINAL" << endl;

						if (mostrarOriginalDone == true)
						{
							while (pila != NULL)							//Mostrar pila
							{
							mostrarPilaOriginal(pila, n);

							if (pila != NULL)
							{
								cout << n << ",";
							}
							else
							{
								cout << n << "." << endl;
							}
						}

							for (int i = 0; i < dim; i++)					//Depositar array en pila
							{
								depositarPilaOriginal(pila, arr[i]);
							}
						}
						else
						{
							q = 0;
							w = dim - 1;
							temp = 0;

							while (pila != NULL)						//Proceso de depositar pila en array
							{
								for (int i = 0; i < dim; i++)
								{
									pilaOriginal(pila, n);
									arr[i] = n;
								}
							}

							while (q < w)								//Proceso para invertir array
							{
								temp = arr[q];
								arr[q] = arr[w];
								arr[w] = temp;

								q++;
								w--;
							}

							for (int i = 0; i < dim; i++)					//Depositar array en pila
							{
								depositarPilaOriginal(pila, arr[i]);
							}

							while (pila != NULL)							//Mostrar pila
							{
								mostrarPilaOriginal(pila, n);

								if (pila != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim; i++)					//Depositar array en pila
							{
								depositarPilaOriginal(pila, arr[i]);
							}

							mostrarOriginalDone = true;
						}
						system("pause");
						break;

					case 2:
						cout << "ELIGIO VER PILA SIN NUMEROS REPETIDOS" << endl;

						if (repetidoDone == true)
						{
							while (pila2 != NULL)							//Mostrar pila
							{
								mostrarPilaNoRepetidos(pila2, n);

								if (pila2 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim2; i++)					//Volver a depositar array en pila
							{
								pilaNoRepetidos(pila2, arr2[i]);
							}
						}
						else
						{
						dim2 = dim;
							w = dim - 1;

							while (pila != NULL)						//Proceso de depositar pila en array
						{
							for (int i = 0; i < dim; i++)
							{
								noRepetidos(pila, n);
								arr[i] = n;
							}
						}

							while (q < w)								//Proceso para invertir array
						{
								temp = arr[q];
								arr[q] = arr[w];
								arr[w] = temp;

								q++;
								w--;
						}

							for (j = 0; j < dim; j++)					//Proceso para eliminar repetidos
						{
							for (k = 0; k < l; k++)
							{
								if (arr[j] == arr2[k])
								{
									dim2 = dim2 - 1;
									break;
								}
							}

							if (k == l)
							{
								arr2[l] = arr[j];
								l++;
							}
						}

						cout << "\n" << endl;

						for (int i = 0; i < dim2; i++)
						{
							cout << arr2[i];
						}

						cout << "\n" << endl;

						for (int i = dim2; i > 0; i--)
						{
							arr3[dim2-i] = arr2[i];
						}

						for (int i = 0; i < dim2; i++)
						{
							cout << arr3[i];
						}

						cout << "\n" << endl;

						for (int i = 0; i < dim2; i++)
						{
							pilaTemporal(pila2, arr2[i]);
						}

						while (pila2 != NULL)
						{
							mostrarPilaTemporal(pila2, n);

							if (pila2 != NULL)
							{
								cout << n << ",";
							}
							else
							{
								cout << n << "." << endl;
							}
						}
						system("pause");
						break;

					case 3:
						cout << "ELIGIO VER PILA NUMEROS PARES" << endl;
						system("pause");
						break;

					case 4:
						cout << "ELIGIO VER PILA NUMEROS IMPARES" << endl;
						system("pause");
						break;

					case 5:
						cout << "ELIGIO VER PILA NUMEROS POSITIVOS" << endl;
						system("pause");
						break;

					case 6:
						cout << "ELIGIO VER PILA NUMEROS NEGATIVOS" << endl;
						system("pause");
						break;

					case 7:
						break;

					default:
						cout << "OPCION INVALIDA" << endl;
						system("pause");
						break;
					}
				} while (y != 7);
			}
			system("pause");
			break;

		case 4:
			cout << "ELIGIO ELIMINAR TODA LA PILA";
			break;

		case 5:
			cout << "ELIGIO SALIR. HASTA LUEGO" << endl;
			break;

		default:
			cout << "OPCION INVALIDA" << endl;
			system("pause");
			break;
		}
	} while (x != 5);

	return 0;
}
