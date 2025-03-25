// 백준 문제 : 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int dx[3] = {1,-1,0};
int N,K;
vector<int> dist(200002,0);
queue<int> qu;

int bfs(){
    qu.push(N);
    while(!qu.empty()){
        int x = qu.front(); qu.pop();

        if(x == K){
            return dist[x];
        }
        for(int i=0;i<3;i++){
            int cx;
            if(i == 2){
                cx = x*2;
            } else {
                cx = x + dx[i];
            }

            if(cx >= 0 && cx < 200002 && dist[cx] == 0){
                dist[cx] = dist[x] + 1;
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