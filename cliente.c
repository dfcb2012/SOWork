#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include "structs.h"


int main(){

int fifo_c, fifo_s, ler_p;
data cliente;

	sprintf(cliente.pid_cliente, "pipe_cliente%d", getpid());

	mkfifo(cliente.pid_cliente, 0666);

	fifo_s = open("pipe_servidor", O_WRONLY);
	fifo_c = open(cliente.pid_cliente, O_RDWR);

	while(1){
		printf("\n\n1º Numero: ");
		scanf("%d", &cliente.n1);
		printf("\n2º Numero: ");
		scanf("%d", &cliente.n2);
		printf("\nOperacao: ");
		scanf("%s", cliente.opt);
		write(fifo_s, &cliente, sizeof(data));
		ler_p = read(fifo_c, &cliente, sizeof(data));
		printf("Resultado: %d", cliente.result);
	}
	close(fifo_c);
	close(fifo_s);
	unlink(cliente.pid_cliente);
}