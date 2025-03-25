// 백준 문제 : 이항 계수 2

#include <iostream>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    int bc[N+1][N+1];
    bc[0][0] = 1;
    bc[1][0] = 1;
    bc[1][1] = 1;
    for(int i=2;i<N+1;i++){
        for(int j=0;j<i+1;j++){
            if(j==0 || j == i){
                bc[i][j] = 1;
            } else {
                bc[i][j] = (bc[i-1][j-1]+bc[i-1][j])%10007; // 파스칼 삼각형 법칙 이용
            }
        }
    }

    

    int answer = bc[N][K];
    cout << answer << "\n";
}