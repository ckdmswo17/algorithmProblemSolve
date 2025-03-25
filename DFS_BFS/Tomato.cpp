// 백준 문제 : 토마토 (2차원)

#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int M,N;
int box[1000][1000];
// bool visited[1000][1000] = {false};
queue<pair<int,int>> qu;
queue<pair<int,int>> qu2;

void bfs(){

    qu = qu2; // 처음만 제외하고 계속 qu2 -> qu 깊은 복사
    qu2 = queue<pair<int,int>>(); // 재선언으로 qu2 비우기
    // while(!qu2.empty()){
    //     auto cur2 = qu2.front(); qu2.pop();
    //     // cout << "{" << cur2.first <<"," << cur2.second << "}";
    // }
    // cout << endl;

    while(!qu.empty()){
        auto cur = qu.front(); qu.pop();
        for(int i=0;i<4;i++){
            int cy = cur.first + dy[i];
            int cx = cur.second + dx[i];
            if(cy >= 0 && cy < N && cx >= 0 && cx < M && box[cy][cx] == 0){
                qu2.push({cy,cx});
                box[cy][cx] = 1;
            }
        }
    }
}

int main(){
    cin >> M >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                qu2.push({i,j});
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         if(box[i][j] == 1){
    //             qu2.push({i,j});
    //         }
    //     }
    // }

    int count = -1;
    while (!qu2.empty()){
        bfs();
        count += 1;
    }

    bool isFail = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(box[i][j] == 0){
                isFail = true;
                break;
            }
        }
        if(isFail){
            break;
        }
    }
    
    if(isFail){
        cout << -1 << endl;
    } else {
        cout << count << endl;
    }
    

    return 0;
}