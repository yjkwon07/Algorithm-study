#include<stdio.h>
/*
함수를 재귀적으로 호출하여 풀 수있게 된다. 
재귀적으로 함수를 호출 할 경우 낭비되는 메모리 생긴다.
이런 중복연산을 최소화 하기 위해 미리 메모리에 저장하는 방법을 Memoization이라고 한다.  
*/

int f(int n)
{	
	
	if(n < 2)
		return n;	
	else { 
		return f(n-1) + f(n - 2);
	}
}

int main(){
	printf("%d",f(2));
	return 0;
}



