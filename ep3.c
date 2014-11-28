#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*FUNÇÕES*/
float **pegaMatriz(FILE *arquivo, int n, int m);
float  *pegaVetor(FILE *arquivo,int n);
FILE   *openSafe(char arquivo[]);
float **buildQR(float **A, int n, int m);
void rowUperTriang(float **A, float *b, int n);

/*Mais importante*/
float minionSqaureSolution(float **R,float *b,int n, int m);


/*programa principal*/
int main (int argc, char** argv) {
  /*Declarações*/
  FILE *arquivo;
  float **A; 
  float *b;
  int n;
  int m;
  int x,y;
  float a;
   
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


float **pegaMatriz(FILE *arquivo, int n, int m) {
   int x,y;
   float **A;
   A = malloc( n * sizeof (float *));
   int i;
   for (i = 0; i < m; i++)
      A[i] = malloc( m * sizeof (float));
   
   
   for (i = 0; i < (n * m); i++){
      fscanf(arquivo,"%d %d",&x,&y);
      fscanf(arquivo,"%f",&A[x][y]);
   }
   return A;
}

float *pegaVetor(FILE *arquivo,int n) {
   float *b; 
   int x,i;
   b = malloc( n * sizeof (float));
   for (i = 0; i < n; i++) { 
      fscanf(arquivo,"%d",&x);
       fscanf(arquivo,"%f",&b[x]);
   }
   return b;
}




/*PRONTA para usar no EP3,sqn champs*/
void rowUperTriang(float **A,float *b, int n) {
   int i,j;
   for(i = (n-1); i >= 0; i--) {
    for(j = (n-1); j >= (i+1); j--)
      b[i] -= A[i][j] * b[j];
    if( A[i][i] == 0) { 
      printf(" SINGULAR ");
      break;
    }
    b[i] *=  pow(A[i][i], -1.0); 
    
   }
}


/*Parte do Tonino */
float **buildQR(float **A, int n, int m) {
   int k = 0;
   int i;
   double r;
   double y;
   for(;k < n-1; k++) {
      r = 0;
     /*PRIMEIRO PASSO: ENCONTRAR Qk(na verdade u, e y)  
      /*Encontra, o maior elemento em modulo*/
      double max = 0;
      for (i = k; i < n; i++) {
        if (A[i][k] < 0)
          A[i][k] *= -1;
        if (A[i][k] > max)
          max = A[i][k];
      }
      /*-------------------------------------*/ 
      
      /*Coluna nula*/
      if( max == 0) break;
      /*-----------*/
      
      /*Agora divide coluna atula pelo max, para evitar over e under flows*/
      for (i = k; i < n; i++)
        A[i][k] /= max;
      /*------------------------------------------------------------------*/
      
      /*Calcua norma dois da coluna da subMatrix Ak*/
      for (i = k; k < n; k++) 
         r += (A[i][k] * A[i][k]); 
      r = sqrt(r);
      /*-------------------------------------------*/
      
      if (A[k][k] < 0) r *= -1;/*Evitar porrivel soma 0*/
      A[K][K] += r;
      
      y =  A[K][K] / r;
      
      /*Agora normaliza nosso vetor, dividindo por A[k][k]*/
      for (i = k + 1; k < n; k++)
        A[i][k] /= A[K][K];
      /*--------------------------------------------------*/
     A[k][k] = 1;
     r = max * r;
     /*SEGUNDO PASSO: Efetuar a Q*B indiretamente*/ 
     
     
   }
}

/*Solução dos quadrados minimos com QR já feita*/
float minionSqaureSolution(float **R, float *b,int n, int m) {
  /*Primeiro Monta Qb, para depois aplicarmos */
  float y;
  int k;
  
  for (k = 0; k < m; k++) {
   /*y(k)*/
   y = A[k][k];
   
   /*Acha v transposto que é igual u transposto vezes y*/
   int x;
   for (x = k + 1; x < m; x++) 
      A[x][k] = A[k][k]; 
   
   /*Agora faz v transposto por b*/
   float total = 0;
   for (x = 0; x < n; x++) {
      if (x > k || x < m)
        total += A[x][k] + b[x]; 
      else
        total += b[x];
   }
   /*Agora u vezes total*/
   for (x = i + 1; x < m; x++) 
     A[x][i] *= total;
  
  /*Constroi nosso vetor v equivalente a b mas na QR*/
  for (x = 0; x < n; x++) 
    if (x > i)
      b[x] -= A[x][i] 
    else 
      if (x == i) 
      b[x] -= 1; 
  }
  /*Agora resolvermos sistema triangular superio*/
  

  

  return 1.0;
}