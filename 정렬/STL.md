# sort() 함수의 기본 사용법

sort() 함수는 C++의 algorithm헤더에 포함되어 있습니다. 기본 사용법은 다음과 같습니다.

```C
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
  sort(a, a +10);
  for(int i= 0; i < 10; i++) {
    count << a[i] << ' ';
  }
}   
```
`sort()함수는 기본적으로 오름차순 정렬을 수헹`
`배열의 시작점 주소와 마지막 주소 기입`

단순히 sort(a, a + 10);를 해주는 것만으로도 총 10개의 원소가 있는 배열 a를 정렬해주는 것입니다. 

```C
#include <iosstream>
#include <algorithm>

using namespace std; 

bool compare(int a, int b) {
  return a < b;
}

int main (void) {
  int a [10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
  sort(a, a+10, compare);
  for(int i = 0; i < 10; i++) {
    cout <<a[i] << ' ';
  }
}
```

sort()함수가 좋은 이유는 정렬의 기준을 자신이 원하는 형태로 설정할 수 있다는 장점이다. 

위와 같이 `compare()`함수를 만들어서 `sort()의 세번째 인자 값으로 넣게 되면, 해당 함수의 반환 값에 맞게 정렬`

## 데이터를 묶어서 정렬
기본적으로 위와 같은 `단순 데이터 정렬 기법은 실무에서 사용하기에 적합하지 않습니다.` 

모든 데이터들이 객체로 정리되어 내부적으로 여러 개의 변수를 포함하고 있기 때문이다. 

`특정한 변수를 기준으로`정렬

```C
#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
  string name;
  int score;
  Student(string name, int score) {
    this -> name = name;
    this -> score = score;
  }
  
  // 정렬 기준으로 '점수가 작은 순서'
  bool operator <(Student &student) {
    return this -> score < studnet.score;
  }
};

bool compare(int a, int b) {
  return a > b; 
}

int main(void) {
  Student stduents[] = {
    Student("Steven", 90);
    Studnet("Chris", 93);
    Studnet("Camv", 97);
    Studnet("Chus", 87);
    Studnet("Deven", 92);
    Studnet("Gogh", 93);
  };
  sort(students, student + 5);
  for(int i = 0; i < 5; i++) {
    cout << students[i].name << ' ';
  }
} 
```

하지만 실제 대회에서 문제 하나를 풀기 위해 클래스를 정의하고 있는 것은 적절치 못한다.

쉽게 말해 `클래스를 이요한느 방식은 실무에 적합한 방식`

일반적으로 `프로그래밍 대회와 같이 빠른 개발이 필요할 때는 페어(Pair)라이브러리를 사용하는 것이 더 효율적`

```C
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (void) {
  vector<pair<int, string> > v;
  v.push_back(pair<int , string> (90, "Steven"));
  v.push_back(pair<int , string> (85, "Chris"));
  v.push_back(pair<int , string> (83, "Camv"));
  v.push_back(pair<int , string> (33, "Chus"));
  v.push_back(pair<int , string> (24, "Deven"));
  v.push_back(pair<int , string> (25, "Gogh"));
  
  sort(v.begin(), v.end());
  for( int i =0; i < v.size(); i++) {
    cout << v[i].second << ' ';
  }
  return 0;
}
```

위 소스코드는 __Vector 라이브러리와 Pair 라이브러리__ 이용해 시간에 배열과 클래스를 이용했던 방식을 대체

소스코드의 길이를 짧게 해주는 기법을 `숏코딩(Short Coding)`이라고 한다. 

`시간 복잡도가 동일하다면, 프로그래밍 대회에서는 소스코드가 짧을수록 남들보다 앞서있을 수 있다.`

# vcetor
마치 배열과 같이 작동하는데 원소를 선택적으로 삽입(Push)및 삭제(PoP)을 할 수 있다.

`단순한 배열을 보다 사용하기 쉽게 개편한 자료구조` 

# pair 
`한 쌍의 데이터를 처리 할 수 있도록 해주는 자료구조`

## Q. 학생을 나타낼 수 있는 정보가 이름, 성적, 생년월일일 때 학생을 성적 순서대로 나열하고자 한다.

다만 성적이 동리한 경우 나이가 더 어린 학생이 더 우선수위가 높다.

  - 이 경우 또한 벡터와 페어STL을 이용해서 몹시 짧은 코드로 작성이 가능하다.

```
<학생 명단>
  학생 1: Steven/90점/1996-12-20
  학생 2: Chris/90점/1986-12-12  
  학생 3: Camv/85점/1993-11-25
  학생 4: Chus/43점/1992-02-03
  학생 5: Gogh/66점/1944-11-11
```

정상적으로 위 학생들을 정렬하려면 먼저 성적에 따라서 정렬을 하고, 성적이 같은 경우 나이가 더 어린 사람이 먼저 출력되면 된다. 

예를 들어 Steven과 Chris 모두 90점이지만 더 나아가 Steven이 어리기 때문에 먼저 출련된다.
```C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool compare(pair<string, pair<int, int> > a,
             pair<string, pair<int , int> > b) {
      if(a.second.first == b.second.first) {
        return a.second.second > b.second.second;
      } else {
        return a.second.first > b.second.first;
      }
}

int main (void) {
  vecotr<pair <string, pair <int, int> > > v;
  v.push_back(pair<string, pair<int, int> >("Steven", make_pair(90, 19961220)));
  v.push_back(pair<string, pair<int, int> >("Chris", make_pair(90점, 19861212)));
  v.push_back(pair<string, pair<int, int> >("Camv", make_pair(85점, 19931125)));
  v.push_back(pair<string, pair<int, int> >("Chus", make_pair(43점, 19920203)));
  v.push_back(pair<string, pair<int, int> >("Gogh", make_pair(66점, 19441111)));
  
  sort(v.begin(), v.end(), compare);
  for(int i = 0; i < v.size(); , i++) {
    cout << v[i].first << ' ';
  }
  return 0;
}
```
### sort()함수는 이 정도로 세 개의 변수까지만 자유자재로 다룰 수 있는 정도면 실제 실무에서나 혹은 프로그래밍 대회에서나 정렬 때문에 골머리를 앓는 경우는 없을거라고 생각한다.
