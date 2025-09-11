// 백준 문제 : 공백 없는 A+B

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string AB;
    cin >> AB;

    int A;
    int B;
    if(AB.substr(0,2) == "10"){
        A = stoi(AB.substr(0,2));
        B = stoi(AB.substr(2));
    } else {
        A = stoi(AB.substr(0,1));
        B = stoi(AB.substr(1)); 
    }
    cout << A+B << "\n";
}