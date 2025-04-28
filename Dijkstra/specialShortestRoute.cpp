// 백준 문제 : 특정한 최단 경로

#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N,E;
	cin >> N >> E;
	
	vector<pair<int,int>> adj[N+1]; // {비용, 정점}
	for(int i=0;i<E;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	
	int v1,v2;
	cin >> v1 >> v2;
	
	// v1에서 시작하는 최단거리 배열 채우기
	int d[N+1];
	d[v1] = 0;
	for(int i=1;i<N+1;i++){
		if(i != v1) d[i] = INT_MAX; 
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {거리, 정점}
	pq.push({0,v1});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.second] != cur.first) continue;
		
		for(auto nxt:adj[cur.second]){
			if(d[nxt.second] > d[cur.second]+nxt.first){
				if(d[cur.second] != INT_MAX){
					d[nxt.second] = d[cur.second]+nxt.first;
					pq.push({d[nxt.second],nxt.second});
				}
			}
		}
	}
	vector<int> fromV1SpeDist;
	fromV1SpeDist.push_back(d[1]);
	fromV1SpeDist.push_back(d[v2]);
	fromV1SpeDist.push_back(d[N]);
	// v1->1 , v1->v2, v1->N 저장
	
	// 이전 배열 초기화 및 v2에서 시작하는 거리 배열 채우기
	d[v2] = 0;
	for(int i=1;i<N+1;i++){
		if(i != v2) d[i] = INT_MAX; 
	}
	pq.push({0,v2});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.second] != cur.first) continue;
		
		for(auto nxt:adj[cur.second]){
			if(d[nxt.second] > d[cur.second]+nxt.first){
				if(d[cur.second] != INT_MAX){
					d[nxt.second] = d[cur.second]+nxt.first;
					pq.push({d[nxt.second],nxt.second});
				}
			}
		}
	}
	vector<int> fromV2SpeDist;
	fromV2SpeDist.push_back(d[1]);
	fromV2SpeDist.push_back(d[v1]);
	fromV2SpeDist.push_back(d[N]);
		
	vector<int> dst;
	dst.push_back(fromV1SpeDist[0] + fromV1SpeDist[1] * 2 + fromV1SpeDist[2]);
	dst.push_back(fromV1SpeDist[0] + fromV1SpeDist[1] + fromV2SpeDist[2]);
	dst.push_back(fromV2SpeDist[0] + fromV1SpeDist[1] * 2 + fromV2SpeDist[2]);
	dst.push_back(fromV2SpeDist[0] + fromV1SpeDist[1] + fromV1SpeDist[2]);
	
	//for(int i=0;i<3;i++){
	//	cout << fromV1SpeDist[i] << " " << fromV2SpeDist[i] << "\n";
	//}
	
	int answer = *min_element(dst.begin(),dst.end());
	if(answer == INT_MAX || answer < 0 || E == 0){
		cout << -1 << "\n";
	} else {	
		cout << answer << "\n";
	}
	
}

// ex) 2, 3를 지나야한다면
// 1->2 , 2->3, 3->4
// 1->3 , 3->2, 2->4
// 각 자리 최단거리끼리 누가 더 작은지 비교
// 1 -> v1 -> v2 -> N인지 확인
// 아니고 중간이 v1 -> v2 -> v1라면 middleValue * 2
// 작은 거리의 합이 최종 답
