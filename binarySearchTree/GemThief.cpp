// 백준 문제 : 보석 도둑

#include <iostream>
// #include <map>
// #include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    // map<int,int> gems;
    vector<pair<int,int>> gems;
    for(int i=0;i<N;i++){
        int e1,e2;
        cin >> e1 >> e2;
        // gems.insert({e1,e2});
        gems.push_back({e1,e2});
    }
    sort(gems.begin(),gems.end());

    // set<int> bags;
    vector<int> bags;
    for(int i=0;i<K;i++){
        int e1;
        cin >> e1;
        // bags.insert(e1);
        bags.push_back(e1);
    }
    sort(bags.begin(),bags.end());

    priority_queue<int> pq;
    long long answer = 0;
    int j = 0;
    for(auto i:bags){
        // cout << i << "\n";
        while(j < N && gems[j].first <= i){
            pq.push(gems[j].second);
            ++j;
        }
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer << "\n";

    
}