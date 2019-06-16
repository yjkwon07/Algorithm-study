#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
	ºÐÇØÇÕ
	https://www.acmicpc.net/problem/2231
*/
#define MAX 1000000
long long ans = MAX;
string n;
long long arr[MAX];

long long splits(long long i) {
	string temp = to_string(i);
	long long sum = 0;
	for (long long k = 0; k < temp.length(); k++) {
		sum += temp[k] - '0';
	}
	sum += i;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int nn = stoi(n);
	for (long long i = 0; i <= nn; i++) {
		long long checks = splits(i);
		if (checks == nn)
			ans = min(ans, i);
	}
	if (ans == MAX)
		ans = 0;
	cout << ans << '\n';
	return 0;
}