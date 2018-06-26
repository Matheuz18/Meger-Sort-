#include<stdio.h>
#include<stdlib.h>

//Fun��o para mesclar matrizes L e R em A.
//lefCount = n�mero de elementos em L
//rightCount = n�mero de elementos em R.
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	//i - para marcar o �ndice de aubarray esquerdo (L)
	//j - para marcar o �ndice do sub-raay direito (R)
	//k - para marcar o �ndice do subarray mesclado (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++]; // < para crescente (garante que o anterior � sempre menor que o anterior)
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

//Fun��o recursiva para classificar uma matriz de inteiros.
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;//condi��o de base. Se o array tiver menos de dois elementos, n�o fa�a nada. 

	mid = n/2; // encontre o �ndice m�dio.

	//criar subarrays esquerdo e direito
	//Os elementos intermedi�rios (do �ndice 0 at� o meio-1) devem fazer parte da sub-matriz esquerda
	//e (n-mid) elementos (do meio ao n-1) far�o parte do sub-array direito
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; //criando subarray esquerdo
	for(i = mid;i<n;i++) R[i-mid] = A[i]; //criando subarray direito

	MergeSort(L,mid);  //ordenando o subarray esquerdo
	MergeSort(R,n-mid);  //classificando o subarray certo
	Merge(A,L,mid,R,n-mid);  //Mesclando L e R em A como lista classificada.
        free(L);
        free(R);
}

void CriaArray(int *A,int tam){
	int i;
	
	for(i=0;i<tam;i++){
		*A = rand()% 10000;
		A++;
	}
	
}
int main() {
	int tam;
	printf("Digite O Tamanho do vetor : ");
	scanf("%d",&tam);
	
	int A[tam]; // creating an array of integers. 
	CriaArray(A,tam); // Criando array aleatorio
	int i,numberOfElements;

    // encontrar o n�mero de elementos na matriz como tamanho da matriz completa em bytes divididos pelo tamanho do inteiro em bytes.
	// Isso n�o funcionar� se array for passado para a fun��o porque array
	// � sempre passado por refer�ncia atrav�s de um ponteiro. Portanto, a fun��o sizeOf dar� o tamanho do ponteiro e n�o o array.
	// Veja este v�deo para entender este conceito - http://www.youtube.com/watch?v=CpjVucvAc3g
	
	numberOfElements = sizeof(A)/sizeof(A[0]); 

	// Chamando merge sort para ordenar o array.
	MergeSort(A,numberOfElements);

	// imprimindo todos os elementos no array assim que ele for classificado
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}
