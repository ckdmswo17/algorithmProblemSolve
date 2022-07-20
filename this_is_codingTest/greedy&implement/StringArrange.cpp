// 이코테 문제 : 문자열 재정렬
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    string s;
    cin >> s;
    int leng = s.size();
    
    char* charArr = new char[leng];
    int sum= 0;
    int charCount = 0;
    for(int i=0;i<leng;i++){
        if(isdigit(s[i])){
            sum += s[i] - '0';
        } else {
            charArr[charCount] = s[i];
            charCount++;
        }
    }
    
    sort(charArr,charArr+charCount);
    for(int i=0;i<charCount;i++){
        cout << charArr[i] << endl;
    }
    
    string answer = string(charArr) + to_string(sum);
    cout << answer;
    delete(charArr);
}