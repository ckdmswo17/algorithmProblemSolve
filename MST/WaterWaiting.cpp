// 백준 문제 : 물대기

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	int cost[N+1];
	int min = 100001;
	int minIndex;
	
	for(int i=1;i<N+1;i++){
		cin >> cost[i];
		if(min > cost[i]) {
			min = cost[i];
			minIndex = i;
		}
	}
	
	vector<pair<int,int>> adj[N+1]; // {비용, 정점}
	for(int i=1;i<N+1;i++){
		for(int j=1;j<N+1;j++){
			int e;
			cin >> e;
			if(i == j) continue; 
			adj[i].push_back({e,j});
		}
	}
	
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq; // {비용, 정점1, 정점2}
	bool chk[N+1];
	for(int i=1;i<N+1;i++){
		chk[i] = false;
	}
	
	chk[minIndex] = true;// 어차피 모든 정점을 방문하므로 논 중에서 우물 파는 비용이 제일 적은 논을 선택해서 시작
	int cnt = 1;
	int sum = cost[minIndex];
	for(auto i:adj[minIndex]){
		pq.push(make_tuple(i.first,minIndex,i.second));
	}
	for(int i=1;i<N+1;i++){
		if(i == minIndex) continue;
		pq.push(make_tuple(cost[i],i,i));
	}
	// 하지만 무조건 우물을 하나만 파지는 X, 우물 파는 비용이 끌어오는 비용보다 적을 수도 있기 때문
	// 우물 파는 비용을 자신을 시작으로 하고 자신을 도착지로 하는 간선으로 맨처음 초기화때 우선순위 큐에 넣으면 해결 가능
	
	// 프림 알고리즘
	while(cnt < N){ // cnt가 정점 수 미만일때동안 반복
		int a,b,c;
		tie(a,b,c) = pq.top(); pq.pop(); // 우선순위 큐에서 간선 뽑기
		// cout << a << " " << b << " " << c << "\n";
		if(chk[c] == true) continue;
		chk[c] = true; // 해당 정점 2 방문 체크, cnt+1, sum에 해당 간선 비용 더하기
		cnt += 1; //
		sum += a;
		for(auto i:adj[c]){ // 뽑은 간선의 정점 2와 인접한 간선 chk 후 push
			if(chk[i.second] == true) continue;
			pq.push(make_tuple(i.first,c,i.second));
		}
	}
	cout << sum << "\n";
	
}