// 백준 문제 : 토마토 (시간초과로 미해결)

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(){

}

int main(){
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};

    int M,N;
    cin >> M >> N;

    vector<vector<int>> box(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            string a;
            cin >> a;
            box[i][j] = stoi(a);
            if(a == 1){
                qu.push({i,j});
            }
        }
    }

    queue<pair<int,int>> qu;
    

    return 0;
}