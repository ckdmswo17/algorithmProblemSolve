// 백준 문제 : 스택

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
    stack<int> si;
	for(int i=0;i<N;i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push"){
            int X;
            cin >> X;
            si.push(X);
        } else if(cmd == "pop"){
            if(!si.empty()){
                cout << si.top() << "\n";
                si.pop();
            } else {
                cout << -1 << "\n";
            }
        } else if(cmd == "size"){
            cout << si.size() << "\n";
        } else if(cmd == "empty"){
            if(!si.empty()){
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else if(cmd == "top"){ 
            if(!si.empty()){
                cout << si.top() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    } 
}