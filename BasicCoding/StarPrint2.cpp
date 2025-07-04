// 백준 문제 : 별 찍기 - 1

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<i+1;j++){
            cout << "*";
        }
        cout << "\n";
    }
}