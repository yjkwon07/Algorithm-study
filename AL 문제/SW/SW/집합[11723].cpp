#include <cstdio>
#include <cstring>
using namespace std;
/*
	집합
	https://www.acmicpc.net/problem/11723

	물론 배열을 사용하는 것이 더욱 편리하지만, 
	비트마스크를 사용하는 이유는
	집합을 배열의 인덱스로 표현할 수 있기 때문이다.
	상태 다이나믹을 할 때 자주 사용하게 된다.

	비트마스크
	비트(bit) 연산을 사용해서 부분 집합을 표현할 수 있다.
	A << B는 A * 2^B와 같다.
	A >> B는 A / 2^B와 같다.
	(A + B) / 2는 ( A + B) >> 1로 쓸 수 있다.

	정수로 집합을 나타낼 수 있다.
	{1, 3, 4, 5, 9 } = 0 1 0 0 0 1 1 1 0 1 0 = 570

	보통 0부터 N - 1까지 정수로 이루어진 집합을 나타낼 때 사용한다.
	1부터 N까지 정수로 이루어진 집합을 사용하는 건 공간이 2배 더 필요하다.
	또, 각종 연산을 조금 변형해서 사용해야 한다.
	따라서, 0부터 N - 1까지로 변형해서 사용하는 것이 더 좋다.

	전체 집합
	( 1 <<  N) - 1
	공집합
	0

	현재 집합이 S일 때
	i를 추가
	S | ( 1 <<  i)
	i를 검사
	S & ( 1 <<  i)
	i를 제거
	S & ~(1 << i )
	i를 토글(0을 1로, 1을 0으로)
	S ^ ( 1 << i)
*/
char b[111];
int main() {
	/*
		x--를 안하고 싶으면 
		n = 21로 변경하면 된다. 
		n 의 전체 집합 20이면 
		0 ~ 19 
		why? -> (1 << n ) -1
		
		1<<20은 이진수로 1 뒤에 20개의 0이 있는 정수이다
		여기서 1을 빼면 20개의 비트가 모두 켜진 수를 얻는다
		참고 : http://mrl.kr/bitmask/

	*/
	int n = 20;
	int m;
	scanf("%d", &m);
	int s = 0;
	int x;

	while (m--) {
		scanf("%s", b);

		if (!strcmp(b, "add")) {
			scanf("%d", &x); x--;
			s = (s | (1 << x));
		}
		else if (!strcmp(b, "remove")) {
			scanf("%d", &x); x--;
			s = (s & ~(1 << x));
		}
		else if (!strcmp(b, "check")) {
			scanf("%d", &x); x--;
			int res = (s & (1 << x));
			if (res) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
		else if (!strcmp(b, "toggle")) {
			scanf("%d", &x); x--;
			s = (s ^ (1 << x));
		}
		else if (!strcmp(b, "all")) {
			s = (1 << n) - 1;
		}
		else if (!strcmp(b, "empty")) {
			s = 0;
		}
	}
	return 0;
}