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


int soma(int *n1, int *n2){

int result = 0;

	result = *n1 + *n2;
	
return result;
}

int subtr(int *n1, int *n2){

int result = 0;

	result = *n1 - *n2;
	
return result;

}

int mult(int *n1, int *n2){

int result = 0;

	result = *n1 * *n2;
	
return result;

}

int divisao(int *n1, int *n2){

int result = 0;

	result = *n1 / *n2;

return result;

}

int main(){

int total = 0, fifo_s, res_s, fifo_c, ler_p;
char opt[2];
data cliente;


	if (res_s = mkfifo("pipe_servidor", 0666) != 0){
		perror("Erro ao criar pipe do servidor\n");
		exit(1);
	}

	fifo_s = open("pipe_servidor", O_RDWR);

	while(1){
		ler_p = read(fifo_s, &cliente, sizeof(data));
		strcpy(opt, cliente.opt);

		switch(opt[0]){
			case '+': total = soma(&cliente.n1, &cliente.n2);
					  break;

			case '-': total = subtr(&cliente.n1, &cliente.n2);
					  break;

			case '*': total = mult(&cliente.n1, &cliente.n2);
					  break;

			case '/': total = divisao(&cliente.n1, &cliente.n2);
					  break;

			default: printf("Operação Invalida\n");
					 break;
		}
		fifo_c = open(cliente.pid_cliente, O_WRONLY);
		printf("\nNome do Cliente a enviar info: %s\n\n", cliente.pid_cliente);
		cliente.result = total;
		write(fifo_c, &cliente, sizeof(data));
		close(fifo_c);
	}
	close(fifo_s);
	unlink("pipe_servidor");
}