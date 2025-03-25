// 백준 문제 : 평범한 배낭 / 재귀 방법은 시간초과 / 피보나치 형태로 해결 (참고 : https://nanyoungkim.tistory.com/182)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int getValue(vector<pair <int,int>> items,int curWeight,int curIndex){

//     int maxValue = 0;
//     int curValue;
//     if(curIndex == -1){
//         curValue = 0;
//     } else {
//         curValue = items[curIndex].second;
//     }

//     for(int i=curIndex+1;i<items.size();i++){
        
//         if(curWeight - items[i].first >= 0){
//             if(curIndex == -1){
//                 curValue = getValue(items,curWeight - items[i].first,i);
//             } else {
//                 curValue = items[curIndex].second + getValue(items,curWeight - items[i].first,i);
//             }
//         }
//         if(maxValue < curValue){
//             maxValue = curValue;
//         }
//     }
//     if(maxValue < curValue){
//         maxValue = curValue;
//     }
//     return maxValue;
// }

int N,K;
int W[101] = {0};
int V[101] = {0};
int DP[101][100001] = {0};

void dp(){
    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            if(W[j] <= i){
                DP[j][i] = max(DP[j-1][i-W[j]]+V[j],DP[j-1][i]);
            } else {
                DP[j][i] = DP[j-1][i];
            }
        }
    }
}

int main(){
    cin >> N >> K;
    // vector<pair <int,int>> items;
    for(int i=1;i<=N;i++){
        cin >> W[i] >> V[i];
        // items.push_back({W,V});
    }

    dp();
    cout << DP[N][K] << endl;
    return 0;
    // sort(items.rbegin(),items.rend()); // 무게를 기준으로 내림차순 정렬
    // for(int i=0;i<N;i++){
    //     cout << items[i].first << "}" << items[i].second << endl;  
    // }

    // cout << getValue(items,K,-1) << endl;
}