// 백준 문제 : 트리

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
bool visited[501];
bool isTree;

void dfs(int cur, int prev){

    for(auto i:adj[cur]){
        if(i == prev) continue;
        if(visited[i] == true){
            isTree = false;
            continue;
        }
        visited[i] = true;
        dfs(i,cur);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;
    while(true){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i=1;i<n+1;i++){
            adj[i].clear();
            visited[i] = false;
        }

        for(int i=0;i<m;i++){
            int e1,e2;
            cin >> e1 >> e2;

            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
        }

        int trees = 0;
        for(int i=1;i<n+1;i++){
            isTree = true;
            visited[i] = true;
            dfs(i,-1);
            if(isTree == true) trees += 1;
        }

        cout << "Case " << cases << ": ";  
        if(trees > 1){
            cout << "A forest of " << trees << " trees.\n";
        } else if(trees == 1){
            cout << "There is one tree.\n";
        } else {
            cout << "No trees.\n";
        }
        cases += 1;
    }
}