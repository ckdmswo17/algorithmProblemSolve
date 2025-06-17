// 백준 문제 : 주사위 세개

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    
    if((n1 == n2)&&(n2==n3)){
        cout << 10000 + n1*1000;
    } else if((n1 == n2) || (n2==n3)) cout << 1000 + n2 * 100;
    else if(n1==n3) cout << 1000 + n3*100;
    else cout << 100*max({n1,n2,n3});
}