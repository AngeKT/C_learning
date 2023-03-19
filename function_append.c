#include <stdio.h>
#include <stdlib.h>

struct dynamic_array
{
	int *arr;
	int len;
	int allocated;
};

void append(struct dynamic_array *A, int elem)
{
	if (A->len == A->allocated)
	{
		A->allocated*=2;
		int *new_arr = (int*)malloc(sizeof(int)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr=new_arr;
	}
	A->arr[A->len]=elem;
	A->len+=1;
}

int main()
{
 struct dynamic_array A;
 A.len=0;
 A.arr=(int*)malloc(sizeof(int)*1);
 A.allocated=1;
 append(&A,5);
 
	
 return 0;
}
