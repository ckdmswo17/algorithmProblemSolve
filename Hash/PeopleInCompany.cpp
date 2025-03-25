// 백준 문제 : 회사에 있는 사람

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_set<string> people;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        if(s2 == "enter"){
            people.insert(s1);
        } else {
            people.erase(s1);
        }
    }

    set<string,greater<string>> answer(people.begin(),people.end());
    // vector<string> answer;
    // for(const auto& i:people){
    //     answer.push_back(i);
    // }
    // sort(answer.begin(),answer.end(),greater<string>());
    for(auto i:answer){
        cout << i << "\n";
    }
}