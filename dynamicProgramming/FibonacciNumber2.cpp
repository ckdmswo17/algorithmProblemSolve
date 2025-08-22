// 백준 문제 : 피보나치 수 2
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 초기식 fibo[0] = 0, fibo[1] = 1
    // 점화식 fibo[n] = fibo[n-1] + fibo[n-2] (n >= 2)

    long long fibo[91];
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[n] << "\n";
}