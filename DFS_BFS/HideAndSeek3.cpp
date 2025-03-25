// 백준 문제 : 숨바꼭질3

#include <iostream>
#include <queue>

using namespace std;

int dx[3] = {0,-1,1};
int N,K;
vector<int> dist(200002,0);
vector<bool> visited(200002,false);
queue<int> qu;

int bfs(){
    if(N >= K){
        return N-K;
    }
    qu.push(N);
    visited[N] = true;
    while(!qu.empty()){
        int x = qu.front(); qu.pop();
        // cout << "큐 반복 : " << x << endl;

        if(visited[K] == true){
            return dist[K];
        }
        for(int i=0;i<3;i++){
            int cx;
            if(i == 0){
                cx = x*2;
                while(cx < K + (K-N)){
                    if(visited[cx] == false){
                        // cout << cx << endl;
                        dist[cx] = dist[x];
                        visited[cx] = true;
                        qu.push(cx);
                        cx *= 2;
                    } else {
                        break;
                    }
                    
                }
                continue;
            } else {
                cx = x + dx[i];
            }

            
            if(cx >= 0 && cx < K+(K-N) && visited[cx] == false){
                dist[cx] = dist[x]+1; 
                visited[cx] = true;
                qu.push(cx);
                // cout << cx << endl;
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> K;

    cout << bfs() << endl;
}