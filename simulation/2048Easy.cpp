// 백준 문제 : 2048 (Easy) : 미완

#include <iostream>

using namespace std;

int N;
int answer = 0;

void game(vector<vector<int>> map,int count){
    if(count == 5){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j] > answer){
                    answer = map[i][j];
                }
            }
        }
    }

    for(int i=0;i<4;i++){
        switch (i)
        {
            case 0:

                break;
            
            case 1:
                for(int j=0;j<N;j++){
                    for(int z=N-2;z>=0;z--){
                        
                    }
                }
                break;

            case 2:
                break;

            case 3:
                break;
            
            default:
                break;
        }
    }

}

int main(){
    cin >> N;
    vector<vector<int>> map(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }


}