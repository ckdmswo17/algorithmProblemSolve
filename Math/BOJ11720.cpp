// 백준 문제 : 숫자의 합

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string numStr;
    cin >> numStr;

    int sum = 0;
    for(int i=0;i<numStr.size();i++){
        sum += numStr[i]-'0';
    }
    cout << sum << "\n";
}