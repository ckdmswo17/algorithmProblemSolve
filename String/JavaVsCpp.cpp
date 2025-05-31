// 백준 문제 : Java vs C++

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string varName;
    cin >> varName;

    string changeName = "";
    if(varName[0] == '_' || varName[varName.size()-1] == '_'){
        cout << "Error!\n"; return 0;
    }
    else if(varName.find('_') != string::npos){
        // C++ 형식 -> Java 형식
        // cout << "C++ > Java\n";
        int nowIdx = 0;
        int nxtIdx = varName.find('_',nowIdx);
        while(nxtIdx != string::npos){
            if(varName[nxtIdx+1] == '_') {
                cout << "Error!\n"; return 0;
            }
            if(nowIdx == 0){
                changeName += varName.substr(nowIdx,nxtIdx-nowIdx);
            } else {
                string tmpStr = varName.substr(nowIdx,nxtIdx-nowIdx);
                tmpStr[0] = toupper(tmpStr[0]);
                changeName += tmpStr;
            }
            nowIdx = nxtIdx+1;
            nxtIdx = varName.find('_',nowIdx);
        }
        string tmpStr = varName.substr(nowIdx);
        tmpStr[0] = toupper(tmpStr[0]);
        changeName += tmpStr;
        for(int i=0;i<varName.size();i++){
            if(isupper(varName[i]) != 0){
                cout << "Error!\n"; return 0;
            }
        }
        cout << changeName << "\n";
    } else if(islower(varName[0]) != 0){
        // Java 형식 -> C++ 형식
        // cout << "Java > C++\n";
        int nowIdx = 0;
        for(int i=0;i<varName.size();i++){
            if(isupper(varName[i]) != 0){
                string tmpStr = varName.substr(nowIdx,i-nowIdx);
                tmpStr[0] = tolower(tmpStr[0]);
                changeName += tmpStr;
                changeName += '_';
                nowIdx = i;
            }
        }
        string tmpStr = varName.substr(nowIdx);
        tmpStr[0] = tolower(tmpStr[0]);
        changeName += tmpStr;

        cout << changeName << "\n";
    } else {
        cout << "Error!\n";
    }
}