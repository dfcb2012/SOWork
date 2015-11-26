#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void timeout(){
n = n-1;



}


int main() {
   int a, b;
   
   srand(time(NULL));
   signal(SIGALARM, timeout);
   pont = 0;
   tentativas = 3;
   n = 10;


   while(1){
     defineprox();
     scanf("%d", & resp);
     if (resp == a+b){
       pont++;
       printf("\nacertaste"); fflush(stdout);
     }
     else{
      tentativas

     }
   }
   a = (int)(100.0 * random()/RAND_MAX);
   b = (int)(100.0 * random()/RAND_MAX);

   printf("A = %d", a);
   printf("B = %d", b);

}
