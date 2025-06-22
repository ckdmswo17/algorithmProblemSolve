// 백준 문제 : 숫자

#include <iostream> 
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A,B;
    cin >> A >> B;

    if(A == B) {
        cout << 0 << "\n";
    } else {
        cout << max(A,B) - min(A,B) - 1 << "\n";
    }
    for(long long i=min(A,B)+1;i<max(A,B);i++){
        cout << i << " ";
    }
}