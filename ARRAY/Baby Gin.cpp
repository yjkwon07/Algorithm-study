// baby -Gin 
//  https://swexpertacademy.com/main/learn/course/lectureHtmlViewer.do#none

#include<stdio.h>

int main(void) {
	int input =0;
	int c[10] = {0, };
	int tri = 0;
	int run = 0;
	
	scanf("%d", &input);
	
	for(int i =0; i < 6; i++) { //각 자리 숫자를 카운팅 
		c[(input % 10 )]++;
		input /= 10;
	}

	for(int i = 0; i <10; i++){
		if(c[i] >= 3) { // triplet 조사
			c[i] -= 3; 
			tri += 1;
			i--; 
		}
		if( (c[i] >= 1) && (c[i + 1] >= 1) && (c[i+2] >= 1)) { // run 조사 
			c[i] -= 1;
			c[i + 1] -= 1; 
			c[i + 2] -= 1;
			run += 1;
			i--;
		}
	}

	printf("%d", tri + run);
	if(run + tri == 2)
		printf("Baby Gin");
	else
		printf("Lose");
}
