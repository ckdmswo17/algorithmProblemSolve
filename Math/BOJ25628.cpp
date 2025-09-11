// 백준 문제 : 햄버거 만들기

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B;
    cin >> A >> B;
    int halfA = A/2;
    cout << ((halfA > B) ? B : halfA ) << "\n"; 
}