# 1. vector

동적배열이다. 임의의 위치에 있는 원소 접근과, 뒤에서 원소를 추가하는 연산은 O(1)(분할상환분석)을 보장한다.

```C
#include <iostream>
#include <vector>
using namespace std;
int main(){
	//int 자료형을 저장하는 동적배열
	vector<int> vec1;
	//double 자료형을 저장하는 동적배열
	vector<double> vec2;
	//사용자가 정의한 Node 구조체를 저장하는 동적배열
	vector<Node> vec3;
	//벡터의 초기 크기를 n으로 설정
	vector<int> vec4(n);
	//벡터의 초기 크기를 n으로 설정하고 1로 초기화
	vector<int> vec5(n, 1);
	//크기가 n*m인 2차원 벡터를 선언하고 0으로 초기화
	vector<vector<int> > vec6(n, vector<int>(m, 0));
	//벡터의 맨 뒤에 원소(5) 추가
	vec1.push_back(5);
	//벡터의 맨 뒤 원소 삭제
	vec1.pop_back();
	//벡터의 크기 출력
	printf("%d\n", vec1.size());
	//벡터의 크기를 n으로 재설정
	vec1.resize(n);
	//벡터의 모든 원소 삭제
	vec1.clear();
	//벡터의 첫 원소의 주소, 마지막 원소의 다음 주소 리턴
	vec1.begin();
	vec1.end();
	//[a, b) 주소 구간에 해당하는 원소 삭제
	vec1.erase(vec1.begin(), vec1.end());//모든 원소 삭제
	//vec7은 vec1의 2번째 원소부터 마지막 원소까지 복사하여 생성
	vector<int> vec7=vector<int>(vec1.begin()+2, vec1.end());
	return 0;
}
```
# 2. stack

스택 자료구조이다. 
```C
#include <iostream>
#include <stack>
using namespace std;
int main(){
	//int자료형을 저장하는 스택 생성
	stack<int> st;
	//원소(4) 삽입
	st.push(4);
	//맨 위 원소 팝
	st.pop();
	//맨 위 원소 값 출력
	printf("%d\n", st.top());
	//스택이 비어있다면 1 아니면 0
	printf("%d\n", st.empty());
	//스택에 저장되어 있는 원소의 수 출력
	printf("%d\n", st.size());
	return 0;
}
```
# 3. queue

큐 자료구조이다.
```C
#include <iostream>
#include <queue>
using namespace std;
int main(){
	//int자료형을 저장하는 큐 생성
	queue<int> q;
	//원소(4) 삽입
	q.push(4);
	//맨 위 원소 팝
	q.pop();
	//맨 위 원소 값 출력
	printf("%d\n", q.front());
	//큐가 비어있다면 1 아니면 0
	printf("%d\n", q.empty());
	//큐에 저장되어 있는 원소의 수 출력
	printf("%d\n", q.size());
	return 0;
}
```
# 4. deque

동적배열이다. 임의의 위치에 있는 원소 접근과, 앞과 뒤에서 원소를 추가하는 연산은 O(1)을 보장한다.
```C
#include <iostream>
#include <deque>
using namespace std;
int main(){
	//int 자료형을 저장하는 동적배열 생성
	deque<int> dq;
	//배열 맨 앞에 원소(5) 추가
	dq.push_front(5);
	//배열 맨 뒤에 원소(5) 추가
	dq.push_back(5);
	//배열 맨 앞의 원소 삭제
	dq.pop_front();
	//배열 맨 뒤의 원소 삭제
	dq.pop_back();
	//나머지는 vector와 동일하다.
	return 0;
}
```

# 5. set

균형잡힌 이진트리이다. 원소 삽입과 삭제, 탐색 등의 연산은 O(logn)을 보장한다.
```C
#include <iostream>
#include <set>
using namespace std;
int main(){
	//int 자료형을 저장하는 균형잡힌 이진트리 생성
	set<int> s;
	//원소(5) 삽입
	s.insert(5);
	//6값을 가지는 원소를 찾음 있다면 해당 원소의 주소값,  없다면 s.end()리턴
	if(s.find(6)!=s.end())
		printf("존재합니다.\n");
	else
		printf("없습니다.\n");
	//저장된 원소의 수를 리턴
	printf("%d\n", s.size());
	//모든 원소 삭제
	s.clear();
	//해당 주소의 원소 삭제
	//2번째 원소 삭제
	s.erase(++s.begin());
	return 0;
}
```

# 6. pair

2개의 데이터를 저장할 수 있는 변수이다. 비교 연산시 1순위 first 2순위 second로 판별한다.
```C
#include <iostream>
#include <utility>
using namespace std;
int main(){
	//int, int 자료형을 저장하는 변수 선언
	pair<int, int> p;
	//(4, 5)를 p에 저장
	p=make_pair(4, 5);
	//c++11부터 가능
	p={4, 5};
	return 0;
}
```

# 7. map

딕셔너리 자료구조이다. 원소 삽입과 삭제, 탐색 등의 연산은 O(logn)을 보장한다.
```C
#include <iostream>
#include <map>
using namespace std;
int main(){
	//int 자료형을 key로 int 자료형을 데이터로 저장하는 딕셔너리 자료구조 생성
	map<int, int> m;
	//(4, 5)원소 삽입
	m.insert(make_pair(4, 5));
	//또는
	m[5]=6;
	//key와 연관된 원소를 pair<키 자료형, 데이터 자료형> 형태로 리턴함
	printf("%d\n", m.find(4)->second);
	//key와 연관된 원소의 개수를 리턴함
	printf("%d\n", m.count(4));
	//저장된 원소의 수를 리턴함
	printf("%d\n", m.size());
	//해당 주소의 원소 삭제
	m.erase(++m.begin());
	//모든 원소 삭제
	m.clear();
	return 0;
}
```

# 8. algorithm

여러가지 알고리즘이 들어있는 헤더파일이다.
```C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b){
	return a>b;
}

int main(){

	int arr1[100000];
	vector<int> arr2[100000];
	int n=100000;

	//sort
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	sort(arr1, arr1+n);
	sort(arr2.begin(), arr2.end());
	//비교 함수도 만들어서 같이 넘겨줄 수 있다.
	sort(arr1, arr1+n, cmp);

	//stable_sort
	//사용법은 같다.
	stable_sort(arr1, arr1+n);

	//lower_bound
	//첫 원소의 주소와 마지막 원소의 다음 주소와 비교할 원소를 넘겨준다.
	//구간내의 원소들은 정렬되어 있어야한다.
	//리턴 값은 해당 원소의 주소값이다. 없다면 arr1+n을 리턴한다.
	//또는 arr2.end()를 리턴한다.
	int idx=lower_bound(arr1, arr1+n, 42)-arr1;
	printf("%d\n", idx);

	//upper_bound
	//사용법은 같다.
	vector<int>::iterator it=upper_bound(arr2.begin(), arr2.end(), 54);
	if(it!=arr2.end())
		printf("%d\n", *it);

	//max_element
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 최대값을 가지는 원소의 주소를 리턴한다.
	printf("%d\n", *max_element(arr1, arr1+n));

	//min_element
	//사용법은 같다.
	printf("%d\n", *min_element(arr2.begin(), arr2.end()));

	//unique
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 중복된 원소를 구간의 끝부분으로 밀어주고 마지막 원소의 다음 주소를 리턴한다.
	//구간내의 원소들은 정렬되어 있어야한다.
	//보통 erase와 함께 중복된 원소를 제거하는 방법으로 사용한다.
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

	//next_permutation
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 원소들의 다음 순열을 생성하고 true를 리턴한다.
	//다음 순열이 없다면 false를 리턴한다.
	//구간내의 원소들은 정렬되어 있어야한다.
	int arr[10];
	for(int i=0;i<10;i++)
		arr[i]=i;
	do{
		for(int i=0;i<10;i++)
			printf("%d ", arr[i]);
		printf("\n");
	}while(next_permutaion(arr, arr+10));

	return 0;
}
```
[출처: 박트리](https://baactree.tistory.com/29)
