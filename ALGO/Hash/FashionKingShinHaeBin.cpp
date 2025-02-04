// 백준 문제 : 패션왕 신해빈 (next_permutation 이용시 시간초과)

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int n[T];
    int answer[T];
    for(int i=0;i<T;i++){
        unordered_map<string,int> clothes = {};
        answer[i] = 1;
        cin >> n[i];
        for(int j=0;j<n[i];j++){
            string s1,s2;
            cin >> s1 >> s2;
            auto it = clothes.find(s2);
            if(it != clothes.end()){
                it->second += 1;
            } else {
                clothes.insert({s2,1});
            }
        }

        for(auto j:clothes){
            answer[i] *= (j.second + 1); // 같은 종류의 옷에선 기존의 경우의 수와, 그 종류의 옷을 안 입는 경우의 수(+1)가 존재
        }
    }

    for(int i=0;i<T;i++){
        cout << answer[i]-1 << "\n"; // 알몸인 경우의 수(-1) 제외
    }

}