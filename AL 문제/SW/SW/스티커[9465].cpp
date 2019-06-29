#include<iostream>
#include<algorithm>
using namespace std;
/*
	스티커 
	https://www.acmicpc.net/problem/9465

	스티커 2n개가 2 *n모양으로 배치되어 있다.
	스티커 한 장을 떼면 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없다.
	점수의 합을 최대로 만드는 문제
	D[i][j] = 2 * i에서 얻을 수 있는 최대 점수, i번 열에서 뜯는 스티커는 j
	j = 0 -> 뜯지 않음
	 i - 1열에서 스티커를 어떻게 뜯었는지 상관이 없다
	max(D[i-1][0], D[i-1][1], D[i-1][2])
	j = 1-> 위쪽 스티커를 뜯음
	 i - 1열에서 위쪽 스티커는 뜯으면 안된다.
	max(D[i-1][0], D[i-1][2] + A[i][0])
	j =2 -> 아래쪽 스티커를 뜯음
	 i - 1열에서 스티커를 어떻게 뜯었는지 상관이 없다
	max(D[i-1][0], D[i-1][1] + A[i][1])

*/
long long a[100001][2];
long long D[100001][3];
int main() {

	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i][0];
		}
		for (int i = 1; i <= m; i++) {
			cin >> a[i][1];
		}
		D[0][0] = 0;
		D[0][1] = 0;
		D[0][2] = 0;
		for (int i = 1; i <= m; i++) {
			D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + a[i][0];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= m; i++)
			ans = max(max(ans, D[i][0]), max(D[i][1], D[i][2]));
		cout << ans << '\n';
	}
	return 0;
}