#include <iostream>
#include <string>

using namespace std;

string a;

int main(void) {
	cin >> a;
	
	int result = 0;
	string temp = "";
	bool minus = false;
	
	for(int i = 0; i <= a.size(); i++) {
		if(a[i] == '+' || a[i] == '-' || a[i] == '\0'){
			if(minus == true)
				result += -stoi(temp);
			else 
				result += stoi(temp);
			temp = "";
			if(a[i] == '-' ) 
				minus = true;
			continue;
		}
		temp += a[i];
	}
	printf("%d", result);
	return 0;
}
