// 백준 문제 : 단어 정렬

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string i, string j){
    if(i.length() > j.length()){
        return true;
    } else if(i.length() == j.length()){
        if(i > j){
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;

    vector<string> words(N,"");
    for(int i=0;i<N;i++){
        cin >> words[i];
    }

    set<string> unique_rows;
    vector<string> result;

    for(int i=0;i<N;i++){ // 중복 제거
        const auto& e = words[i];
        if(unique_rows.insert(e).second){
            result.push_back(e);
        }
    }

    int newN = result.size();
    // for(int i=0;i<newN-1;i++){ // sort, O(n^2)로 시간초과 
    //     for(int j=i+1;j<newN;j++){
    //         if(result[i].length() > result[j].length()){
    //             string tmp = result[i];
    //             result[i] = result[j];
    //             result[j] = tmp;
    //         } else if(result[i].length() == result[j].length()){
    //             if(result[i] > result[j]){
    //                 string tmp = result[i];
    //                 result[i] = result[j];
    //                 result[j] = tmp;
    //             }
    //         }
    //     }
    // }
    sort(result.begin(),result.end(),compare); // O(nlogn)의 Intro Sort 사용
    reverse(result.begin(),result.end());

    for(int i=0;i<newN;i++){
        cout << result[i] << "\n";
    }
}