#include<stdio.h>

int testCase;
char input[10001];

char stack[10001];
int stackCounter;

char pair[256] = {0,};

int main(){
	int i;
	
	// 짝이 되는 괄호를 할당한다.
	pair['('] = ')';
	pair['['] = ']';
	pair['{'] = '}';
	
	scanf("%d", &testCase);
	
	while(testCase--) {
		stackCounter = 0; // 스택을 비운다.
		
		scanf("%d", &i);
		scanf("%s", input);
	
		while(i--) {
			
			if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
				stack[stackCounter++] =input[i]; // PUSH
			}
				
			else
			{
				if(stackCounter == 0) // 짝 지을 괄홀가 없으므로 무효 
					break;
				else if(stack[stackCounter -1] == pair[input[i]])// 스택의 탑에 있는 괄호와 input의 괄호와 짝이 되는지 확인
					stackCounter--; // pop
				else // 짝이 되지 않으므로 무효
					break;
			 } 

		} 
		if (i == -1 && stackCounter ==0)
			printf("1\n");
		else
			printf("0\n");
	}
}
