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
  pid_t pid;

  printf("$ ");
  leer_de_teclado(BUFSIZ,comando);

  pid = fork();
  if (pid == 0) {
    vector = de_cadena_a_vector(comando);
    execvp(vector[0],vector);
  } else if (pid > 0) {
    wait(NULL);
  } else {
    printf("Error en la ejecución del 'fork'\n");
  }

  return 0;
}

