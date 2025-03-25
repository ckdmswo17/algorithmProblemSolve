// 백준 문제 : 비밀번호 찾기

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    unordered_map<string,string> site;
    for(int i=0;i<N;i++){
        string s1,s2;
        cin >> s1 >> s2;
        site.insert({s1,s2});
    }

    vector<string> findSite;
    for(int i=0;i<M;i++){
        string s1;
        cin >> s1;
        findSite.push_back(s1);
    }

    for(auto i:findSite){
        auto j = site.find(i);
        cout << j->second << "\n";
    }
}