// 백준 문제 : 상근이의 여행

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	vector<int> answer;
	for(int i=0;i<T;i++){
		int N,M;
		cin >> N >> M;
		
		vector<int> adj[N+1];
		for(int j=0;j<M;j++){
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		bool checked[N+1] = {false};
		queue<pair<int,int>> qu; // {정점1, 정점2} 
		int cnt = 0;
		int nodes = 1;
		checked[1] = true;
		for(auto j:adj[1]){
			qu.push({1,j});
		}
		while(nodes < N){
			int e1,e2;
			tie(e1,e2) = qu.front(); qu.pop();
			if(checked[e2] == true) continue;
			checked[e2] = true;
			nodes += 1;
			cnt += 1;
			for(auto j:adj[e2]){
				if(checked[j] == true) continue;
				qu.push({e2,j});
			}
		}
		answer.push_back(cnt);
	}
	
	for(auto i:answer){
		cout << i << "\n";
	}
}