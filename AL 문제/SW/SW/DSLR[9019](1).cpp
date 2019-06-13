#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
/*
	DSLR
	https://www.acmicpc.net/problem/9019
	(2)�� Ǯ�̺��� 2�� ���� 

	A���� B�� ��ȯ�ϱ� ���� �ּ��� ��ɾ� ������ ���ϴ� ������. 
	��ȯ ��ɾ�� �� 4������ ������, �ּ� ��ɾ� ������ ���ؾ� �ϹǷ�, BFS�� ����ϸ� �ȴ�. 
	��ɾ� ����Ʈ�� �������� �����ϸ� �ȴ�.

	�������͸� ��ȯ�ϴ� ��ɾ�� �� 4�����̴�.
	���� �������͸� X�� ���� ��, 
	��ɾ ���� ��ȯ�Ǵ� ���� �������͸� Y�� ����. 
	�� ��ɿ� ���� �������ʹ� �Ʒ��� ���� ��Ÿ�� �� �ִ�.
	��ɾ� D : Y = (X*2) % 10000
	��ɾ� S : Y = X-1 (��, Y < 0�� ���, Y = 9999)
	��ɾ� L : Y = (X%1000)*10 + X/1000
	��ɾ� R : Y = X/10 + (X%10)*1000
	
	�� 4���� ��ɾ ����, BFS�� ��������(����)�� Ž���ϰ�, 
	�̵� ��ο� ��ɾ ������ ����Ʈ�� �����Ѵ�.
	A���� ����ؼ� B�� �����ϸ�, B���� A�� �������� �ö󰡸鼭 ��ɾ �����Ѵ�. 
	�׸��� �̸� �������� ����Ѵ�.
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