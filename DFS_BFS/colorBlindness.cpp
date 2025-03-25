// 백준 문제 : 적록색약
#include <iostream>
#include <string>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool dfs(char **art, int y, int x, char color,bool isBlind,int N){
    if((y < 0 || y >= N) || (x < 0 || x>= N)){
        return false;
    }
    if(!isBlind){
        if(art[y][x] == color){
            art[y][x] = '0';
            dfs(art,y+dy[0],x+dx[0],color,isBlind,N);
            dfs(art,y+dy[1],x+dx[1],color,isBlind,N);
            dfs(art,y+dy[2],x+dx[2],color,isBlind,N);
            dfs(art,y+dy[3],x+dx[3],color,isBlind,N);
            return true;
        } else {
            return false;
        }
    } else {
        if(color == 'B'){
            if(art[y][x] == color){
                art[y][x] = '0';
                dfs(art,y+dy[0],x+dx[0],color,isBlind,N);
                dfs(art,y+dy[1],x+dx[1],color,isBlind,N);
                dfs(art,y+dy[2],x+dx[2],color,isBlind,N);
                dfs(art,y+dy[3],x+dx[3],color,isBlind,N);
                return true;
            } else {
                return false;
            }
        } else {
            if(art[y][x] == 'R' || art[y][x] == 'G'){
                art[y][x] = '0';
                dfs(art,y+dy[0],x+dx[0],color,isBlind,N);
                dfs(art,y+dy[1],x+dx[1],color,isBlind,N);
                dfs(art,y+dy[2],x+dx[2],color,isBlind,N);
                dfs(art,y+dy[3],x+dx[3],color,isBlind,N);
                return true;
            } else {
                return false;
            }
        }
    }

}

int main(){
    int N;
    cin >> N;
    char** art;
    char** art2;
    art = new char *[N];
    art2 = new char *[N];
    for(int i=0;i<N;i++){
        art[i] = new char[N];
        art2[i] = new char[N];
        string str;
        cin >> str;
        for(int j=0;j<N;j++){
            art[i][j] = str[j];
            art2[i][j] = str[j];
        }
    }

    int count = 0;
    int count2 = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(art[i][j] != '0' && dfs(art,i,j,art[i][j],false,N)){
                count += 1;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(art2[i][j] != '0' && dfs(art2,i,j,art2[i][j],true,N)){
                count2 += 1;
            }
        }
    }

    cout << count << " " << count2 << endl;
}