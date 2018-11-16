// 비트 연산자 활용 
// 부분 집합의 합 

#include <stdio.h> 
int main(void) {
	int i, j;
	int arr[] = {-7 , -3, -2, 5, 8};
	int n = sizeof(arr) / sizeof(arr[0]); // n: 원소의 개수 
	int sum;
	
	int ret =0;
	printf("n: %d\n", n);
	for(int i =1; i < (1 << (n)); i++ ) {
		sum = 0; 
		printf("%d\n",i);
		
		for( int j =0; j < n; j++) {
			printf("%d",i & (1 << j));
			if( i & (1 << j)){
				sum += arr[j];
			}
		}
		printf("\n");
		if( sum == 0) {
			ret = 1; 
			break;
		}
	}
	printf("%d\n",sum);
	
	printf("%s \n", ret ? "True" :"False");
}
