#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	일곱 난쟁이
	https://www.acmicpc.net/problem/2309

	아홉 명의 난쟁이 중 일곱 명의 난쟁이를 찾는 문제
	일곱 난쟁이의 키의 합은 100이다.
	아홉 명 중에 두 명을 고르는 것과 같다.
	난쟁이의 수를 N이라고 했을 때
	두 명을 고르는 경우의 수: N^2라고 할 수 있다.
	나머지 난쟁이의 키의 합을 고르는 시간복잡도: O(N)
	O(N^2)(방법의 개수) * O(N)(값) = O(N^3)
*/
int main() {

	int n = 9;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((sum - a[i] - a[j]) == 100) {
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue;
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}