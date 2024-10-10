// 백준 문제 : 구간 합 구하기 4

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int nums[N+1];
    for(int i=1;i<N+1;i++){
        cin >> nums[i];
    }

    vector<pair<int,int>> ijs(M+1,{0,0});
    for(int i=1;i<M+1;i++){
        int p1,p2;
        cin >> p1 >> p2;
        ijs[i] = {p1,p2};
    }

    int sums[N+1];
    sums[0] = 0;
    for(int i=1;i<N+1;i++){
        sums[i] = sums[i-1]+nums[i];
    }

    for(int i=1;i<M+1;i++){
        cout << sums[ijs[i].second]-sums[ijs[i].first-1] << "\n";
    }
}