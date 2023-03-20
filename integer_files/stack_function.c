#include <stdio.h>
#include <stdlib.h>

struct dynamic_array
{
	int *arr;
	int len;
	int allocated;
};

void push (struct dynamic_array *A, int elem) 
{
	if (A->len == A->allocated)
	{
		A->allocated*=2;
		int *new_arr = (int*) malloc(sizeof(int)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr = new_arr;
	}
	A->arr[A->len]=elem;
	A->len+=1;
}


void pop (struct dynamic_array *A)
	{
	if (A->len != 0)
	{
	A->len-=1;
	A->allocated-=1;
	int *new_arr = (int*) malloc(sizeof(int)*(A->allocated));
	for (int i=0; i<A->len; i++)
		new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr = new_arr;
	}
	
	else
		printf("There's nothing to pop!\n");
	}
	

int peak (struct dynamic_array *A)
{
	if (A->len >= 1)
		return *(A->arr + (A->len - 1));
	else
	{
	printf("Your stack is empty\n");
	return 0;
	}
		
}
	












int main()
{
    struct dynamic_array A;
    A.len=0;
    A.arr = (int*) malloc(sizeof(int)*1);
    A.allocated=1;
    push(&A, -1);
    push(&A, 2);
    pop(&A);
    pop(&A);
    pop(&A);
    
    
    
    int last = peak(&A);
    printf("%d\n",last); 
    return 0;
}
