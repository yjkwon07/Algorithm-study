#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
/*
	DSLR
	https://www.acmicpc.net/problem/9019
	(2)번 풀이보다 2배 빠름 

	A에서 B로 변환하기 위한 최소의 명령어 나열을 구하는 문제다. 
	변환 명령어는 총 4가지가 있으며, 최소 명령어 나열을 구해야 하므로, BFS를 사용하면 된다. 
	명령어 리스트는 역순으로 추적하면 된다.

	레지스터를 변환하는 명령어는 총 4가지이다.
	현재 레지스터를 X라 했을 때, 
	명령어에 의해 변환되는 다음 레지스터를 Y라 하자. 
	각 명령에 따른 레지스터는 아래와 같이 나타낼 수 있다.
	명령어 D : Y = (X*2) % 10000
	명령어 S : Y = X-1 (단, Y < 0일 경우, Y = 9999)
	명령어 L : Y = (X%1000)*10 + X/1000
	명령어 R : Y = X/10 + (X%10)*1000
	
	위 4가지 명령어에 따라, BFS로 레지스터(숫자)를 탐색하고, 
	이동 경로와 명령어를 별도의 리스트에 저장한다.
	A부터 출발해서 B에 도착하면, B부터 A로 역순으로 올라가면서 명령어를 저장한다. 
	그리고 이를 역순으로 출력한다.
*/
const int N = 10000, M = 1000;
char C[] = "DSLR";
int A, B;
bool check[N];
int path[N], command[N];

void bfs() {
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == B) {
			vector<char> v;
			int mx = x;
			while (mx != A) {
				v.push_back(command[mx]);
				mx = path[mx];
			}
			int m = v.size();
			for (int i = 0; i<m; i++) printf("%c", v[m - i - 1]);
			printf("\n");
			return;
		}
		int nx[] = { x * 2 % N, x - 1, x%M * 10 + x / M, x / 10 + x % 10 * M };
		if (nx[1] < 0) nx[1] = N - 1;
		for (int i = 0; i<4; i++) {
			if (check[nx[i]]) continue;
			check[nx[i]] = true;
			path[nx[i]] = x;
			command[nx[i]] = C[i];
			q.push(nx[i]);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		memset(check, false, sizeof(check));
		bfs();
	}
	return 0;
}