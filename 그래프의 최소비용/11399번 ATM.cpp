#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int n , sum = 0;

int main(void) {
	cin >> n;
	for(int i =0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i =0; i <n; i++) {
		sum += a[i] * (n-i);
	}
	cout << sum << '\n';
	return 0;
}
