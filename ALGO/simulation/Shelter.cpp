// 백준 문제 : 대피소 (2023 LIG넥스원 하반기 기출문제와 유사)

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<pair<int,int>> location(N,{0,0});
    for(int i=0;i<N;i++){
        cin >> location[i].first >> location[i].second;
    }

    vector<int> inloc;
    for(int i=0;i<K;i++){
        inloc.push_back(1);
    }
    for(int i=0;i<N-K;i++){
        inloc.push_back(0);
    }
    sort(inloc.begin(),inloc.end());

    int answer = 200000;
    int count = 0;
    do{
        int max = 0;
        for(int i=0;i<N;i++){
            if(inloc[i] != 1){
                int min = 200000;
                for(int j=0;j<inloc.size();j++){
                    if(inloc[j] == 1){
                        int distance = abs(location[i].first-location[j].first)+abs(location[i].second-location[j].second);
                        if(min > distance){
                            min = distance;
                        }
                        // cout << i << " " << j << " " << distance << " " << min << " "<< max << " " << answer <<  " "<< count<< "\n";
                    }
                }
                if(max < min){
                    max = min;
                }
            }
        }
        if(answer > max){
            answer = max;
        }
    } while(next_permutation(inloc.begin(),inloc.end()));

    cout << answer << "\n";
}