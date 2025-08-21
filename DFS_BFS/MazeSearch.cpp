// 백준 문제 : 미로 탐색
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int dy[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};

#define Y first
#define X second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    // 미로 2차원 배열
    // visited 2차원 배열
    // 최단거리 2차원 배열
    // queue <x,y>

    int maze[N][M];
    for(int i=0;i<N;i++){
        string numStr;
        cin >> numStr;
        for(int j=0;j<M;j++){
            maze[i][j] = stoi(numStr.substr(j,1));
        }
    }

    bool visited[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j] = false;
        }
    }
    int minDist[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            minDist[i][j] = 0;
        }
    }

    queue<pair<int,int> > qpi;
    qpi.push({0,0});
    visited[0][0] = true;
    minDist[0][0] = 1;
    while(visited[N-1][M-1] == false && !qpi.empty()){
        pair<int,int> cur = qpi.front();
        qpi.pop();

        for(int i=0;i<4;i++){
            int nxtY = cur.Y + dy[i]; 
            int nxtX = cur.X + dx[i];
            if(0 <= nxtY && nxtY < N && 0 <= nxtX && nxtX < M){
                if(maze[nxtY][nxtX] == 1 && visited[nxtY][nxtX] == false){
                    qpi.push({nxtY,nxtX});
                    visited[nxtY][nxtX] = true;
                    minDist[nxtY][nxtX] = minDist[cur.Y][cur.X] + 1; // 처음 방문할때 거리가 곧 그 지점의 최단거리임 
                }
            }
        }
    }

    cout << minDist[N-1][M-1] << "\n";
}