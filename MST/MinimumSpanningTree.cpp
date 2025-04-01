// 백준 문제 : 최소 스패닝 트리

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int V,E;
	cin >> V >> E;
	
	vector<pair<int,int>> adj[V+1]; // {비용, 정점}
	for(int i=0;i<E;i++){
		int A,B,C;
		cin >> A >> B >> C;
		
		adj[A].push_back({C,B});
		adj[B].push_back({C,A});
	}
	
	bool checked[V+1];
	for(int i=1;i<V+1;i++){
		checked[i] = false;
	}
	
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq; // {비용, 정점1, 정점2}
	int cnt = 0; // 선택된 간선 개수
	
	// 프림 알고리즘
	checked[1] = true; // 1 방문 체크
	int sum = 0;
	for(auto i:adj[1]){
		pq.push(make_tuple(i.first,1,i.second)); // 1과 연결된 간선 pq에 넣기
	}
	while(cnt < V-1){ // cnt가 트리의 간선 수 미만일때동안 반복
		int a,b,c;
		tie(a,b,c) = pq.top(); pq.pop(); // 우선순위 큐에서 간선 뽑기
		if(checked[c] == true) continue;
		checked[c] = true; // 해당 정점 2 방문 체크, cnt+1, sum에 해당 간선 비용 더하기
		cnt += 1;
		sum += a;
		for(auto i:adj[c]){ // 뽑은 간선의 정점 2와 인접한 간선 chk 후 push
			if(checked[i.second] == true) continue;
			pq.push(make_tuple(i.first,c,i.second));
		}
	}
	cout << sum << "\n";  
}