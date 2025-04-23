// 백준 문제 : 파티

#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N,M,X;
	cin >> N >> M >> X;
	
	vector<pair<int,int>> adj[N+1];
	vector<pair<int,int>> revAdj[N+1]; // {비용, 정점}
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		adj[a].push_back({c,b});
		revAdj[b].push_back({c,a});
	}
	
	int toXD[N+1];
	int fromXD[N+1];
	toXD[X] = 0;
	fromXD[X] = 0;
	for(int i=1;i<N+1;i++){
		if(i == X) continue;
		toXD[i] = INT_MAX;
		fromXD[i] = INT_MAX;
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {거리, 정점}
	pq.push({0,X});
	//cout << "1-------------\n";
	while(!pq.empty()){ // revAdj 이용해서 toXD 채우기
		auto cur = pq.top(); pq.pop();
		if(toXD[cur.second] != cur.first) continue;
		
		for(auto nxt:revAdj[cur.second]){
			if(toXD[nxt.second] > toXD[cur.second]+nxt.first){
				toXD[nxt.second] = toXD[cur.second]+nxt.first;
				//cout << cur.first << " " << cur.second << " " << nxt.first << " " << nxt.second << " "<<toXD[nxt.second] <<"\n"; 
				//for(auto i:fromXD){
				//	cout << i << " ";
				//}
				//cout << "\n";
				pq.push({toXD[nxt.second],nxt.second});
			}
		}
		
	}
	
	pq = priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>(); // {거리, 정점}
	pq.push({0,X});
	//cout << "2-------------\n";
	while(!pq.empty()){ // adj 이용해서 fromXD 채우기
		auto cur = pq.top(); pq.pop();
		if(fromXD[cur.second] != cur.first) continue;
		
		for(auto nxt:adj[cur.second]){
			if(fromXD[nxt.second] > fromXD[cur.second]+nxt.first){
				fromXD[nxt.second] = fromXD[cur.second]+nxt.first;
				//cout << cur.first << " " << cur.second << " " << nxt.first << " " << nxt.second << " "<<fromXD[nxt.second] <<"\n"; 
				//for(auto i:fromXD){
				//	cout << i << " ";
				//}
				//cout << "\n";
				pq.push({fromXD[nxt.second],nxt.second});
			}
		}
		
		
	}
	
	int answer = 0;
	for(int i=1;i<N+1;i++){
		int sum = toXD[i] + fromXD[i];
		//cout << toXD[i] << " " << fromXD[i] << " " << sum << "\n";
		if(answer < sum) answer = sum;
	}
	cout << answer << "\n";
}

// N명 학생 집 -> x : 경로 뒤집고 최단 거리 계산
// x -> n명 학생 집 : 경로 그대로 최단 거리 계산 
// 두 벡터를 더해서 최대값 구하기