// 백준 문제 : 구구단

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=9;i++){
        cout << N << " * " << i << " = " << N*i << "\n";
    }
}