#include <string>
#include <vector>
using namespace std;
/*
	보물지도
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);

	for (int i = 0; i < n; i++) {
		int x = arr1[i] | arr2[i];
		answer[i].assign(" ", n);
		for (int j = n - 1; j >= 0; j--) {
			if (x % 2 == 0) answer[i][j] = ' ';
			else answer[i][j] = '#';
			x /= 2;
		}
	}

	return answer;
}