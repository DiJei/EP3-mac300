/*Como passo inicial para construçao do nosso
ep3, vamo efetuar aqui uma multiplicacao de duas matrizes
de forma otimizada para a linguagem c  ou seja atravez de linha
e não coluna*/


#include <stdio.h>
#include <stdlib.h>
/*Prototipos*/
FILE  *openSafe(char arquivo[]);
float **pegaMatriz(FILE *arquivo, int n);
void produtoMatriz(float **A,float **B, int n);

/*programa principal*/
int main (int argc, char** argv) {
  /*Declarações*/
  FILE *arquivo1;
  FILE *arquivo2;
  float **A; 
  float **B;
  int n1;
  int n2;
  int x,y;
  /*pega as matrizes*/
  arquivo1 = openSafe(argv[1]);
  arquivo2 = openSafe(argv[2]);
  fscanf(arquivo1,"%d",&n1);
  fscanf(arquivo2,"%d",&n2); 

  
  A = pegaMatriz(arquivo1, n1);
  B = pegaMatriz(arquivo2, n2);
 
  
   /*Imprime matriz Apenas teste*/
   printf("\nPrimeira matriz\n" );
   for(x = 0; x < n1; x++) {
   	   for(y = 0; y < n1; y ++)
   	   	printf("%f ",A[x][y]);

       printf("\n"); 
   }

   /*Imprime matriz Apenas teste*/
   printf("\nsegunda matriz\n" );
   for(x = 0; x < n2; x++) {
   	   for(y = 0; y < n2; y ++)
   	   	printf("%f ",B[x][y]);

       printf("\n"); 
   }



  return 0;
}


/*Corpo das funcoes*/

FILE *openSafe(char arquivo[]) {
    FILE * f;
    f = fopen(arquivo,"r");  
    if (f == NULL) {
   	  printf("Falha para abrir arquivo\n");
          exit(EXIT_FAILURE); 
  }
   return f;    
}


float **pegaMatriz(FILE *arquivo, int n) {
   int x,y;
   float **A;
   A = malloc( n * sizeof (float *));
   int i;
   for (i = 0; i < n; i++)
      A[i] = malloc( n * sizeof (float));
   
   
   for (i = 0; i < (n * n); i++){
      fscanf(arquivo,"%d %d",&x,&y);
      fscanf(arquivo,"%f",&A[x][y]);
   }
   return A;
}

void produtoMatriz(float **A,float **B, int n) {
	
}