// 백준 문제 : 불!
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

    int R,C;
    cin >> R >> C;

    // 미로 2차원 배열
    // visited 2차원 배열
    // 최단거리 2차원 배열
    // 사람용 큐, 불용 큐

    queue<pair<int,int> > humanQu;
    queue<pair<int,int> > fireQu;

    bool visited[R][C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            visited[i][j] = false;
        }
    }

    int minDist[R][C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            minDist[i][j] = 0;
        }
    }

    char maze[R][C];
    for(int i=0;i<R;i++){
        string str;
        cin >> str;
        for(int j=0;j<C;j++){
            maze[i][j] = str[j];
            if(str[j] == 'J'){
                humanQu.push({i,j});
                visited[i][j] = true;
            } else if(str[j] == 'F'){
                fireQu.push({i,j});
            }
        }
    }

    int ans = -1;
    while(ans == -1 && !humanQu.empty()){
        // fireQu bfs
        queue<pair<int,int> > fireQu2;
        while(!fireQu.empty()){
            pair<int,int> curF = fireQu.front();
            fireQu.pop();

            for(int i=0;i<4;i++){
                int nxtY = curF.Y + dy[i];
                int nxtX = curF.X + dx[i];
                if(0 <= nxtY && nxtY < R && 0 <= nxtX && nxtX < C){
                    if(maze[nxtY][nxtX] != '#' && maze[nxtY][nxtX] != 'F'){
                        fireQu2.push({nxtY,nxtX});
                        maze[nxtY][nxtX] = 'F';
                    }
                }
            }
        }
        // 이번 턴의 queue 다 비우고 난 후, 새로 push한 queue2를 queue에 복사 
        fireQu = fireQu2;

        // humanQu bfs
        queue<pair<int,int> > humanQu2;
        while(!humanQu.empty()){
            pair<int,int> curH = humanQu.front();
            humanQu.pop();
            
            for(int i=0;i<4;i++){
                int nxtY = curH.Y + dy[i];
                int nxtX = curH.X + dx[i];
                if(0 <= nxtY && nxtY < R && 0 <= nxtX && nxtX < C){
                    if(maze[nxtY][nxtX] == '.' && visited[nxtY][nxtX] == false){
                        humanQu2.push({nxtY,nxtX});
                        visited[nxtY][nxtX] = true;
                        minDist[nxtY][nxtX] = minDist[curH.Y][curH.X]+1;
                    }
                } else {
                    ans = minDist[curH.Y][curH.X]+1;
                    break;
                }
            }
            if(ans != -1){
                break;
            }
        }
        humanQu = humanQu2;
    }

    if(ans == -1){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
    }
}