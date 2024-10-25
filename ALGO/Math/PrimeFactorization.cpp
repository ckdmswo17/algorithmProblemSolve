// 백준 문제 : 소인수분해

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=2;N!=1;i++){
        if(N%i == 0){
            cout << i << "\n";
            N /= i;
            i = 1;
        }
    }
}