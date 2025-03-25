// 백준 문제 : 결혼식

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool visited[n+1];
    for(int i=1;i<n+1;i++){
        visited[i] = false;
    }
    
    queue<pair<int,int>> qu; // {노드번호, 노드 1과의 거리}
    int answer = 0;
    int count = 0;
    visited[1] = true;
    qu.push({1,0});
    while(!qu.empty()){
        pair e = qu.front();
        if(e.second >= 2){
            break;
        }
        qu.pop();

        for(auto i:adj[e.first]){
            if(visited[i] == true) continue;
            visited[i] = true;
            qu.push({i,e.second+1});
            answer += 1;
        }
    }

    cout << answer << "\n";
}