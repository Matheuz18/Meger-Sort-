#include<stdio.h>
#include<stdlib.h>
void CriaArray(int *A,int tam){
	int i;
	for(i=0;i<tam;i++){
		*A = rand()% 10000;
		A++;
	}
}
int main() {
	int i,tam,numberOfElements;;
	
	printf("Digite O Tamanho do vetor : ");
	scanf("%d",&tam);
	
	int A[tam]; 
	CriaArray(A,tam);
	
	numberOfElements = sizeof(A)/sizeof(A[0]); 
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}
