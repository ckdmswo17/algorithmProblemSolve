// 백준 문제 : 음악프로그램

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin >> N >> M;
	
	int deg[N+1];
	for(int i=1;i<N+1;i++){
		deg[i] = 0;
	}
	
	vector<int> adj[N+1];
	for(int i=0;i<M;i++){
		int num_singer;
		cin >> num_singer;
		
		vector<int> singer;
		for(int j=0;j<num_singer;j++){
			int e;
			cin >> e;
			singer.push_back(e);
		}
		for(int j=0;j<num_singer-1;j++){
			adj[singer[j]].push_back(singer[j+1]);
			deg[singer[j+1]] += 1;
		}
	}
	
	queue<int> qu;
	vector<int> answer;
	for(int i=1;i<N+1;i++){
		if(deg[i] == 0) qu.push(i);
	}
	while(!qu.empty()){
		int e = qu.front(); qu.pop();
		answer.push_back(e);
		
		for(auto i:adj[e]){
			deg[i] -= 1;
			if(deg[i] == 0) qu.push(i);
		}
	}
	
	if(answer.size() == N){
		for(auto i:answer){
			cout << i << "\n";
		}
	} else {
		cout << 0 << "\n";
	}
}