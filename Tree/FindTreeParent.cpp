// 백준 문제 : 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> adj[N+1];
    for(int i=1;i<N;i++){
        int e1,e2;
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1); 
    }

    int p[N+1];
    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        int cur = qu.front();
        qu.pop();
        
        for(auto nxt:adj[cur]){
            if(p[cur] == nxt) continue;
            qu.push(nxt);
            p[nxt] = cur;
        }
    }

    for(int i=2;i<N+1;i++){
        cout << p[i] << "\n";
    }

}