#include<stdio.h>
/*
�Լ��� ��������� ȣ���Ͽ� Ǯ ���ְ� �ȴ�. 
��������� �Լ��� ȣ�� �� ��� ����Ǵ� �޸� �����.
�̷� �ߺ������� �ּ�ȭ �ϱ� ���� �̸� �޸𸮿� �����ϴ� ����� Memoization�̶�� �Ѵ�.  
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



