// 백준 문제 : 이친수

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long piNum[N+1];
    piNum[1] = 1;
    piNum[2] = 1;
    for(int i=3;i<=N;i++){
        piNum[i] = piNum[i-1] + piNum[i-2];
    }
    cout << piNum[N] << "\n";
}