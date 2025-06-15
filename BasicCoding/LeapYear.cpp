// 백준 문제 : 윤년

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;
    if(year % 4 == 0){
        if(!(year % 100 == 0) || (year % 400 == 0)){
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}