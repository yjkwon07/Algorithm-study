#include <stdio.h>
#define MAXCAMDIDATES 100
#define NMAX 100

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i;
	bool in_perm[NMAX] = {0,};
	
	for(i =0; i <k; i++) in_perm[ a[i] ]=1;
	
	*ncandidates = 0;
	for(i =1; i<=n; i++)
		if(in_perm[i] == 0)
		{
			c[ *ncandidates ] = i;
			(*ncandidates)++;
		}
}

void backtrack(int a[], int k, int input)
{
		int c[MAXCAMDIDATES] = {0,};
		int ncandidates =0;
		int i =0;
		
		if(k == input) 
		{
			for(i = 1; i <= k ; i++)
				printf(" %d", a[i]);
				printf("\n");
		}
		else
		{
			k++;
			construct_candidates(a, k , input, c, &ncandidates);
			for(i = 0; i < ncandidates; i++)
			{
				a[k] = c[i];
				backtrack(a, k, input);
			}
		}
}

int main() 
{
	int a[NMAX];
	backtrack(a , 0, 3);
	
}

