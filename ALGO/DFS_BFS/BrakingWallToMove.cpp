// 백준 문제 : 벽 부수고 이동하기
#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = {1,0,-1,0}; // 하, 우, 상, 좌 순서
int dx[4] = {0,1,0,-1};
int N,M;
int board[1000][1000];
int dist[1000][1000][2];
queue<tuple<int,int,int>> qu;

int bfs(){
    dist[0][0][0] = dist[0][0][1] =  1; // 3번째 차원이 0 = 벽 부쉈을 때, 1 = 벽 안부쉈을 때
    qu.push({0,0,1});
    while(!qu.empty()){
        auto cur = qu.front(); qu.pop();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int notBroken = get<2>(cur); // 0 = 벽 부숨, 1 = 안 부숨
        if(y == N-1 && x == M-1){
            return dist[y][x][notBroken];
        }
        for(int i=0;i<4;i++){
            int cy = y + dy[i];
            int cx = x + dx[i];
            if(cy >= 0 && cy < N && cx >= 0 && cx < M){

                // cout << "==================" << endl;
                // for(int j=0;j<2;j++){
                //     for(int z=0;z<N;z++){
                //         for(int q=0;q<M;q++){
                //             cout << dist[z][q][j] << ",";
                //         }
                //         cout << endl;
                //     }
                //     cout << "-----------------" << endl;
                // }
                

                if(board[cy][cx] == 0 && dist[cy][cx][notBroken] == 0){
                    qu.push({cy,cx,notBroken});
                    dist[cy][cx][notBroken] = dist[y][x][notBroken]+1;
                } else if(board[cy][cx] == 1 && dist[cy][cx][notBroken] == 0) {
                    if(notBroken == 1){
                        qu.push({cy,cx,0});
                        dist[cy][cx][0] = dist[y][x][notBroken]+1;
                    }
                }
            }
        }
    }
    return dist[N-1][M-1][0];
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<M;j++){
            board[i][j] = str[j]-'0';
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }

    int result = bfs();
    if(result != 0){
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

}