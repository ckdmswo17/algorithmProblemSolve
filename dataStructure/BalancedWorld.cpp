// 백준 문제 : 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    string str;
    getline(cin,str);
	while(str != "."){
        stack<char> sc;

        // 문자열 처리
        for(const char c:str){
            if(c == '('){
                sc.push('(');
            } else if(c == '['){
                sc.push('[');
            } else if(c == ')'){
                if(!sc.empty() && sc.top() == '(') {
                    sc.pop();
                } else {
                    sc.push(')');
                }
            } else if(c == ']'){
                if(!sc.empty() && sc.top() == '[') {
                    sc.pop();
                } else {
                    sc.push(']');
                }
            }
        }

        // yes or no 출력
        if(sc.empty()) cout << "yes\n";
        else cout << "no\n"; 

        // 다음 반복을 위한 문자열 입력받기
        getline(cin,str);
    }
}