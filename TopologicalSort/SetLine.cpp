// 백준 문제 : 줄 세우기

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin >> N >> M;
	
	vector<int> adj[N+1];
	vector<int> deg(N+1,0);
	for(int i=0;i<M;i++){
		int A,B;
		cin >> A >> B;

		adj[A].push_back(B);
		deg[B] += 1;
	}
	
	queue<int> qu;
	for(int i=1;i<N+1;i++){
		if(deg[i] == 0) qu.push(i);
	}
	while(!qu.empty()){
		int e = qu.front(); qu.pop();
		cout << e << " ";
		for(auto i:adj[e]){
			deg[i] -= 1;
			if(deg[i] == 0) qu.push(i);
		}
	}
	cout << "\n";
	
}