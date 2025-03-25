// 백준 문제 : 빈도 정렬

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second > p2.second; // 내림차순
}

int main(){
    int N,C;
    cin >> N >> C;

    int msg[N];
    for(int i=0;i<N;i++){
        cin >> msg[i];
    }

    vector<pair<int,int>> frequency;
    for(int i=0;i<N;i++){
        int e = msg[i];
        auto it = find_if(frequency.begin(),frequency.end(),[&e](const auto& p){return p.first == e;});
        if(it == frequency.end()){
            frequency.push_back({e,1});
        } else {
            it->second += 1;
        }
    }
    stable_sort(frequency.begin(),frequency.end(),compare); // sort: 3%에서 틀림 -> stable_sort : 정답 (이유는 아마 우선순위가 동일한 값 사이에서 sort는 원래 순서를 유지해주지 않기때문으로 유추)

    for(int i=0;i<frequency.size();i++){
        for(int j=0;j<frequency[i].second;j++){
            cout << frequency[i].first << " ";
        }
    }
    cout << "\n";
}