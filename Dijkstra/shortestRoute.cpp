// 백준 문제 : 최단 경로

#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V,E;
    cin >> V >> E;

    int st;
    cin >> st;

    vector<pair<int,int>> adj[V+1]; // {비용, 정점}
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    int d[V+1];
    d[st] = 0;
    for(int i=1;i<V+1;i++){
        if(i != st) d[i] = INT_MAX;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {시작 노드부터의 거리, 정점}
    pq.push({0,st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue; // 이미 최단거리를 기록한 정점인지 검사
        

        for(auto nxt:adj[cur.second]){
            if(d[nxt.second] >= d[cur.second]+nxt.first) {
                d[nxt.second] = d[cur.second]+nxt.first;
                pq.push({d[nxt.second],nxt.second});
            }
        }
    }

    for(int i=1;i<V+1;i++){
        if(d[i] == INT_MAX) cout << "INF\n";
        else cout << d[i] << "\n";
    }

}