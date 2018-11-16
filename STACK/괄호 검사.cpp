#include<stdio.h>

int testCase;
char input[10001];

char stack[10001];
int stackCounter;

char pair[256] = {0,};

int main(){
	int i;
	
	// ¦�� �Ǵ� ��ȣ�� �Ҵ��Ѵ�.
	pair['('] = ')';
	pair['['] = ']';
	pair['{'] = '}';
	
	scanf("%d", &testCase);
	
	while(testCase--) {
		stackCounter = 0; // ������ ����.
		
		scanf("%d", &i);
		scanf("%s", input);
	
		while(i--) {
			
			if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
				stack[stackCounter++] =input[i]; // PUSH
			}
				
			else
			{
				if(stackCounter == 0) // ¦ ���� ��Ȧ�� �����Ƿ� ��ȿ 
					break;
				else if(stack[stackCounter -1] == pair[input[i]])// ������ ž�� �ִ� ��ȣ�� input�� ��ȣ�� ¦�� �Ǵ��� Ȯ��
					stackCounter--; // pop
				else // ¦�� ���� �����Ƿ� ��ȿ
					break;
			 } 

		} 
		if (i == -1 && stackCounter ==0)
			printf("1\n");
		else
			printf("0\n");
	}
}
