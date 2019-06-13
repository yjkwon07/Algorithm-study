#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 200
using namespace std;

int R, C, N;
int Boom_Time[MAX][MAX];
char MAP[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input()
{
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 'O')
			{
				Boom_Time[i][j] = 3;
			}
		}
	}
}

void Install_Boom(int T)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (MAP[i][j] == 'O') continue;
			MAP[i][j] = 'O';
			Boom_Time[i][j] = T + 3;
		}
	}
}

void Delete_Boom(int T)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Boom_Time[i][j] == T)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (MAP[nx][ny] == '.') continue;

					MAP[nx][ny] = '.';
				}
				MAP[i][j] = '.';
				Boom_Time[i][j] = 0;
			}
		}
	}
}

void Print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << MAP[i][j];
		}
		cout << endl;
	}
}

void Solution()
{
	// input Time = 1;
	int Time = 2;
	for (int Time = 2; Time <= N; Time++) {
		//if (Time == N + 1) break;

		if (Time % 2 == 0)
		{
			Install_Boom(Time);
		}
		else
		{
			Delete_Boom(Time);
		}

		//Time++;
	}
	/*while (1)
	{
		if (Time == N + 1) break;

		if (Time % 2 == 0)
		{
			Install_Boom(Time);
		}
		else
		{
			Delete_Boom(Time);
		}

		Time++;

	}*/
	Print();
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}
