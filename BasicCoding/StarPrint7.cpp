// 백준 문제 : 별 찍기 - 7

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 상단부, 중간
    for(int i=1;i<=N;i++){
        for(int j=0;j<N-i;j++){
            cout << " ";
        }
        for(int j=0;j<2*i-1;j++){
            cout << "*";
        }
        cout << "\n";
    }

    // 하단부
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=0;j<2*N-(1+2*i);j++){
            cout << "*";
        }
        cout << "\n";
    }
}