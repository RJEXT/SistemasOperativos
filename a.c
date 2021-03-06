/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  int i;
  int a=0;

  while (1) {
    pid_t pid;
    
    while (a==0) {
      printf("Indique el programa que desea se ejecute\n");
      a=a+1;
    }
    printf("$ ");
    leer_de_teclado(BUFSIZ,comando);
    if (strcmp("exit",comando) == 0) {
      break;
    } else if (strcmp("salir",comando) == 0) {
      break;
    }
    pid = fork();
    if (pid < 0) {
      perror("No se pudo crear un proceso\n");
      exit(1);
    } else if (pid == 0) {
      vector = de_cadena_a_vector(comando);
      execvp(vector[0],vector);
      perror("Return from execlp() not expected");
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }
  }

  return 0;
}
