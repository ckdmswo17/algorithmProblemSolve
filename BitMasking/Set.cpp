// 백준 문제 : 집합

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M;
    cin >> M;

    int tmp = 0;
    for(int i=0;i<M;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            int x;
            cin >> x;
            if((tmp & (1 << x)) == 0) tmp += pow(2,x);
        } else if(cmd == "remove"){
            int x;
            cin >> x;
            if((tmp & (1 << x)) != 0) tmp -= pow(2,x);
        } else if(cmd == "check"){
            int x;
            cin >> x;
            if((tmp & (1 << x)) != 0) cout << "1\n";
            else cout << "0\n";
        } else if(cmd == "toggle"){
            int x;
            cin >> x;
            if((tmp & (1 << x)) != 0) tmp -= pow(2,x);
            else tmp += pow(2,x); 
        } else if(cmd == "all"){
            tmp = 2097150;
        } else {
            tmp = 0;
        }
    }
    
}