// 백준 문제 : N-Queen

#include <iostream>

using namespace std;

int N;
int answer = 0;
vector<pair<int,int>> arr(14,{0,0});
int dy[8] = {-1,-1,0,1,1,1,0,-1}; // 위부터 시계방향으로
int dx[8] = {0,1,1,1,0,-1,-1,-1};

void queen(int y, int x, int count){
    if(count == N){
        answer += 1;
        return;
    }
    for(int i=y;i<N;i++){
        for(int j=x;j<N;j++){
            // cout << "현재 원소 :" << i << " " << j <<  " " << count << "\n"; 

            bool isOkay = true;
            for(int z=0;z<count;z++){
                pair<int,int> p = arr[z];
                cout << "기존 원소 :"<< p.first << " " << p.second << " " << count << "\n";
                for(int q=0;q<8;q++){
                    for(int m=0;m<N;m++){
                        int cy = p.first+dy[q]*m;
                        int cx = p.second+dx[q]*m;
                        // cout << "검사 원소 :" << cy << " " << cx << "\n";

                        if(cy == i && cx == j){
                            // cout << "걸림" << "\n";
                            isOkay = false;
                            break;
                        } 
                    }
                    if(isOkay == false){
                        break;
                    }
                }
                if(isOkay == false){
                    break;
                }
            }
            if(isOkay){
                // cout << "재귀!" << endl;
                arr[count] = {i,j};
                queen(i,j,count+1);

            }
        }
    }
}

int main(){
    cin >> N;

    queen(0,0,0);
    cout << answer << "\n";
    
}