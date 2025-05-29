// 백준 문제 : 한국이 그리울 땐 서버에 접속하지

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    string fileNames[N];
    for(int i=0;i<N;i++){
        cin >> fileNames[i];
    }

    int starPos = pattern.find('*');
    string frontStr = pattern.substr(0,starPos);
    string backStr = pattern.substr(starPos+1,pattern.size()-starPos+1);
    for(string f:fileNames){
        if(pattern.size()-1 <= f.size()){
            if(frontStr == f.substr(0,frontStr.size())){
                if(backStr == f.substr(f.size()-backStr.size(),backStr.size())){
                    cout << "DA\n";
                    continue;
                }
            }
        }
        cout << "NE\n";
    }
}

// f : abcd 
// pattern : a*d
// frontStr : a
// backStr : d