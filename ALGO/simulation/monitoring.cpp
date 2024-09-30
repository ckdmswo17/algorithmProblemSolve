// 백준 문제 : 감시

#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<pair<int,int>> cctvs;
int answer;
int dy[15][4] = {{-1,0,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0},{-1,0,1,0},{0,0,0,0},{-1,0,0,0},{0,0,1,0},{0,0,1,0},{-1,0,0,0},{-1,0,1,0},{0,0,1,0},{-1,0,1,0},{-1,0,0,0},{-1,0,1,0}};
int dx[15][4] = {{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,-1},{0,0,0,0},{0,1,0,-1},{0,1,0,0},{0,1,0,0},{0,0,0,-1},{0,0,0,-1},{0,1,0,0},{0,1,0,-1},{0,0,0,-1},{0,1,0,-1},{0,1,0,-1}};

void monitor(vector<vector<int>> map, int count){
    if(count == cctvs.size()){
        // cout << "==================\n";
        int area = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                // cout << map[i][j] << " ";
                if(map[i][j] == 0){
                    area += 1;
                }
            }
            // cout << "\n";
        }
        // cout << area<< "\n";
        if(answer > area){
            answer = area;
        }
        return;
    }

    int y = cctvs[count].first;
    int x = cctvs[count].second;
    int e = map[y][x];
    switch (e)
    {
        case 1:
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] <= 0){
                                map[cy][cx] -= 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
                monitor(map,count+1);
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] < 0){
                                map[cy][cx] += 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
            }
            
            break;
        case 2 :
            for(int i=4;i<6;i++){
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] <= 0){
                                map[cy][cx] -= 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
                monitor(map,count+1);
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] < 0){
                                map[cy][cx] += 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
            }
            break;
        case 3:
            for(int i=6;i<10;i++){
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] <= 0){
                                map[cy][cx] -= 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
                monitor(map,count+1);
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] < 0){
                                map[cy][cx] += 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
            }
            break;
        case 4:
            for(int i=10;i<14;i++){
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] <= 0){
                                map[cy][cx] -= 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
                monitor(map,count+1);
                for(int j=0;j<4;j++){
                    bool isEnd = false;
                    int step = 1;
                    while(isEnd == false){
                        int cy = y + dy[i][j] * step;
                        int cx = x + dx[i][j] * step;
                        if(dy[i][j] == 0 && dx[i][j] == 0){
                            break;
                        }
                        if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                            if(map[cy][cx] < 0){
                                map[cy][cx] += 1;
                            }
                        } else {
                            isEnd = true;
                        }
                        step += 1;
                    }
                }
            }
            break;
        case 5:
            for(int j=0;j<4;j++){
                bool isEnd = false;
                int step = 1;
                while(isEnd == false){
                    int cy = y + dy[14][j] * step;
                    int cx = x + dx[14][j] * step;
                    if(dy[14][j] == 0 && dx[14][j] == 0){
                            break;
                        }
                    if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                        if(map[cy][cx] <= 0){
                            map[cy][cx] -= 1;
                        }
                    } else {
                        isEnd = true;
                    }
                    step += 1;
                }
            }
            monitor(map,count+1);
            for(int j=0;j<4;j++){
                bool isEnd = false;
                int step = 1;
                while(isEnd == false){
                    int cy = y + dy[14][j] * step;
                    int cx = x + dx[14][j] * step;
                    if(dy[14][j] == 0 && dx[14][j] == 0){
                            break;
                        }
                    if(cy >= 0 && cy < N && cx >= 0 && cx < M && map[cy][cx] != 6){
                        if(map[cy][cx] < 0){
                            map[cy][cx] += 1;
                        } 
                    } else {
                        isEnd = true;
                    }
                    step += 1;
                }
            }
            break;
        default:
            break;
    }
}

int main(){
    cin >> N >> M;
    answer = N * M;
    vector<vector<int>> map(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cctvs.push_back({i,j});
            }
        }
    }

    monitor(map,0);
    cout << answer << "\n";
}