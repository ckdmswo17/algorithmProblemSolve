// 백준 문제 : 연결 요소의 개수

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

    bool visited[N+1];
    for(int i=0;i<N+1;i++){
        visited[i] = false;
    }

    queue<int> qu;
    int answer = 0;
    for(int i=1;i<N+1;i++){ // BFS
        if(visited[i] == true){
            continue;
        }

        qu.push(i);
        visited[i] = true;
        // cout << i << " : "; 
        while(!qu.empty()){
            int e = qu.front();
            qu.pop();

            for(auto j:adj[e]){
                if(visited[j] == true){
                    continue;
                } 
                visited[j] = true;
                qu.push(j);
                // cout << j << " ";
            }
            // cout << "\n";
        }

        answer += 1;
    }
    cout << answer << "\n";
}