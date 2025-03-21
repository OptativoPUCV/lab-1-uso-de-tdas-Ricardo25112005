#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for (int k = 1; k <= 10; k++){
      int *elemento = (int*)malloc(sizeof(int));
      *elemento = k;
      pushBack(L, elemento);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int* elemento = first(L);   
   while(elemento != NULL){
      suma += *elemento;
      elemento = next(L);   
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* actual = first(L);
   while (actual != NULL){
      if (*actual == elem){
         popCurrent(L);
         actual = next(L);
      }
      else {actual = next(L);}
   }
}
/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* auxiliar =  create_stack();
   while (top(P1) != NULL){
      int *elemento = (int*)top(P1);
      push(auxiliar, elemento);
      pop(P1);
   }
   while (top(auxiliar) != NULL){
      int *elemento = (int*)top(auxiliar);
      push(P1, elemento);
      push(P2, elemento);
      pop(auxiliar);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack *pila = create_stack();

    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        if (c == '(' || c == '{' || c == '[') {
            char *char_ptr = (char *)malloc(sizeof(char));
            *char_ptr = c;
            push(pila, char_ptr);
         } 
        else if (c == ')' || c == '}' || c == ']') {
            if (top(pila) == NULL) return 0;

            char tope = *(char *)top(pila);
            if ((c == ')' && tope != '(') ||
                (c == '}' && tope != '{') ||
                (c == ']' && tope != '[')) {
                return 0; 
            }
            free(pop(pila));
         }
   }
   return 1;
   /*Stack* auxiliar = create_stack();
   Stack* auxiliar2 = create_stack();
   Stack* auxiliar3 = create_stack();
   for(int i = 0; cadena[i] != '\0'; i++){
      char caracter = cadena[i];
      char *char_ptr = (char *)malloc(sizeof(char));
      *char_ptr = caracter;
      push(auxiliar,char_ptr);
      push(auxiliar3, char_ptr);
   }
   while(top(auxiliar) != NULL){
      push(auxiliar2, top(auxiliar));
      pop(auxiliar);   
   }
   while(top(auxiliar2) != NULL){
      if (top(auxiliar2) != top(auxiliar3)) return 0;
      pop(auxiliar2);
      pop(auxiliar3);
   }*/
   return 1;
}

