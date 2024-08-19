// 백준 문제 : 나이트의 이동
#include <iostream>
#include <queue>
#include <vector>
// #include <cmath>

using namespace std;

int dy[8] = {-2,-1,1,2,2,1,-1,-2}; // 12시부터 시계방향으로 
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int>> qu;

int bfs(int i,int l,pair<int,int> startPos, pair<int,int> endPos,vector<vector<int>> board){
    if(startPos == endPos){
        return 0;
    }
    board[startPos.first][startPos.second] = 0;
    qu.push({startPos.first,startPos.second});

    while(!qu.empty() && board[endPos.first][endPos.second] == -1){
        auto cur = qu.front(); qu.pop();
        // float curDistance  = sqrt(pow(cur.first-endPos.first,2)+pow(cur.second-endPos.second,2));
        // cout << "현재 큐 요소 : "<<cur.first <<","<< cur.second  << "{" << board[cur.first][cur.second]<< "}"<< endl;
        for(int j=0;j<8;j++){
            int cy = cur.first + dy[j];
            int cx = cur.second + dx[j];
            if(cy >= 0 && cy < l && cx >= 0 && cx < l && board[cy][cx] == -1){
                // float cDistance = sqrt(pow(cy-endPos.first,2)+pow(cx-endPos.second,2));
                // if(cDistance < curDistance || cDistance <= sqrt(5)){ // 시간, 공간 복잡도 측면에서 개선 X -> 오히려 오답 
                board[cy][cx] = board[cur.first][cur.second] + 1;
                // cout << "현재 큐에 삽입되는 요소 : "<< cy << "," << cx << endl;
                qu.push({cy,cx});
                // }
            }
        }
    }

    qu = queue<pair<int,int>>();
    return board[endPos.first][endPos.second];
}

int main(){
    int t;
    cin >> t;

    vector<int> l(t,0);
    vector<pair<int,int>> startPos(t,{0,0});
    vector<pair<int,int>> endPos(t,{0,0});
    for(int i=0;i<t;i++){
        cin >> l[i];

        cin >> startPos[i].first >> startPos[i].second;

        cin >> endPos[i].first >> endPos[i].second;
    }

    for(int i=0;i<t;i++){
        vector<vector<int>> board(l[i],vector<int>(l[i],-1));
        int result = bfs(i,l[i],startPos[i],endPos[i],board);
        cout << result << endl;
    }
}