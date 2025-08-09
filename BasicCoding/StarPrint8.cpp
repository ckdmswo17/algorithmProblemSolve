// 백준 문제 : 별 찍기 - 8

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    bool beforeHalf = true;
    // 줄 반복
    for(int i=1;i<=2*N-1;i++){
        if(beforeHalf == true){
            for(int j=0;j<i;j++){
                cout << "*";
            }
            for(int j=0;j<2*(N-i);j++){
                cout << " ";
            }
            for(int j=0;j<i;j++){
                cout << "*";
            }
            if(i == (int)((2*N-1)/2+1)){
                beforeHalf = false;
            }
        } else {
            for(int j=0;j<N-(i%N);j++){
                cout << "*";
            }
            for(int j=0;j<2*(i%N);j++){
                cout << " ";
            }
            for(int j=0;j<N-(i%N);j++){
                cout << "*";
            }
        }
        cout << "\n";
    }
}