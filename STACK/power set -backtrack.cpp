#include <stdio.h>
#define MAXCAMDIDATES 100
#define NMAX 100
void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	c[0] = 1;
	c[1] = 0; 
	*ncandidates = 2; 
}

void backtrack(int a[], int k, int input)
{
	int c[MAXCAMDIDATES] = {0,};
	int ncandidates = 0;
	int i = 0;
	
	if ( k == input ) // 답이면 원하는 작업을 한다. 
	{
		printf("(");
		for( i =0; i <= k; i++)
			if(a[i] == 1)
				printf("%d", i);
		printf(")\n"); 
	 } 
	 else 
	 {
	 	k++;
	 	construct_candidates(a, k , input , c , &ncandidates); 
	 	for( i = 0; i < ncandidates; i++) 
	 	{
	 		a[k] = c[i];
	 		backtrack(a, k ,input);
		 }
	 }
}


int main() 
{
	int a[NMAX];
	backtrack(a , 0, 3);
	
}
