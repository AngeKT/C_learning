#include <stdio.h>
#include <stdlib.h>

struct dynamic_array
{
	char *arr;
	int len;
	int allocated;
};

void push (struct dynamic_array *A, char elem) 
{
	if (A->len == A->allocated)
	{
		A->allocated*=2;
		char *new_arr = (char*)malloc(sizeof(char)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr = new_arr;
	}
	A->arr[A->len]=elem;
	A->len+=1;
}


void pop (struct dynamic_array *A, int indice, int *count)
	{
	A->arr[indice]='\0';
	A->len-=1;
	*count+=1;
	if (*count % 2 == 0)
	{
		A->allocated-=2;
		char *new_arr = (char*)malloc(sizeof(char)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr = new_arr;
	}
	
	}
	

	












int main()
{
 
 	
 	
 	
 	
 	

return 0;
}
