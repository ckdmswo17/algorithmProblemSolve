// 백준 문제 : 문제집

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
    int deg[N+1];
    for(int i=1;i<N+1;i++){
        deg[i] = 0;
    }
    for(int i=0;i<M;i++){
        int e1,e2;
        cin >> e1 >> e2;

        adj[e1].push_back(e2);
        deg[e2] += 1;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<N+1;i++){
        if(deg[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int e = pq.top(); pq.pop();
        cout << e << " ";
        
        for(auto i:adj[e]){
            deg[i] -= 1;
            if(deg[i] == 0){
                pq.push(i);
            }
        }
    }
    cout << "\n";
}