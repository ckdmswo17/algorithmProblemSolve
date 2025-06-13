// 백준 문제 : 퇴사 2

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int T[N+1];
    int P[N+1];
    for(int i=1;i<N+1;i++){
        int Ti,Pi;
        cin >> Ti >> Pi;

        T[i] = Ti;
        P[i] = Pi;
    }

    int max[N+1];
    for(int i=0;i<N+1;i++){
        max[i] = 0;
    }

    for(int i=1;i<N+1;i++){
        // for(int j=1;j<N+1;j++){
        //     cout << max[j] << " ";
        // }
        // cout << "\n";

        if(i + T[i] - 1 <= N){
            if(max[i + T[i]-1] < max[i-1] + P[i]){
                max[i+T[i]-1] = max[i-1] + P[i];
            }
        }
        if(max[i] < max[i-1]){
            max[i] = max[i-1];
        } 
    }
    cout << max[N] << "\n";
}