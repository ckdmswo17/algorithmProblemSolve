// 백준 문제 : 수강신청

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K,L;
    cin >> K >> L;
    unordered_map<string,int> studentNum;

    for(int i=0;i<L;i++){
        string e;
        cin >> e;
        
        if(studentNum.insert({e,i}).second == false){
            auto it = studentNum.find(e);
            it->second = i;
        }
    }

    vector<pair<string,int>> studentVec(studentNum.begin(),studentNum.end());
    stable_sort(studentVec.begin(),studentVec.end(),[](const auto &a, const auto &b){
        return a.second < b.second;
    });

    vector<string> answer;
    if(studentVec.size() > K){
        for(int i=0;i<K;i++){
            answer.push_back(studentVec[i].first);
        }
    } else {
        for(int i=0;i<studentVec.size();i++){
            answer.push_back(studentVec[i].first);
        }
    }

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << "\n";
    }
}