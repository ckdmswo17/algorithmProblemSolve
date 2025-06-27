// 백준 문제 : 빠른 A+B

#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int A,B;
        cin >> A >> B;
        cout << A+B << "\n";
    }
}