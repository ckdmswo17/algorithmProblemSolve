// 백준 문제 : 별 찍기 - 6

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=0;j<2*N-(1+2*i);j++){
            cout << "*";
        }
        cout << "\n";
    }
}