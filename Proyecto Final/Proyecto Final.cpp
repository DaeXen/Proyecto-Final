#include<vector>
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x, y, n, dim = 0, dim2 = 0, dim3 = 0, dim4 = 0, dim5 = 0, dim6 = 0, 
dim_aux = 0, dim_aux3 = 0, dim_aux4 = 0, dim_aux5 = 0, dim_aux6 = 0;

int j, k, l = 0;																		//Variables para pasar a array dedicado
int q = 0, w, temp = 0;																	//Variables para invertir array

bool repetidoDone = false, mostrarOriginalDone = false,
parDone = false, imparDone = false, posDone = false, negDone = false,
finish = false, reentry = false, procesoDone = false, change = false;

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

void agregarPila2(Nodo*& pila, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
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
	Nodo* pilatemp = NULL;
	Nodo* pilatemp2 = NULL;
	Nodo* pila2 = NULL;
	Nodo* pila3 = NULL;
	Nodo* pila4 = NULL;
	Nodo* pila5 = NULL;
	Nodo* pila6 = NULL;
	int* arr = new int[dim];				//Array pila original
	int* arr2 = new int[dim2];				//Array para no repetidos
	int* arr_aux2 = new int[dim_aux];		//Array auxiliar para no repetidos
	int* arr3 = new int[dim3];				//Array para pares
	int* arr_aux3 = new int[dim_aux];		//Array auxiliar para pares
	int* arr4 = new int[dim4];				//Array para impares
	int* arr_aux4 = new int[dim_aux];		//Array auxiliar para impares
	int* arr5 = new int[dim5];				//Array para positivos
	int* arr_aux5 = new int[dim_aux];		//Array auxiliar para positivos
	int* arr6 = new int[dim6];				//Array para negativos
	int* arr_aux6 = new int[dim_aux];		//Array auxiliar para negativos

	do
	{
		system("cls");
		cout << "MENU PILAS\n*************************************" << endl;
		cout << "	1.AGREGAR NODO\n	2.ELIMINAR UN SOLO NODO DE LA PILA ORIGINAL\n	3.VER PILAS" << endl;
		cout << "	4.ELIMINAR TODAS LAS PILAS\n	5.SALIR\n";
		cout << "*************************************" << endl;
		cout << "?Que opcion elige? ";
		cin >> x;

		switch (x)
		{

		case 1:
			cout << "ELIGIO AGREGAR NODO" << endl;
			cout << "Digite un numero" << endl;
			cin >> n;
			agregarPila(pila, n);								//Se agrega elemento a la pila
			agregarPila2(pilatemp, n);							//Se agrega elemento a pila temporal
			dim = dim + 1;										//Aumenta dimension de la pila

			if (reentry == true && change == true)				//Si ya se salio del submenu y realizo un cambio, se cambia a falso el bool de proceso que esta mas abajo
			{
				procesoDone = false;
			}
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
				dim = dim - 1;											//Disminuye la dimension de la pila
				eliminarNodo(pila, n);									//Se elimina elemento de la pila
				eliminarNodo(pilatemp, n);								//Se elimina elemento de la pila temporal
				cout << "Nodo eliminado" << endl;
				change = true;											//Se realizo un cambio entonces cambio es verdadero
			}
			system("pause");
			break;

		case 3:
			
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

					if (procesoDone != true)						//Si ya se generaron los arrays entonces ya no se vuelve a realizar este proceso
					{
						dim2 = dim;									//Definiendo dimensiones 
						dim3 = dim;
						dim4 = dim;
						dim5 = dim;
						dim6 = dim;

						while (pilatemp != NULL)						//Proceso de depositar pila en array
						{
							for (int i = 0; i < dim; i++)
							{
								pilaOriginal(pilatemp, n);
								arr[i] = n;
							}
						}

						for (int i = 0; i < dim; i++)				//Pasar arrays para cada array individual
						{
							arr2[i] = arr[i];
							arr3[i] = arr[i];
							arr4[i] = arr[i];
							arr5[i] = arr[i];
							arr6[i] = arr[i];
						}

						if (reentry == true && change == true)			//Si ya se ha salido de el submenu y se ha realizado un cambio entonces las condiciones de las pilas es falsa y se vuelve a realizar todo el proceso
						{
							repetidoDone = false, mostrarOriginalDone = false, parDone = false, imparDone = false, posDone = false, negDone = false;
						}

						procesoDone = true;								//Ya se realizo este proceso entonces se hace verdadero para que no vuelva a correr
					}

					cin >> y;

					switch (y)
					{
					case 1:
						cout << "ELIGIO VER PILA ORIGINAL" << endl;

						if (mostrarOriginalDone == true)					//Si ya se realizo el proceso de generar la pila entonces se hace un procedimiento 
						{													//de solo volver a depositar el array ya generado en la pila y se muestra
							for (int i = 0; i < dim; i++)			//Depositar array en pila
							{
								depositarPilaOriginal(pilatemp2, arr[i]);
							}

							while (pilatemp2 != NULL)							//Mostrar pila
							{
								mostrarPilaOriginal(pilatemp2, n);

								if (pilatemp2 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}
						}
						else
						{
							q = 0;
							w = dim - 1;
							temp = 0;

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
								depositarPilaOriginal(pilatemp2, arr[i]);
							}

							while (pilatemp2 != NULL)							//Mostrar pila
							{
								mostrarPilaOriginal(pilatemp2, n);

								if (pilatemp2 != NULL)
								{
									cout << n << ",";
								}
								else
								{
									cout << n << "." << endl;
								}
							}

							mostrarOriginalDone = true;				//Ya se genero la pila entonces el bool se hace verdadero
						}
						system("pause");
						break;

					case 2:
						cout << "ELIGIO VER PILA SIN NUMEROS REPETIDOS" << endl;

						if (repetidoDone == true)								//Si ya se realizo el proceso de general la pila entonces se hace un procedimiento 
						{														//de solo volver a depositar el array ya generado en la pila y se muestra
							for (int i = 0; i < dim_aux; i++)				//Volver a depositar array en pila
							{
								pilaNoRepetidos(pila2, arr_aux2[i]);
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
						}
						else
						{
							dim_aux=dim2;
							q = 0;
							w = dim - 1;
							temp = 0;
							l = 0;
							

							while (q < w)								//Proceso para invertir array
							{
								temp = arr2[q];
								arr2[q] = arr2[w];
								arr2[w] = temp;

								q++;
								w--;
							}

							for (j = 0; j < dim2; j++)					//Proceso para eliminar repetidos
							{
								for (k = 0; k < l; k++)					//Es un proceso de donde si detecta un elemento repetido interrumpe el ciclo y continua
								{										//al siguiente elemento
									if (arr2[j] == arr_aux2[k])
									{
										dim_aux = dim_aux - 1;
										break;
									}
								}

								if (k == l)
								{
									arr_aux2[l] = arr2[j];
									l++;
								}
							}

							for (int i = 0; i < dim_aux; i++)					//Depositar array en pila
							{
								pilaNoRepetidos(pila2, arr_aux2[i]);
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

							repetidoDone = true;
						}
						system("pause");
						break;

					case 3:
						cout << "ELIGIO VER PILA NUMEROS PARES" << endl;

						if (parDone == true)
						{
							for (int i = 0; i < dim_aux3; i++)					//Volver a depositar array en pila
							{
								pilaNumPar(pila3, arr_aux3[i]);
							}

							if (pila3 == NULL)
							{
								cout << "NO HAY ELEMENTOS PARES A MOSTRAR" << endl;
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
						}
						else
						{
							dim_aux3 = dim3;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (q < w)								//Proceso para invertir array
							{
								temp = arr3[q];
								arr3[q] = arr3[w];
								arr3[w] = temp;

								q++;
								w--;
							}

							for (int i = 0; i < dim3; i++)				//Proceso para separar pares
							{
								if (arr3[i] % 2 == 0)					//Si detecta que el residuo de un elemento es igual a 0 entonces este va a ser depositado
								{										//en otro array y si no detecta uno con residuo igual a cero entonces este es impar y va a disminuir la dimension del array ya que no se depositara en este
									arr_aux3[j] = arr3[i];
									j++;
								}
								else
								{
									dim_aux3 = dim_aux3 - 1;
								}
							}

							for (int i = 0; i < dim_aux3; i++)					//Depositar array en pila
							{
								pilaNumPar(pila3, arr_aux3[i]);
							}

							if (pila3 == NULL)
							{
								cout << "NO HAY ELEMENTOS PARES A MOSTRAR" << endl;
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

							parDone = true;

						}
						system("pause");
						break;

					case 4:
						cout << "ELIGIO VER PILA NUMEROS IMPARES" << endl;

						if (imparDone == true)
						{
							for (int i = 0; i < dim_aux4; i++)					//Volver a depositar array en pila
							{
								pilaNumImpar(pila4, arr_aux4[i]);
							}

							if (pila4 == NULL)
							{
								cout << "NO HAY ELEMENTOS IMPARES A MOSTRAR" << endl;
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
						}
						else
						{
							dim_aux4 = dim4;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (q < w)								//Proceso para invertir array
							{
								temp = arr4[q];
								arr4[q] = arr4[w];
								arr4[w] = temp;

								q++;
								w--;
							}

							for (int i = 0; i < dim4; i++)				//Proceso para separar impares
							{
								if (arr4[i] % 2 == 1 || arr4[i] % 2 == -1)				//Mismo procedimiento al anterior pero ahora si detecta que el residuo es
								{														//1 o -1 entonces el elmento es depositado 
									arr_aux4[j] = arr4[i];
									j++;
								}
								else
								{
									dim_aux4 = dim_aux4 - 1;
								}
							}

							for (int i = 0; i < dim_aux4; i++)					//Depositar array en pila
							{
								pilaNumImpar(pila4, arr_aux4[i]);
							}

							if (pila4 == NULL)
							{
								cout << "NO HAY ELEMENTOS IMPARES A MOSTRAR" << endl;
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

							imparDone = true;

						}
						system("pause");
						break;

					case 5:
						cout << "ELIGIO VER PILA NUMEROS POSITIVOS" << endl;

						if (posDone == true)
						{
							for (int i = 0; i < dim_aux5; i++)					//Volver a depositar array en pila
							{
								pilaNumPos(pila5, arr_aux5[i]);
							}

							if (pila5 == NULL)
							{
								cout << "NO HAY ELEMENTOS POSITIVOS A MOSTRAR" << endl;
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
						}
						else
						{
							dim_aux5 = dim5;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (q < w)								//Proceso para invertir array
							{
								temp = arr5[q];
								arr5[q] = arr5[w];
								arr5[w] = temp;

								q++;
								w--;
							}

							for (int i = 0; i < dim5; i++)				//Proceso para separar positivos
							{
								if (arr5[i] > 0)						//Si el elemento es mayor a 0 entonces este es positivo y se desposita
								{
									arr_aux5[j] = arr5[i];
									j++;
								}
								else
								{
									dim_aux5 = dim_aux5 - 1;
								}
							}

							for (int i = 0; i < dim_aux5; i++)					//Depositar array en pila
							{
								pilaNumPos(pila5, arr_aux5[i]);
							}

							if (pila5 == NULL)
							{
								cout << "NO HAY ELEMENTOS POSITIVOS A MOSTRAR" << endl;
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

							posDone = true;

						}
						system("pause");
						break;

					case 6:
						cout << "ELIGIO VER PILA NUMEROS NEGATIVOS" << endl;

						if (negDone == true)
						{
							for (int i = 0; i < dim_aux6; i++)					//Volver a depositar array en pila
							{
								pilaNumNeg(pila6, arr_aux6[i]);
							}

							if (pila6 == NULL)
							{
								cout << "NO HAY ELEMENTOS NEGATIVOS A MOSTRAR" << endl;
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
						}
						else
						{
							dim_aux6 = dim6;
							q = 0;
							w = dim - 1;
							temp = 0;
							j = 0;

							while (q < w)								//Proceso para invertir array
							{
								temp = arr6[q];
								arr6[q] = arr6[w];
								arr6[w] = temp;

								q++;
								w--;
							}

							for (int i = 0; i < dim6; i++)				//Proceso para separar negativos
							{
								if (arr6[i] < 0)						//Mismo procedimiento al anterior pero ahora si el elemento es menor a 0 este se deposita
								{
									arr_aux6[j] = arr6[i];
									j++;
								}
								else
								{
									dim_aux6 = dim_aux6 - 1;
								}
							}

							for (int i = 0; i < dim_aux6; i++)					//Depositar array en pila
							{
								pilaNumNeg(pila6, arr_aux6[i]);
							}

							if (pila6 == NULL)
							{
								cout << "NO HAY ELEMENTOS NEGATIVOS A MOSTRAR" << endl;
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

							negDone = true;
						}
						system("pause");
						break;

					case 7:
						reentry = true;					//Si se elije la opcion 7 para salir entonces se hace verdadera reentry para verificar cambios despues
						change = false;					//Change regresa a ser falso para que no afecte el procedimiento y se ejecute
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
			{													//else para eliminar todas las pilas
				while (pila != NULL)
				{
					eliminarNodo(pila, n);
				}
				while (pilatemp != NULL)
				{
					eliminarNodo(pilatemp, n);
				}
				while (pilatemp2 != NULL)
				{
					eliminarNodo(pilatemp2, n);
				}
				while (pila2 != NULL)
				{
					eliminarNodo(pila2, n);
				}
				while (pila3 != NULL)
				{
					eliminarNodo(pila3, n);
				}
				while (pila4 != NULL)
				{
					eliminarNodo(pila4, n);
				}
				while (pila5 != NULL)
				{
					eliminarNodo(pila5, n);
				}
				while (pila6 != NULL)
				{
					eliminarNodo(pila6, n);
				}
				dim = 0, dim2 = 0, dim3 = 0, dim4 = 0, dim5 = 0, dim6 = 0, dim_aux = 0, dim_aux3 = 0, dim_aux4 = 0, dim_aux5 = 0, dim_aux6 = 0;		//las dimensiones se regresan a 0
				change = true;				//Se realizo un cambio a las pilas enotnces change es verdadero

				cout << "ELIMINO TODAS LAS PILAS" << endl;
			}
			system("pause");
			break;
			
		case 5:
			if (pila != NULL || pilatemp != NULL || pilatemp2 != NULL || pila2 != NULL || pila3 != NULL || pila4 != NULL || pila5 != NULL || pila6 != NULL)			//Si alguna pila tiene informacion enotnces no se puede salir el menu
			{
				cout << "ERROR. DEBE ELIMINAR TODAS LA PILAS" << endl;
			}
			else
			{
				cout << "ELIGIO SALIR. HASTA LUEGO" << endl;
				finish = true;											//bool para salir del switch case y terminar el programa
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