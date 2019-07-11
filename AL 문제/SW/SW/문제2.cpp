#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
각 배열의 원소는 숫자 1 ~ 13

*/
#define MAX 7
int arrA[MAX];
int arrB[MAX];
struct POKER {
	int key, count;
};
bool compare(POKER a, POKER b) {
	return a.count < b.count;
}
vector<POKER> pairs(vector<int> param) {
	vector<POKER> answer;
	map<int, int> mp;
	vector<int> key;
	int len = param.size();
	for (int i = 0; i < len; i++) {
		if (!mp[param[i]]) {
			key.push_back(param[i]);
		}
		mp[param[i]]++;
	}
	bool ok = false;
	for (int i = 0; i < key.size(); i++) {
		if (mp[key[i]] > 1) {
			answer.push_back({ key[i] , mp[key[i]] });
			ok = true;
		}
	}
	if (!ok) {
		answer.push_back({-1 ,-1 });
		return answer;
	}
	else return answer;
}

int solution(vector<int> arr1, vector<int> arr2) {
	int answer = 0;
	vector<POKER> op1 = pairs(arr1);
	vector<POKER> op2 = pairs(arr2);
	sort(op1.begin(), op1.end(), compare);
	sort(op2.begin(), op2.end(), compare);
	int op_arr1 = op1[0].count;
	int op_arr2 = op2[0].count;
	if (op_arr1 == -1) op_arr1 = 0;
	else if (op_arr1 >= 5) op_arr1 = 4;
	if (op_arr2 == -1) op_arr2 = 0;
	else if (op_arr2 >= 5) op_arr2 = 4;
	if (op_arr1 == 0 && op_arr2 == 0) return 0;
	else if (op_arr1 == op_arr2) {
		if (op1[0].key > op2[0].key) {
			return 1;
		}
		else if (op1[0].key < op2[0].key) return 2;
		else return 0;
	}
	else if (op_arr1 > op_arr2) return 1;
	else if (op_arr1 > op_arr2) {
		return 2;
	}
}

int main() {
	vector<int>param;
	vector<int>param2;
	for (int i = 0; i < 7; i++) {
		int in;
		cin >> in;
		param.push_back(in);
	}
	for (int i = 0; i < 7; i++) {
		int in;
		cin >> in;
		param2.push_back(in);
	}
	int ans = solution(param, param2);
	cout << ans;
	cout << '\n';
	return 0;
}