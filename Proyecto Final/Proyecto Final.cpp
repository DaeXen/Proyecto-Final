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

void depositarPilaOriginal(Nodo*& pila, int n)
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

void mostrarPilaNoRepetidos(Nodo*& pila, int& n)
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

							for (int i = 0; i < dim2; i++)					//Depositar array en pila
							{
								pilaNoRepetidos(pila2, arr2[i]);
							}

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

							repetidoDone = true;
						}
						system("pause");
						break;

					case 3:
						cout << "ELIGIO VER PILA NUMEROS PARES" << endl;

						if (parDone == true)
						{
							while (pila3 != NULL)							//Mostrar pila
							{
								mostrarPilaNumPar(pila3, n);

								if (pila3 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim3; i++)					//Volver a depositar array en pila
							{
								pilaNumPar(pila3, arr3[i]);
							}
						}
						else
						{
							dim3 = dim;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (pila != NULL)						//Proceso de depositar pila en array
							{
								for (int i = 0; i < dim; i++)
								{
									mostrarPilaNumPar(pila, n);
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

							for (int i = 0; i < dim; i++)				//Proceso para separar pares
							{
								if (arr[i] % 2 == 0)
								{
									arr3[j] = arr[i];
									dim3 = dim3 - 1;
									j++;
								}
							}

							for (int i = 0; i < dim3; i++)					//Depositar array en pila
							{
								pilaNumPar(pila3, arr3[i]);
							}

							while (pila3 != NULL)							//Mostrar pila
							{
								mostrarPilaNumPar(pila3, n);

								if (pila3 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim3; i++)					//Volver a depositar array en pila
							{
								pilaNumPar(pila3, arr3[i]);
							}

							parDone = true;

						}
						system("pause");
						break;

					case 4:
						cout << "ELIGIO VER PILA NUMEROS IMPARES" << endl;

						if (imparDone == true)
						{
							while (pila4 != NULL)							//Mostrar pila
							{
								mostrarPilaNumImpar(pila4, n);

								if (pila4 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim4; i++)					//Volver a depositar array en pila
							{
								pilaNumImpar(pila4, arr4[i]);
							}
						}
						else
						{
							dim4 = dim;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (pila != NULL)						//Proceso de depositar pila en array
							{
								for (int i = 0; i < dim; i++)
								{
									mostrarPilaNumImpar(pila, n);
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

							for (int i = 0; i < dim; i++)				//Proceso para separar impares
							{
								if (arr[i] % 2 == 1 || arr[i] % 2 == -1)
								{
									arr4[j] = arr[i];
									dim4 = dim4 - 1;
									j++;
								}
							}

							for (int i = 0; i < dim4; i++)					//Depositar array en pila
							{
								pilaNumImpar(pila4, arr4[i]);
							}

							while (pila4 != NULL)							//Mostrar pila
							{
								mostrarPilaNumImpar(pila4, n);

								if (pila4 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim4; i++)					//Volver a depositar array en pila
							{
								pilaNumImpar(pila4, arr4[i]);
							}

							imparDone = true;

						}
						system("pause");
						break;

					case 5:
						cout << "ELIGIO VER PILA NUMEROS POSITIVOS" << endl;

						if (posDone == true)
						{
							while (pila5 != NULL)							//Mostrar pila
							{
								mostrarPilaNumPos(pila5, n);

								if (pila5 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim5; i++)					//Volver a depositar array en pila
							{
								pilaNumPos(pila5, arr5[i]);
							}
						}
						else
						{
							dim5 = dim;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (pila != NULL)						//Proceso de depositar pila en array
							{
								for (int i = 0; i < dim; i++)
								{
									mostrarPilaNumPos(pila, n);
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

							for (int i = 0; i < dim; i++)				//Proceso para separar positivos
							{
								if (arr[i] > 0)
								{
									arr5[j] = arr[i];
									dim5 = dim5 - 1;
									j++;
								}
							}

							for (int i = 0; i < dim5; i++)					//Depositar array en pila
							{
								pilaNumPos(pila5, arr5[i]);
							}

							while (pila5 != NULL)							//Mostrar pila
							{
								mostrarPilaNumPos(pila5, n);

								if (pila5 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim5; i++)					//Volver a depositar array en pila
							{
								pilaNumPos(pila5, arr5[i]);
							}

							posDone = true;

						}
						system("pause");
						break;

					case 6:
						cout << "ELIGIO VER PILA NUMEROS NEGATIVOS" << endl;

						if (negDone == true)
						{
							while (pila6 != NULL)							//Mostrar pila
							{
								mostrarPilaNumNeg(pila6, n);

								if (pila6 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim6; i++)					//Volver a depositar array en pila
							{
								pilaNumNeg(pila6, arr6[i]);
							}
						}
						else
						{
							dim6 = dim;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (pila != NULL)						//Proceso de depositar pila en array
							{
								for (int i = 0; i < dim; i++)
								{
									mostrarPilaNumNeg(pila, n);
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

							for (int i = 0; i < dim; i++)				//Proceso para separar negativos
							{
								if (arr[i] < 0)
								{
									arr6[j] = arr[i];
									dim6 = dim6 - 1;
									j++;
								}
							}

							for (int i = 0; i < dim6; i++)					//Depositar array en pila
							{
								pilaNumNeg(pila6, arr6[i]);
							}

							while (pila6 != NULL)							//Mostrar pila
							{
								mostrarPilaNumNeg(pila6, n);

								if (pila6 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							for (int i = 0; i < dim6; i++)					//Volver a depositar array en pila
							{
								pilaNumNeg(pila6, arr6[i]);
							}

							negDone = true;
						}
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
			if (pila == NULL)
			{
				cout << "ERROR. DEBE EXISTIR AL MENOS UNA PILA" << endl;
			}
			else
			{
				if (pila != NULL)
				{
					pila = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
				if (pila2 != NULL)
				{
					pila2 = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
				if (pila3 != NULL)
				{
					pila3 = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
				if (pila4 != NULL)
				{
					pila4 = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
				if (pila5 != NULL)
				{
					pila5 = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
				if (pila6 != NULL)
				{
					pila6 = NULL;
					cout << "ELIGIO ELIMINAR LA PILA ORIGINAL" << endl;
				}
			}
			system("pause");
			break;

		case 5:
			if (pila != NULL || pila2 != NULL || pila3 != NULL || pila4 != NULL || pila5 != NULL || pila6 != NULL)
			{
				cout << "ERROR. DEBE ELIMINAR TODAS LA PILAS" << endl;
			}
			else
			{
				cout << "ELIGIO SALIR. HASTA LUEGO" << endl;
				finish = true;
			}
			system("pause");
			break;

		default:
			cout << "OPCION INVALIDA" << endl;
			system("pause");
			break;
		}
	} while (finish != true);

	return 0;
}