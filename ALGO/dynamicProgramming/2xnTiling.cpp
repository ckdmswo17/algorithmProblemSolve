// 백준 문제 : 2xn 타일링

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cases[n+1];
    cases[1] = 1;
    cases[2] = 2;
    for(int i=3;i<=n;i++){ // 백준 문제 1,2,3 더하기와 유사. 세로막대를 1, 가로막대를 2로 보면 더해서 N을 만드는 경우의 수 문제로 볼 수 있음
        cases[i] = (cases[i-1] + cases[i-2])%10007; // n(a+b)%10007 == n(a)%10007 + n(b)%10007 이므로 결과에만 %10007을 하는 방식은 cases 원소의 int 범위 초과를 일으킬수 있음.
    }

    cout << cases[n] << "\n";
}

