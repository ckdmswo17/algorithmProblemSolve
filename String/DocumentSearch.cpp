// 백준 문제 : 문서 검색

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string doc;
    getline(cin, doc);

    string word;
    getline(cin, word);

    int answer = 0;
    int pos = doc.find(word);
    while(pos != -1) {
        doc.erase(pos,word.length());
        // cout << doc << " " << pos << "\n";
        answer++;
        pos = doc.find(word,pos);
    }
    cout << answer << "\n";
}