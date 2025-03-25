// 백준 문제 : RGB 거리 2 (미완)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    int costs[N][3];
    for(int i=0;i<N;i++){
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    int smallestCosts[N][3];
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            if(i == 0){
                smallestCosts[i][j] = costs[i][j];    
            }
            else if(i==N-1){
                smallestCosts[i][j] = min(smallestCosts)
            }
            else {
                smallestCosts[i][j] = min(smallestCosts[i-1][(j+1)%3]+costs[i][j],smallestCosts[i-1][(j+2)%3]+costs[i][j]);
            }
        }
    }
    int result = min(min(smallestCosts[N-1][0],smallestCosts[N-1][1]),smallestCosts[N-1][2]);
    cout << result << endl;

}