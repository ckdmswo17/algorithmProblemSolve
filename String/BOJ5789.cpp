// 백준 문제 : 한다 안한다

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        cout << ((str.substr(str.size()/2-1,1) == str.substr(str.size()/2,1)) ? "Do-it" : "Do-it-Not") << "\n";
    }
}