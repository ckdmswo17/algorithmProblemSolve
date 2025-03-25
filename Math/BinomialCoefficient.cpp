// 백준 문제 : 이항 계수 1

#include <iostream>

using namespace std;

int factorial(int num){
    if(num == 0){
        return 1;
    } else {
        return num * factorial(num-1);
    }
}

int main(){
    int N,K;
    cin >> N >> K;

    int answer = factorial(N)/(factorial(K)*factorial(N-K));
    cout << answer << "\n";
}