// 백준 문제 : 문제 추천 시스템 Version 1

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // (https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x16/solutions/21939.cpp) 참고 버전
    cin >> N;
    int probLevel[100001]; // 해당 문제번호가 몇 난이도인지
    set<int> probByLevel[101]; // 해당 난이도에 문제번호가 무엇이 있는지

    for(int i=0;i<N;i++){
        int P,L;
        cin >> P >> L;
        probLevel[P] = L;
        probByLevel[L].insert(P);
    }

    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        string command;
        cin >> command;
        if(command == "add"){
            int P,L;
            cin >> P >> L;
            probLevel[P] = L;
            probByLevel[L].insert(P);
        } else if(command == "recommend"){
            int x;
            cin >> x;
            if(x == 1){
                for(int j=100;j>=1;j--){
                    if(probByLevel[j].empty()){
                        continue;
                    }
                    cout << *prev(probByLevel[j].end()) << "\n";
                    break;
                }
            } else {
                for(int j=1;j<=100;j++){
                    if(probByLevel[j].empty()){
                        continue;
                    }
                    cout << *probByLevel[j].begin() << "\n";
                    break;
                }
            }
        } else {
            int P;
            cin >> P;
            probByLevel[probLevel[P]].erase(P);
        }
    }
}   