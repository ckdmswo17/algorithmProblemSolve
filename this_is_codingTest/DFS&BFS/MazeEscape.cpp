// 이코테 문제 : 미로 탈출
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N;
int M;
int** graph;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(int y,int x){
    queue<pair<int,int>> q;
    q.push({y,x});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if((0 > ny || ny >= N)||(0 > nx || nx >= M)){
                continue;
            }
            if(graph[ny][nx] == 0){
                continue;
            }
            if(graph[ny][nx] == 1){
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ny,nx});
            }

            // cout << ny << " " << nx << "\n"; 
            // for(int j=0;j<N;j++){
            //     for(int z=0;z<M;z++){
            //         cout << graph[j][z]<<"/" ;
            //     }
            //     cout << "\n";
            // }
            // cout << "\n"; 
        }
    }

    return graph[N-1][M-1];
}

int main(){
    cin >> N >> M;
    graph = new int*[N];
    for(int i=0;i<N;i++){
        graph[i] = new int[M];
    }

    for(int i=0;i<N;i++){
        string line;
        cin >> line;
        for(int j=0;j<M;j++){
            graph[i][j] = stoi(line.substr(j,1));
        }
    }
    cout << bfs(0,0) << "\n";
    
    for(int i=0;i<N;i++){
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}