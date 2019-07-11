#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*

자연수가 들어 있는 배열 arr

*/
#define MAX 100
int arr[MAX];
vector<int> solution(vector<int> param) {
	vector<int> answer;
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
			answer.push_back(mp[key[i]]);
			ok = true;
		}
	}
	if (!ok) {
		answer.push_back(-1);
		return answer;
	}
	else return answer;
}
int main() {

	vector<int>param;
	for (int i = 0; i < 5; i++) {
		int in;
		cin >> in;
		param.push_back(in);
	}
	param = solution(param);
	for (int i = 0; i < param.size(); i++) {
		cout << param[i] << ' ';
	}
	cout << '\n';
}