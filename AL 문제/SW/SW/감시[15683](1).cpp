#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/*
감시
https://www.acmicpc.net/problem/15683

*/
#define MAX 9
int dx1[] = { 0, 0, 1, -1 };
int dy1[] = { 1, -1, 0 , 0 };
int dx2[4][2] = {
	{ -1, 1 },
{ 0, 0 },
{ -1, 1 },
{ 0, 0 }
};
int dy2[][2] = {
	{ 0, 0, },
{ -1, 1 },
{ 0, 0 },
{ -1, 1 }
};
int dx3[][2] = {
	{ 1, 0 },
{ 1 ,0 },
{ -1, 0 },
{ -1, 0 }
};
int dy3[][2] = {
	{ 0, -1 },
{ 0, 1 },
{ 0, 1 },
{ 0, -1 }
};
int dx4[][3] = {
	{ 1, -1, 0 },
{ 1, 0, 0 },
{ -1, 1, 0 },
{ -1, 0, 0 }
};
int dy4[][3] = {
	{ 0, 0, -1 },
{ 0, -1, 1 },
{ 0, 0, 1 },
{ 0, -1, 1 }
};
struct CCTV {
	int x, y;
	int number;
};
int arrCctv[MAX]; // cctv 정보 담기 vector에 담긴 cctv의 index와 같아야 한다.
int arrCctvDir[MAX]; // 방향을 담는다.
int arr[MAX][MAX]; // 전체 도면
int cp_arr[MAX][MAX];  // 뱡향의 횐전에 따라 다라질 도면
vector<CCTV> cctv; // cctv info
int totalEmpty = 0; // 사각지대 개수
int ans = 0; // 결과
int compare_ans = 0; // 방향에 따른 달라질 결과
int N, M; // 행 열 

void print() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << cp_arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void init() {
	cctv = vector<CCTV>();
	memset(arrCctv, 0, sizeof(arrCctv));
	memset(arrCctvDir, -1, sizeof(arrCctvDir));
	memset(arr, 0, sizeof(arr));
	totalEmpty = 0;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv.push_back({ i, j , arr[i][j] });
			}
			if (arr[i][j] == 0) {
				totalEmpty++;
			}
		}
	}
	ans = totalEmpty;
}
void go(int x, int y, int dx, int dy) {
	int nx = x + dx;
	int ny = y + dy;
	//	cout << nx << ' '<< ny;
	//	cout << '\n';
	while (true)
	{
		if (cp_arr[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (cp_arr[nx][ny] == 0) {
			compare_ans--;
			cp_arr[nx][ny] = -1;
		}
		nx += dx;
		ny += dy;
	}
}
int check() {
	compare_ans = totalEmpty;
	memset(cp_arr, 0, sizeof(cp_arr));
	memcpy(cp_arr, arr, sizeof(arr));
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].x;
		int y = cctv[i].y;
		int number = cctv[i].number;
		int dir = arrCctvDir[i];
		if (number == 1) {
			//		cout << 1<<'\n';
			go(x, y, dx1[dir], dy1[dir]);
		}
		else if (number == 2) {
			//		cout << 2<<'\n';
			int nx[2];
			int ny[2];
			nx[0] = dx2[dir][0];
			nx[1] = dx2[dir][1];
			ny[0] = dy2[dir][0];
			ny[1] = dy2[dir][1];
			go(x, y, nx[0], ny[0]);
			go(x, y, nx[1], ny[1]);
		}
		else if (number == 3) {
			//			cout << 3<<'\n';
			int nx[2];
			int ny[2];
			nx[0] = dx3[dir][0];
			nx[1] = dx3[dir][1];
			ny[0] = dy3[dir][0];
			ny[1] = dy3[dir][1];
			go(x, y, nx[0], ny[0]);
			go(x, y, nx[1], ny[1]);
		}
		else if (number == 4) {
			//			cout << 4<<'\n';
			int nx[3];
			int ny[3];
			nx[0] = dx4[dir][0];
			nx[1] = dx4[dir][1];
			nx[2] = dx4[dir][2];

			ny[0] = dy4[dir][0];
			ny[1] = dy4[dir][1];
			ny[2] = dy4[dir][2];
			go(x, y, nx[0], ny[0]);
			go(x, y, nx[1], ny[1]);
			go(x, y, nx[2], ny[2]);
		}
		else if (number == 5) {
			//		cout << 5<<'\n';
			go(x, y, 1, 0);
			go(x, y, -1, 0);
			go(x, y, 0, 1);
			go(x, y, 0, -1);
		}
	}
	//	print();
	return compare_ans;
}

void dfs(int cctv_size) {
	if (cctv.size() == cctv_size) {
		//		for (int i = 0; i < cctv_size; i++){
		//			cout << arrCctvDir[i] << ' ';
		//		}
		//		cout <<'\n';
		int compare_ans = check();
		ans = min(ans, compare_ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		arrCctvDir[cctv_size] = i;
		dfs(cctv_size + 1);
	}
}
int main() {
	init();
	input();
	dfs(0);
	cout << ans << '\n';
	return 0;
}

