// 백준 문제 : A+B - 5

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B;
    cin >> A >> B;
    while(A != 0 && B != 0){
        cout << A+B << "\n";
        cin >> A >> B;
    }
}