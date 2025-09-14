// 백준 문제 : X marks the Spot

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string ans = "";
    for(int i=0;i<N;i++){
        string str1, str2;
        cin >> str1 >> str2;

        int xPos = str1.find("x");
        int XPos = str1.find("X");
        if(xPos != string::npos){
            ans += ((isdigit(str2[xPos]) == true)?str2[xPos]:toupper(str2[xPos]));
        } else if(XPos != string::npos){
            ans += ((isdigit(str2[XPos]) == true)?str2[XPos]:toupper(str2[XPos]));
        }
    }
    cout << ans << "\n";
}