// 백준 문제 : A/B

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    double A,B;
    cin >> A >> B;
    cout << fixed << setprecision(9) << A/B << "\n";
}
