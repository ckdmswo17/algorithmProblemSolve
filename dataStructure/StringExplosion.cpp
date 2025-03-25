// 백준 문제 : 문자열 폭발 (2023 LIG넥스원 하반기 기출문제와 유사, 미완)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str, exStr;
    cin >> str >> exStr;

    vector<char> s;
    int isStart = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == exStr[0]){
            isStart += 1;
        }
        if(isStart > 0){
            s.push_back(str[i]);
            if(str[i] == exStr[exStr.length()-1]){
                for(int j=0;j<exStr.length();j++){
                    s.pop_back();
                    // str = str.substr(0,i)+str.substr(i+1,str.length());
                    str.erase(i);
                    i -= 1;
                }
                isStart -= 1;
            }
        }
    }

    if(str != ""){
        cout << str << "\n";
    } else {
        cout << "FRULA" << "\n";
    }

    // while(str.find(exStr) < str.length()){
    //     str.replace(str.find(exStr),exStr.length(),"");
    // }

    // if(str != ""){
    //     cout << str << "\n";
    // } else {
    //     cout << "FRULA" << "\n";
    // }

}