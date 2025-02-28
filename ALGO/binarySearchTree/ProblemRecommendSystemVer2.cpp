// 백준 문제 : 문제 추천 시스템 Version 2

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; 
    cin >> N;
    int probLevel[100002]; // 해당 문제번호가 몇 난이도인지
    int probAlgo[100002]; // 해당 문제번호가 무슨 알고리즘 분류인지
    set<int> probByLevel[102]; // 해당 난이도에 문제번호가 무엇이 있는지
    set<int> probByGL[102][102]; // 해당 알고리즘,난이도에 문제번호가 무엇이 있는지

    for(int i=0;i<N;i++){
        int P,L,G;
        cin >> P >> L >> G;

        probLevel[P] = L;
        probAlgo[P] = G;
        probByLevel[L].insert(P);
        probByGL[G][L].insert(P);
    }

    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        string command;
        cin >> command;
        if(command == "add"){
            int P,L,G;
            cin >> P >> L >> G;
            probLevel[P] = L;
            probAlgo[P] = G;
            probByLevel[L].insert(P);
            probByGL[G][L].insert(P);
        } else if(command == "recommend"){
            int G,x;
            cin >> G >> x;
            if(x == 1){
                for(int j=100;j>=0;j--){
                    if(probByGL[G][j].empty()){
                        continue;
                    }
                    cout << *prev(probByGL[G][j].end()) << "\n";
                    break;
                }
            } else {
                for(int j=0;j<=100;j++){
                    if(probByGL[G][j].empty()){
                        continue;
                    }
                    cout << *probByGL[G][j].begin() << "\n";
                    break;
                }
            }
        } else if(command == "recommend2"){
            int x;
            cin >> x;
            if(x == 1){
                for(int j=100;j>=0;j--){
                    if(probByLevel[j].empty()){
                        continue;
                    }
                    cout << *prev(probByLevel[j].end()) << "\n";
                    break;
                }
            } else {
                for(int j=0;j<=100;j++){
                    if(probByLevel[j].empty()){
                        continue;
                    }
                    cout << *probByLevel[j].begin() << "\n";
                    break;
                }
            }
        } else if(command == "recommend3"){
            int x,L;
            cin >> x >> L;
            int ans = -1;
            if(x == 1){
                for(int j=L;j<=100;j++){
                    if(probByLevel[j].empty()){
                        if(j == 100){
                            cout << -1 << "\n";
                        }
                        continue;
                    }
                    cout << *probByLevel[j].begin() << "\n";
                    // ans = *probByLevel[j].begin();
                    break;
                }
            } else {
                for(int j=L-1;j>=0;j--){
                    if(probByLevel[j].empty()){
                        if(j == 0){
                            cout << -1 << "\n";
                        }
                        continue;
                    }
                    cout << *prev(probByLevel[j].end()) << "\n";
                    // ans = *prev(probByLevel[j].end());
                    break;
                }
            }
            cout << ans << "\n";
        } else {
            int P;
            cin >> P;
            probByLevel[probLevel[P]].erase(P);
            probByGL[probAlgo[P]][probLevel[P]].erase(P);
        }
    }
}   