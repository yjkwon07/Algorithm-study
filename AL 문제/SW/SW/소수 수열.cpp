#include<iostream>
using namespace std;
/*
	소수 수열
*/
#define MAX 30000
int arrA[MAX];
int arrB[MAX];
bool checkedA[MAX];
bool checkedB[MAX];
int ansA, ansB;

void init() {
	memset(arrA, 0, sizeof(arrA));
	memset(arrB, 0, sizeof(arrB));
}
void input() {
		
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		init();
		input();
		solve();
	}
	return 0;
}