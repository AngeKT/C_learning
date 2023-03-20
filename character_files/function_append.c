#include <stdio.h>
#include <stdlib.h>

struct dynamic_array
{
	char *arr;
	int len;
	int allocated;
};

void append(struct dynamic_array *A, char elem)
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

int main()
{
 struct dynamic_array A;
 A.len=0;
 A.arr=(char*) malloc(sizeof(char)*2);//Taking into account the null character
 A.allocated=2;
 append(&A,'r');
 append(&A,'z');
 append(&A,'e');
 append(&A,'f');
 append(&A,'v');
 
 printf("%s\n",A.arr);
 return 0;
}
