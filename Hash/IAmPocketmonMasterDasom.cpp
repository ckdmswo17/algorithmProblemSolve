// 백준 문제 : 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    unordered_map<string,int> dogam_name;
    unordered_map<int,string> dogam_num;
    for(int i=0;i<N;i++){
        string e;
        cin >> e;
        dogam_name.insert({e,i+1});
        dogam_num.insert({i+1,e});
    }

    string problems[M];
    for(int i=0;i<M;i++){
        cin >> problems[i];
    }

    for(int i=0;i<M;i++){
        bool isAllDigit = true;
        for(auto j:problems[i]){
            if(!isdigit(j)){
                isAllDigit = false;
            }
        }
        if(isAllDigit){
            cout << dogam_num.find(stoi(problems[i]))->second << "\n";
        } else {
            cout << dogam_name.find(problems[i])->second << "\n";
        }
    }
}