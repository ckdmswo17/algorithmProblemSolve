// 백준 문제 : 문제 추천 시스템 Version 1

#include <iostream>
// #include <map>
#include <set>
// #include <queue>
#include <vector>

using namespace std;

// struct Compare {
//     bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
//         return a.second < b.second;  // second 값 기준 오름차순 정렬
//     }
// };


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int N; // set,map,priority_queue 세개쓴 버전 -> 메모리초과
    // cin >> N;
    // set<pair<int,int>,Compare> proList;
    // map<int,int> noCompList;
    // for(int i=0;i<N;i++){
    //     int e1,e2;
    //     cin >> e1 >> e2;
    //     proList.insert({e1,e2});
    //     noCompList.insert({e1,e2});
    // }

    // int M;
    // cin >> M;
    // vector<int> answer;

    // for(int i=0;i<M;i++){

    //     string s;
    //     cin >> s;

    //     if(s == "add"){
    //         int e1,e2;
    //         cin >> e1 >> e2;
    //         proList.insert({e1,e2});
    //         noCompList.insert({e1,e2});
    //     } else if(s == "recommend"){
    //         int e1;
    //         cin >> e1;
    //         if(e1 == 1){
    //             priority_queue<int> pq = {};
    //             int e = prev(proList.end())->second;
    //             pq.push(prev(proList.end())->first);
    //             auto j = prev(prev(proList.end()));
    //             while(e == j->second){
    //                 pq.push(j->first);
    //                 j = prev(j);
    //             }
    //             answer.push_back(pq.top());
    //         } else {
    //             priority_queue<int,vector<int>,greater<int>> pq = {};
    //             int e = proList.begin()->second;
    //             pq.push(proList.begin()->first);
    //             auto j = next(proList.begin());
    //             while(e == j->second){
    //                 pq.push(j->first);
    //                 j = next(j);
    //             }
    //             answer.push_back(pq.top());
    //         }
    //     } else {
    //         int e1;
    //         cin >> e1;
    //         auto j = proList.lower_bound({e1,noCompList[e1]});
    //         proList.erase(*j);
    //         noCompList.erase(noCompList[e1]);
    //     }

    // for(auto i:answer){
    //     cout << i << "\n";
    // }

    int N; // (https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x16/solutions/21939.cpp) 참고 버전
    cin >> N;
    int probLevel[1000001]; // 해당 문제번호가 몇 난이도인지
    set<int> probByLevel[101]; // 해당 난이도에 문제번호가 무엇이 있는지

    for(int i=0;i<N;i++){
        int P,L;
        cin >> P >> L;
        probLevel[P] = L;
        probByLevel[L].insert(P);
    }

    int M;
    cin >> M;
    vector<int> answer;
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