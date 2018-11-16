#include<stdio.h>

int stack[8] = {0, };
int top =-1;
int vistied[8] = {0, };
int arr[8][8] = {0, };

void push( int v)
{
	printf("%d", v);
	stack[++top] = v;
	vistied[v] = 1;
	return ;
}

void pop() 
{
	top --;
	return;
}
void dfs(int v)
{
	push(v);
	
	while(top >= 0) {
		for(int i =1; i <=7; i++) {
			if(vistied[i] == 0 && arr[stack[top]][i] == 1) {
				push(i);
				i = 1;
			}
		}
		pop();
	}
}

int main() {
	int a , b; 
	for (int i = 0; i < 7; i++) { 
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(1);
	return 0;
}

