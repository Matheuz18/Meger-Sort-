/* Merge sort in C */
#include<stdio.h>
#include<stdlib.h>

//Função para mesclar matrizes L e R em A.
//lefCount = número de elementos em L
//rightCount = número de elementos em R.
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	//i - para marcar o índice de aubarray esquerdo (L)
	//j - para marcar o índice do sub-raay direito (R)
	//k - para marcar o índice do subarray mesclado (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  >= R[j]) A[k++] = L[i++];// >= para decrescente (garante que o anterior é sempre maior que o anterior)
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

//Função recursiva para classificar uma matriz de inteiros.
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; //condição de base. Se o array tiver menos de dois elementos, não faça nada. 

	mid = n/2;// encontre o índice médio.

	//criar subarrays esquerdo e direito
	//Os elementos intermediários (do índice 0 até o meio-1) devem fazer parte da sub-matriz esquerda
	//e (n-mid) elementos (do meio ao n-1) farão parte do sub-array direito
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; //criando subarray esquerdo
	for(i = mid;i<n;i++) R[i-mid] = A[i];//criando subarray direito

	MergeSort(L,mid);  //ordenando o subarray esquerdo
	MergeSort(R,n-mid);  //classificando o subarray certo
	Merge(A,L,mid,R,n-mid);  //Mesclando L e R em A como lista classificada.
        free(L);
        free(R);
}
void MergeD(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	//i - para marcar o índice de aubarray esquerdo (L)
	//j - para marcar o índice do sub-raay direito (R)
	//k - para marcar o índice do subarray mesclado (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++]; // < para crescente (garante que o anterior é sempre menor que o anterior)
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
void MergeSortD(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;  

	mid = n/2;  
	
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i]; 

	MergeSortD(L,mid);  
	MergeSortD(R,n-mid);  
	MergeD(A,L,mid,R,n-mid); 
    
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
	int j,tam,mid;
	printf("Digite O Tamanho do vetor : ");
	scanf("%d",&tam);
	
	int A[tam]; // creating an array of integers. 
	CriaArray(A,tam); // Criando array aleatorio
	int i,numberOfElements=0;
	
	mid = tam/2;
	
	int  E[mid],D[tam-mid];

	for(i = 0;i<mid;i++) E[i] = A[i]; //criando subarray esquerdo
	for(i = 0;i<tam-mid;i++) D[i] = A[mid+i]; // criando subarray direito
	
	// Decrescente 
	numberOfElements = sizeof(E)/sizeof(E[0]);		// É criado dois vetores apartir do vetor A
	MergeSort(E,numberOfElements);					// Para poder fazer metade crescente e outra decrescente									
	for(i = 0;i<mid;i++)    A[i] = E[i];			// ou vice-versa		
	
	// Crescente
	numberOfElements = sizeof(D)/sizeof(D[0]);			
	MergeSortD(D,numberOfElements);								
	for(i = 0;i<tam-mid;i++)  A[mid+i]= D[i];
	
	numberOfElements = sizeof(A)/sizeof(A[0]);
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);			
	
	return 0;
}
