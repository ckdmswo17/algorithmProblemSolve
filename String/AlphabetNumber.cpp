// 백준 문제 : 알파벳 개수

#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int alphabetLength = 'z'-'a'+1;
	int alphabetNum[alphabetLength];
    for(int i=0;i<alphabetLength;i++){
        alphabetNum[i] = 0;
    }

    string word;
    cin >> word;
    for(int i=0;i<word.length();i++){
        alphabetNum[word[i]-'a']++;
    }

    for(int i:alphabetNum){
        cout << i << " ";
    }
    cout << "\n";
	
}