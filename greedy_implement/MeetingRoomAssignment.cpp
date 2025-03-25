// 백준 문제 : 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool moreBig(pair<int,int> p1, pair<int,int> p2){ // second 오름차순으로, second가 같을시 first를 오름차순으로 정렬 compare
    if(p1.second > p2.second){
        return false;
    } else if(p1.second == p2.second){
        if(p1.first > p2.first){
            return false;
        } else {
            return true;
        }
    } else {
        return true;
    }
}

int main(){
    cin >> N;

    vector<pair<int,int>> time;
    for(int i=0;i<N;i++){
        int e1,e2;
        cin >> e1 >> e2;
        time.push_back({e1,e2});
    }

    int lastTime = 0;
    int answer = 0;
    int i = 0;
    stable_sort(time.begin(),time.end(),moreBig);
    while(i < time.size()){
        

        bool isFind = false;
        for(;i<time.size();i++){
            if(time[i].first >= lastTime){
                isFind = true;
                break;
            }
        }

        if(isFind == true){
            answer += 1;
            lastTime = time[i].second;
            i += 1;
        }
    }

    cout << answer << "\n";
}