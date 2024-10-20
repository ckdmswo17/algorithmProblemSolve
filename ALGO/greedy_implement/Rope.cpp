// 백준 문제 : 로프

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int N;
    cin >> N;

    int weights[N];
    for(int i=0;i<N;i++){
        cin >> weights[i];
    }

    stable_sort(weights,weights+N,greater<>()); // 내림차순 정렬

    int answer = 0;
    for(int i=N;i>0;i--){ // N부터 1까지 로프의 개수를 i로 반복함. 내림차순 정렬을 했기때문에 현재 반복에서 최대 무게를 결정하는 건 가장 작은 i-1 인덱스의 로프임. 즉 현재 반복에서 최대 무게는 weights[i-1] * i임. 이렇게 계속 반복하면서 무게들의 최대값을 찾으면됨.
        int w = weights[i-1]*i;
        if(w > answer){
            answer = w;
        }
    }
    cout << answer << "\n";
}