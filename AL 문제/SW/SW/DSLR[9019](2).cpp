#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX = 10000;
int dist[MAX + 1];

//char how[MAX + 1];
//int from[MAX + 1];

bool check[MAX + 1];
pair<int, char> start[MAX + 1];
// 배열을 pair로 하지 않고 두 배열로 나눔 훔.........

/*
	DSLR
	https://www.acmicpc.net/problem/9019
	0 <= 레지스터 < 10,000
	n: 네 자릿수 [d1][d2][d3][d4]
	D:  n의 2배
	if) 9999 < n ( 2n mod 10,000)
	S: n - 1
	if) n == 0 n = 9999
	L:  n = [d2][d3][d4][d1]
	R:  n = [d4][d1][d2][d3]
	*** n의 자릿 수로 0이 포함된 경우에 주의 해야한다.
	1000 L -> 0001 -> 1
	1000 R -> 0100 -> 100
	최소한의 명령어로 이루어진다 -> 연산은 1 -> BFS????
*/

void init() {
	memset(dist, 0, sizeof(dist));
	//memset(how, ' ', sizeof(how));
	//memset(from, 0, sizeof(from));
	memset(check, false, sizeof(check));
	memset(start, {}, sizeof(start));
}

void print(int n, int m) {
	if (n == m) return;
	print(n, start[m].first);
	cout << start[m].second;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		int A, B;
		cin >> A >> B;
		// dist[A] = 0;
		check[A] = true;
		queue<int> q;
		q.push(A);

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			// D 
			int next = (2 * now) % MAX;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				// dist[next] = dist[now] + 1;
				//how[next] = 'D';
				//from[next] = now;
				start[next] = make_pair(now, 'D');
			}

			// S
			next = now - 1;
			if (next == -1) next = 9999;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				// dist[next] = dist[now] + 1;
				//how[next] = 'S';
				//from[next] = now;
				start[next] = make_pair(now, 'S');
			}

			// L
			// 1000 -> 0001
			// 1234 / 1000 = 1
			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				// dist[next] = dist[now] + 1;
				//how[next] = 'L';
				//from[next] = now;
				start[next] = make_pair(now, 'L');
			}

			// R
			// 0001 -> 1000
			next = (now / 10) + (now % 10) * 1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				// dist[next] = dist[now] + 1;
				//how[next] = 'R';
				//from[next] = now;
				start[next] = make_pair(now, 'R');
			}
		}
		print(A, B);
		cout << '\n';
	}
	return 0;
}