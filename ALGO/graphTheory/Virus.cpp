// 백준 문제 : 바이러스

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
    for(int i=0;i<M;i++){
        int e1,e2;
        cin >> e1 >> e2;

        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    queue<int> qu;
    bool visited[N+1];
    for(int i=1;i<N+1;i++){
        visited[i] = false;
    }
    int answer = -1;
    visited[1] = true;
    qu.push(1);
    while(!qu.empty()){
        int e = qu.front();
        qu.pop();
        // cout << e << "\n";
        answer += 1;

        for(auto i:adj[e]){
            if(visited[i] == true) continue;
            
            visited[i] = true;
            qu.push(i);
        }
    }

    cout << answer << "\n";
}