// 백준 문제 : 토마토 (3차원)

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dz[6] = {-1,1,0,0,0,0}; // 위, 아래, 앞, 오, 뒤, 좌 순서
int dy[6] = {0,0,-1,0,1,0};
int dx[6] = {0,0,0,1,0,-1};
int M,N,H;
int box[100][100][100];
queue<tuple<int,int,int>> qu;
queue<tuple<int,int,int>> qu2;

void bfs(){
    qu = qu2;
    qu2 = queue<tuple<int,int,int>>();

    while(!qu.empty()){
        tuple<int,int,int> cur = qu.front(); qu.pop();
        for(int i=0;i<6;i++){
            int cz = get<0>(cur) + dz[i];
            int cy = get<1>(cur) + dy[i];
            int cx = get<2>(cur) + dx[i];
            if(cz >= 0 && cz < H && cy >= 0 && cy < N && cx >= 0 && cx < M && box[cz][cy][cx] == 0){
                tuple<int,int,int> t = make_tuple(cz,cy,cx);
                qu2.push(t);
                box[cz][cy][cx] = 1;
            }
        }
    }
}

int main(){
    cin >> M >> N >> H;

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int z=0;z<M;z++){
                cin >> box[i][j][z];
                if(box[i][j][z] == 1){
                    tuple<int,int,int> t = make_tuple(i,j,z);
                    qu2.push(t);
                }
            }
        }
    }

    int count = -1;
    while(!qu2.empty()){
        bfs();
        count += 1;
    }

    bool isFail = false;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int z=0;z<M;z++){
               if(box[i][j][z] == 0){
                    isFail = true;
                    break;
               } 
            }
            if(isFail){
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
}