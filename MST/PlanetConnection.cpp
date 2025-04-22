// 백준 문제 : 상근이의 여행

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
	
	vector<pair<int,int>> adj[N+1]; // {비용, 정점}
	for(int i=1;i<N+1;i++){
		for(int j=1;j<N+1;j++){
			int e;
			cin >> e;
			if(e == 0) continue;
			adj[i].push_back({e,j});
			adj[j].push_back({e,i});
		}
	}
	
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq; // {비용, 정점1, 정점2}
	bool check[N+1] = {false};
	check[1] = true;
	for(auto i: adj[1]){
		pq.push(make_tuple(i.first,1,i.second));
	}
	
	int cnt = 0;
	long sum = 0;
	while(cnt < N-1){
		int a,b,c;
		tie(a,b,c) = pq.top(); pq.pop();
		if(check[c] == true) continue;
		check[c] = true;
		cnt += 1;
		sum += a;
		for(auto i:adj[c]){
			if(check[i.second] == true) continue;
			pq.push(make_tuple(i.first,c,i.second));
		}
	}
	
	cout << sum << "\n";
	
}