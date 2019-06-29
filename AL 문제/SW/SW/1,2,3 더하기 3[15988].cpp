#include<iostream>
using namespace std;
/*
	1, 2, 3 더하기3 
	https://www.acmicpc.net/problem/15988

	정수 n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 문제( n <= 1,000,000)
*/
long long d[1000001];
const long long mod = 1000000009LL;
int main() {
	//d[1] = 1;
	//d[2] = 2;
	//d[3] = 4;
	d[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
		
		d[i] %= mod;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}

}
