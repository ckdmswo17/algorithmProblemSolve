// 백준 문제 : 노드사이의 거리

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin >> N >> M;
	
	int dist[N+1][N+1];
	for(int i=1;i<N+1;i++){
		for(int j=1;j<N+1;j++){
			if(i == j){
				dist[i][j] = 0;
			} else {
				dist[i][j] = INT_MAX;
			}
		}
	}
	
	for(int i=0;i<N-1;i++){
		int e1,e2,e3;
		cin >> e1 >> e2 >> e3;
		dist[e1][e2] = e3;
		dist[e2][e1] = e3;
	}
	
	for(int k=1;k<N+1;k++){
		for(int i=1;i<N+1;i++){
			for(int j=1;j<N+1;j++){
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
					continue;
				}
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	vector<int> answer;
	for(int i=0;i<M;i++){
		int e1,e2;
		cin >> e1 >> e2;
		answer.push_back(dist[e1][e2]);
	}
	
	for(auto i:answer){
		cout << i << "\n";
	}
}