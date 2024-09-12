// 백준 문제 : Z

#include <iostream>
#include <cmath>

using namespace std;

int N;
int r,c;
// int cnt = 0;
int answer = 0;
int spaces[16];
// int dy[4] = {0,0,1,0};
// int dx[4] = {0,1,-1,1};

void z(int minY, int maxY,int minX,int maxX, int step){
    // if(answer != -1){ // 아래 주석친 방법은 시간초과
    //     return;
    // }

    // if(step == 1){
    //     int cy = y;
    //     int cx = x;
    //     for(int i=0;i<4;i++){
            
    //         cy = cy+dy[i];
    //         cx = cx+dx[i];
    //         // cout << cy << " "<< cx << " " << cnt << endl;
    //         if(cy == r && cx == c){
    //             answer = cnt;
    //             break;
    //         }
    //         cnt++;
    //     }
    // } else {
    //     int cy = y;
    //     int cx = x;
    //     for(int i=0;i<4;i++){
    //         if(answer != -1) {
    //             return;
    //         }
    //         cy = cy+ dy[i] * pow(2,step-1);
    //         cx = cx+ dx[i] * pow(2,step-1);
    //         z(cy,cx,step-1);
    //     }
    // }

    if(step == 0){
        for(int i = N;i>0;i--){
            answer += pow(4,i-1) * spaces[i];
        }
    } else {
        int centerY = (minY + maxY)/2;
        int centerX = (minX + maxX)/2; 
        if(r <= centerY){ 
            if(c <= centerX) { // 1사분면 
                spaces[step] = 0;
                z(minY,centerY,minX,centerX,step-1);
            } else { // 2사분면
                spaces[step] = 1;
                z(minY,centerY,centerX+1,maxX,step-1);
            }
        } else { 
            if(c <= centerX) { // 3사분면
                spaces[step] = 2;
                z(centerY+1,maxY,minX,centerX,step-1);
            } else { // 4사분면
                spaces[step] = 3;
                z(centerY+1,maxY,centerX+1,maxX,step-1);
            }
        }
    }


}

int main(){
    cin >> N >> r >> c;
    z(0,pow(2,N)-1,0,pow(2,N)-1,N);
    cout << answer << endl;
}