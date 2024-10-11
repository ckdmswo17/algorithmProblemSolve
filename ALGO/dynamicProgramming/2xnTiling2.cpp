// 백준 문제 : 2xn 타일링 2

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cases[n+1];
    cases[1] = 1;
    cases[2] = 3; // 1 , 3, 5 , 11, 
    for(int i=3;i<=n;i++){
        cases[i] = (cases[i-1] + cases[i-2]*2)%10007;
    }

    cout << cases[n] << "\n";
}

