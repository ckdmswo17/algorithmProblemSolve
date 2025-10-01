// 백준 문제 : 문자와 문자열

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int idx;
    cin >> idx;

    cout << str[idx-1] << "\n";
}