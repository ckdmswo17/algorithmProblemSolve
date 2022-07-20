// 이코테 문제 : 곱하기 혹은 더하기
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string numString = "";
    cin >> numString;
    const int numSize = numString.length();
    
    int n[numSize];
    for(int i=0;i<numSize;i++){
        n[i] = numString[i] - '0';
    }
    
    int cur = n[0];
    
    for(int i=1;i<numSize;i++){
        if(cur <= 1 || n[i] <= 1) {
            cur += n[i];
        } else {
            cur *= n[i];
        }
    }
    
    cout << cur;
}