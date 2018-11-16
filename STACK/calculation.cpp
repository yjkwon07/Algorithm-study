#include<stdio.h>

#define STACK_MAX_SIZE 1000
#define STRING_MAX_LENGTH 1000

// 입력된 수식을 후위표기법으로 변경하기 위한 스택
char notationStack[STACK_MAX_SIZE];
int notationStackCount;
int notationStackPush(char c) ;
int notationStackPop(char &c);
int notationStackTop(char &c);
int notationStackIsEmpty();
int notationStackIsFull();

// 후위표기법으로 표기된 수식을 계산하기 위한 스택
int calculationStack[STACK_MAX_SIZE];
int calculationStackCount;
int calculationStackPush(int i);
int calculationStackPop(int &i);
int calculationStackIsEmpty();
int calculationStackISFull();

// 연산자 우선순위 
int priority(char c)  {
	if (c == '(') return 5;
	else if (c == '*') return 1;
	else if (c == '+') return 2;
	else return -1;
}

int main() {
	int length; // 입력되는 수식의 길이
	char input[STACK_MAX_SIZE]; // 입력되는 수식
	
	char ans[STRING_MAX_LENGTH]; // 수식을 후위 표기법으로 저장 
	int ansLength; // 후위 표기법으로 표기된  수식의 기링
	 
	int temp;
	char temp2;
	char temp3; 
	
	int &i_temp = temp;
	char &c_temp = temp2; 
	char &c_temp2 = temp3;
	
	int i, j;
	int t;
	
	while(t--) {
		notationStackCount =0;
		notationStackCount =0;
		
		ansLength =0;
		
		// 입력된 수식을 후위 표기법으로 변경하기 
		for(j = 0; j < length; j++) {
			if (input[j] >= '0' && input[j] <= '9') 
				ans[ansLength++] = input[j];
						
			else {
				if(input[j] == '(')
					notationStackPush(input[j]);
					
				else if (input[j] == ')') { 
					notationStackTop(c_temp);
					while(c_temp != '(') {
						notationStackPop(c_temp2);
						ans[ansLength] = c_temp2;
						notationStackTop(c_temp);
					}
					notationStackPop(c_temp2);
				}
				
				else{
					notationStackTop(c_temp);
					if(notationStackIsEmpty() != 1) {
						while(priority(input[j] >= priority(c_temp))) {
							notationStackPop(c_temp2);
							ans[ansLength++] = c_temp2;
							notationStackTop(c_temp);
							if(notationStackIsEmpty() == 1)
								break;	
						}
					}  
					notationStackPush(input[j]);
				}
			}
		}
		while (notationStackIsEmpty() != 1) {
			notationStackPop(c_temp2);
			ans[ansLength] = c_temp2;
			ansLength++;
		}
		// 계산하기 
		int x, y;
		
		int &xx = x;
		int &yy = y; 
		
		for(j =0; j < ansLength; j++) {
			if(ans[j] >= '0' && ans[j] <= '9') {
				calculationStackPush((int)(ans[j] - 48));
			}
			else if(ans[j] == '*') {
				calculationStackPop(xx);
				calculationStackPop(yy);
				calculationStackPush(xx * yy);
			}
			
			else if(ans[j] == '+') {
				calculationStackPop(xx);
				calculationStackPop(yy);
				calculationStackPush(xx + yy);
			}
		}
		calculationStackPop(xx);
		printf("%d\n" , xx);
	}
	return 0; 
	 
}
