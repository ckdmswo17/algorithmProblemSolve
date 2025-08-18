// 백준 문제 : 그림

#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int paper[n][m];
    bool visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> paper[i][j];
            visited[i][j] = false;
        }
    }

    int paintingNum = 0;
    int maxArea = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            queue<pair<int,int>> qpi;
            int area = 0;
            if(visited[i][j] == false && paper[i][j] == 1){
                qpi.push({i,j});
                visited[i][j] = true;
                area++;
                paintingNum++;
            }
            while(!qpi.empty()){
                // pop
                pair<int,int> cur = qpi.front();
                qpi.pop();

                for(int z=0;z<4;z++){
                    int nxtY = cur.first + dy[z];
                    int nxtX = cur.second + dx[z];
                    if(paper[nxtY][nxtX] == 1 && visited[nxtY][nxtX] == false && nxtY >= 0 && nxtY < n && nxtX >= 0 && nxtX < m){
                        qpi.push({nxtY,nxtX});
                        visited[nxtY][nxtX] = true;
                        area++;
                    }
                }
            }
            if(area > maxArea){
                maxArea = area;
            }
        }
    }

    cout << paintingNum << "\n" << maxArea << "\n";
}