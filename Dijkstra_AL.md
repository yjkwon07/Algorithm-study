<h1>단일 시작점 최단 경로 문제</h1>
<h2>다익스트라(Daijkstra) 알고리즘</h2> <br>

	-다이나믹 프로그래밍을 활용한 대표적인 최단 경로(shortest Path)탐색 알고리즘
	-흔히 인공위성 GPS 소프트웨어 등에서 가장 많이 사용
	-시작 정점에서 거리가 최소인 정점부터 선택해 나가면서 최단 경로를 구하는 방식
	-다만 이 때 음의 간선을 포함 할 수 없다. 
	-현실 세계에서는 음의 간선이 존재 하지 않기 때문에 다익스트라는 현실 세계에 사용하기 매우 적합한 알고리즘 중 하나라고 할 수 있다.
	-다이나믹 프로그래밍(DP) 문제인 이유는 ‘최단 거리는 여러 개의 최단 거리로 이루어져 있기 때문이다.'
	-작은 문제가 큰 문제의 부분 집합에 속해 있다고 볼 수 있다. 
	-기본적으로 다익스트라는 하나의 최단 거리를 구할 때 그 이전까지 구했던 최단 거리 정보를 그대로 사용한다는 특징 
	-하나의 최단 거리를 구할 때 그 이전까지 구했던 최단 거리 정보를 그대로 사용한다는 특징이 있다. 
	-탐욕 기법을 사용한 알고리즘으로(정렬을 사용하기 때문에)최소 신장 트리를 구하는 프림 알고리즘과 유사
<br>
<h2>Flow</h2> 

	1.출발 노드를 설정
	2.출발 노드를 기준으로 각 노드의 최소 비용을 저장 
	3.방문하지 않은 노드중에서 가장 비용이 적은 노드를 선택
	4.해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신
	5.위 과정에서 3번 ~ 4번을 반복 
	* 컴퓨터 안에서 처리는 2차원 배열 형태 
	* 정점에서 같은 수를 가질 때 사용자가 우선순위를 정한다.

 *****************************************************************************************************
 <pre>
#include <stdio.h>

int number =6; 
int INF= 1000000000;

// 전체 그래프를 초기화 합니다. 
int a[6][6] ={
	{0, 2, 5, 1, INF, INF}, 
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
{INF, INF, 5, INF, 2, 0},
};
bool v[6]; // 방문한 노드
int d[6]; // 최단 거리 

// 가장 최소 거리를 가지는 정점을 반환합니다. 
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for(int i =0; I < number; i++){
		if(d[i] < min && !v[i]){
			min = d[i];
			index = i;
		}
	}
	return index;
}

// 다익스트라를 수행하는 함수입니다. 
void dijkstra(int start){
	for( int I =0; I < number; i++){
		d[i] = a[start][i];
	}
	v[start] = true;
	for( int j = 0;  j < 6; j++) { 
		if(!v[j]) {
			if( d[current] + a[current][j] < d[j]) {
				d[j] = d[current] + a[current][j];
			}
		}
	}
}

int main(void) { 
	dijkstra(0);
	for(int i =0; I < number; i++) {
	 	printf(“%d”, d[i]);
	}
}

</pre>

<h2> 시간 초과 문제 -> Heap </h2>
<pre>
#include <iostream>
#include <vector>
#include <queue>
/*
인접리스트 방식을 활용하여 시간복작보 O(N log N)으로 구현  
*/

using namespace std; 

int number = 6; 
int INF = 10000000;

vector<pair <int, int> > a[7]; // 간선 정보 
int d[7];// 최소 비용 

void dijkstra(int start) { 
	d[start] =0; 
	priority_queue<pair<int, int> > pq; // 힙구조 입니다.
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리하므로 큐를 사용합니다. 
	while(!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화 (-) 합니다. 
		int distance = -pq.top().second;
		pq.pop();
		//최단 거리가 아닌 경우 스킵합니다. 
		if( d[current] < distance) continue;
		for(int i=0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드 
			int next = a[current][i].first;
			// 선택된 노드 거쳐서 인접 노드로 가는 비용 
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체
			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));	
			}
		}
	}
}

int main(void) { 
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다. 
	for(int i = 1; i  <= number; i++){
		d[i] = INF;
	} 
	
	a[1].push_back(make_pair(2,2));
	a[1].push_back(make_pair(3,5));
	a[1].push_back(make_pair(4,1));
	
	a[2].push_back(make_pair(1,2));
	a[2].push_back(make_pair(3,3));
	a[2].push_back(make_pair(4,2));
	
	a[3].push_back(make_pair(1,5));
	a[3].push_back(make_pair(2,3));
	a[3].push_back(make_pair(4,3));
	a[3].push_back(make_pair(5,1));
	a[3].push_back(make_pair(6,5));
	
	a[4].push_back(make_pair(1,1));
	a[4].push_back(make_pair(2,2));
	a[4].push_back(make_pair(3,3));
	a[4].push_back(make_pair(5,1));
	
	a[5].push_back(make_pair(3,1));
	a[5].push_back(make_pair(4,1));
	a[5].push_back(make_pair(6,2));
	
	a[6].push_back(make_pair(3,5));
	a[6].push_back(make_pair(5,2));
	
	dijkstra(1);
	
	for( int i = 1; i <= number; i ++){
		printf("%d", d[i]);
	}
}
</pre>
