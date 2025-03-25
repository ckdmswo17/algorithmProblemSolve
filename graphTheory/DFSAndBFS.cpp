// 백준 문제 : DFS와 BFS

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,V;
    cin >> N >> M >> V;

    set<int> adj[N+1];
    for(int i=0;i<M;i++){
        int e1,e2;
        cin >> e1 >> e2;
        adj[e1].insert(e2);
        adj[e2].insert(e1);
    }

    bool visited[N+1];
    for(int i=1;i<N+1;i++){
        visited[i] = false;
    }
    vector<int> dfsAnswer;
    vector<int> bfsAnswer;

    stack<int> sck;
    sck.push(V);
    while(!sck.empty()){ // 비재귀 DFS
        int e = sck.top();
        sck.pop();
        if(visited[e] == true) continue;
        visited[e] = true;

        dfsAnswer.push_back(e);
        for(auto i=adj[e].rbegin();i != adj[e].rend();i++){
            if(visited[*i] == true) continue;
            // cout << *i << " ";
            sck.push(*i);
        }
        // cout << "\n";
    }

    for(int i=1;i<N+1;i++){
        visited[i] = false;
    }

    queue<int> qu;
    visited[V] = true;
    qu.push(V);
    while(!qu.empty()){ // BFS
        int e = qu.front();
        // cout << e << "\n";
        qu.pop();
        bfsAnswer.push_back(e);

        for(auto i:adj[e]){
            if(visited[i] == true){
                continue;
            }
            visited[i] = true;
            qu.push(i);
        }
    }

    for(auto i:dfsAnswer){
        cout << i << " ";
    }
    cout << "\n";
    for(auto i:bfsAnswer){
        cout << i << " ";
    }
    cout << "\n";
}
