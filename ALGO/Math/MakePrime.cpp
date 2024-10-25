// 백준 문제 : 소수 구하기 (에라토스테네스의 체 활용)

#include <iostream>

using namespace std;

int main(){
    int M,N;
    cin >> M >> N;

    bool isPrime[N+1];
    fill_n(isPrime,N+1,true);
    isPrime[1] = false;

    for(int i=2;i<N+1;i++){
        if(isPrime[i] == true){
            for(int j=2;i*j<N+1;j++){
                isPrime[i*j] = false;
            }
        }
    }

    for(int i=M;i<N+1;i++){
        if(isPrime[i] == true){
            cout << i << "\n";
        }
    }
}