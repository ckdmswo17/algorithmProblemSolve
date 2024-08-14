// 백준 문제 : 백조의 호수 (미완)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count = 0;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int R,C;

bool dfs(vector<vector<string>> lake,int y,int x,int direction){
    if((0<=y && y<R)&&(0<=x && x<C)){
        if(lake[y][x] == "L"){
            return true
        }else if(lake[y][x] == "X"){
            
        } else {
            
            dfs(lake,y+dy[0],x+dx[0],0); // 상
            dfs(lake,y+dy[1],x+dx[1],1); // 우
            dfs(lake,y+dy[2],x+dx[2],2); // 하
            dfs(lake,y+dy[3],x+dx[3],3); // 좌
        }
    }
    return false;
}

int main(){

    cin >> R >> C;

    vector<vector<string>> lake(R,vector<string>(C,""));
    for(int i=0;i<R;i++){
        string sentence;
        cin >> sentence;
        for(int j=0;j<C;j++){
            lake[i][j] = sentence.substr(j,1);
        }
    }        

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(lake[i][j] == "."){
                for(int z=0;z<4;z++){
                    if((i+dy[z] >= 0 && i+dy[z] < R)&&(j+dx[z] >= 0 && j+dx[z] < C)){
                        if(lake[i+dy[z]][j+dx[z]] == "X"){
                            lake[i+dy[z]][j+dx[z]] = "1";
                        }
                    }
                }
            }
        }
    }
    for(int i =0;i<R;i++){
        for(int j=0;j<C;j++){
            if(lake[i][j] == "1"){
                lake[i][j] = ".";
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << lake[i][j] << " ";
        }
        cout << "\n";
    }
}