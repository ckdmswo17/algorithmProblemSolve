// 백준 문제 : 최소비용 구하기 2

#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	vector<pair<int,int>> adj[n+1]; // {비용, 정점}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		adj[a].push_back({c,b});
	}
	
	int st,end;
	cin >> st >> end;
	
	int d[n+1];
	int beforeNode[n+1];
	d[st] = 0;
	beforeNode[st] = 0; 
	for(int i=1;i<n+1;i++){
		if(i != st) d[i] = 0x3f3f3f3f;
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {거리, 정점}
	pq.push({0,st});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(cur.first != d[cur.second]) continue;
		
		for(auto nxt:adj[cur.second]){
			if(d[nxt.second] > d[cur.second] + nxt.first) { // 괄호를 넣으면 불필요한 삽입이 일어나서 메모리 초과
				d[nxt.second] = d[cur.second] + nxt.first;
				beforeNode[nxt.second] = cur.second;
				// cout << cur.first << " " << cur.second << " " << nxt.first << " " << nxt.second << "\n"; 
				pq.push({d[nxt.second],nxt.second});
			}
		}
	}
	
	
	cout << d[end] << "\n";
	vector<int> citys;
	int cur = end;
	while(cur != st){
		citys.push_back(cur);
		cur = beforeNode[cur];
	}
	citys.push_back(cur);
	reverse(citys.begin(),citys.end());
	cout << citys.size() << "\n";
	for(auto c:citys){
		cout << c << " "; 
	}
	cout << "\n";
}