// 백준 문제 : 숨바꼭질3 (미완)

#include <iostream>
#include <queue>

using namespace std;

int dx[3] = {0,1,-1};
int N,K;
vector<int> dist(200002,0);
vector<bool> visited(200002,false);
queue<int> qu;

int bfs(){
    qu.push(N);
    visited[N] = true;
    while(!qu.empty()){
        int x = qu.front(); qu.pop();

        if(x == K){
            return dist[x];
        }
        for(int i=0;i<3;i++){
            int cx;
            if(i == 0){
                cx = x*2;
                while(cx < 200002){
                    if(visited[cx] == false){
                        dist[cx] = dist[x];
                        visited[cx] = true;
                        qu.push(cx);
                    }
                    cx = cx*2;
                }
                continue;
            } else {
                cx = x + dx[i];
            }

            
            if(cx >= 0 && cx < 200002 && visited[cx] == false){
                dist[cx] = dist[x]+1; 
                visited[cx] = true;
                qu.push(cx); 
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> K;

    cout << bfs() << endl;
}