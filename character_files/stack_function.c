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
	if (A->len + 1 == A->allocated)//Taking into account the null character
	{
		A->allocated*=2;
		char *new_arr = (char*) malloc(sizeof(char)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
		free(A->arr);
		A->arr = new_arr;
	}
	A->arr[A->len]=elem;
	A->arr[A->len + 1]='\0';
	A->len+=1;
}


void pop (struct dynamic_array *A)
	{
	if (A->len != 0)
	{
		A->len-=1;
		A->allocated-=1;
		char *new_arr = (char*) malloc(sizeof(char)*(A->allocated));
		for (int i=0; i<A->len; i++)
			new_arr[i] = A->arr[i];
			free(A->arr);
			A->arr = new_arr;
			A->arr[A->len] = '\0';
	}
	else
		printf("There's nothing to pop!\n");
	}
	

char peak (struct dynamic_array *A)
{
	if (A->len >= 1)
		return *(A->arr + (A->len - 1));
	else
	{
		printf("Your stack is empty\n");
		return 'N';
	}
}
	












int main()
{
    struct dynamic_array A;
    A.len=0;
    A.arr = (char*) malloc(sizeof(char)*2);//I've written 2 to take into account the null character
    A.allocated=1;
    push(&A, 'e');
    push(&A, 'a');
    push(&A, 'b');
    pop(&A);
    pop(&A);
    
    char last = peak(&A);
    printf("%c\n",last); 
    return 0;
}
