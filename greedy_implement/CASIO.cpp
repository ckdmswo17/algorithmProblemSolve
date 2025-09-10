// 백준 문제 : CASIO

#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    long N, M; // 9999999999까지 들어올 수 있으므로 int의 최대범위인 21억을 초과함
    cin >> N >> M;

    cout << ( (N==M) ? 1 : 0 ) << "\n";
}