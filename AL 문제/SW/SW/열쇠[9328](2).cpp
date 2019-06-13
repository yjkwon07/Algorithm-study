#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dx[] = { 0 , 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char a[111][111];
bool check[111][111];
bool key[111];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		memset(a, 0, sizeof(a));
		for (int i = 2; i < n + 2; i++) {
			cin >> a[i] + 2;
		}

		n += 4;
		m += 4;

		for (int i = 0; i < n; i++) {
			a[i][0] = '*';
			a[i][1] = '.';
			a[i][m - 2] = '.';
			a[i][m - 1] = '*';
		}

		for (int j = 1; j <= m - 2; j++) {
			a[0][j] = '*';
			a[1][j] = '.';
			a[n - 2][j] = '.';
			a[n - 1][j] = '*';
		}
		
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++)
		//		cout << a[i][j];
		//	cout << '\n';
		//}

		memset(key, false, sizeof(key));
		char temp[111];
		cin >> temp;
		int len = strlen(temp);
		if (temp[0] != '0') {
			for (int i = 0; i < len; i++) {
				key[temp[i] - 'a'] = true;
			}
		}
		memset(check, false, sizeof(check));

		queue<pair<int, int>> q; // 움직임
		queue<pair<int, int>> sec[26]; // 보안요원 
		q.push(make_pair(1, 1)); // 1,1에서 시작하자 
		check[1][1] = true; // 방문 했다.
		int ans = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (check[nx][ny]) continue;

				char w = a[nx][ny];
				if (w == '*') continue;
				check[nx][ny] = true;

				if (w == '.')
					q.push(make_pair(nx, ny));
				else if (w == '$') {
					ans += 1;
					q.push(make_pair(nx, ny));
				}
				else if ('A' <= w && w <= 'Z') {
					if (key[w - 'A']) {
						q.push(make_pair(nx, ny));
					}
					else
						sec[w - 'A'].push(make_pair(nx, ny));
				}
				else if ('a' <= w && w <= 'z') {
					if (!key[w - 'a']) {
						key[w - 'a'] = true;
						q.push(make_pair(nx, ny));
						while (!sec[w - 'a'].empty()) {
							q.push(sec[w - 'a'].front());
							sec[w - 'a'].pop();
						}
					}
					else
						q.push(make_pair(nx, ny));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}