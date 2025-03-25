// 백준 문제 : 수들의 합 2

#include <iostream>

using namespace std;

int N,M;
int arr[10000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int sum = arr[0];
    int answer = 0;
    while(start < N&&end < N){ // start, end 둘 중 하나만 범위를 벗어나도 반복 종료
        // cout << start <<" "<< end <<" "<< sum << endl;
        if(sum == M){
            answer++;
        }

        if(sum >= M){
            sum -= arr[start];
            start++;
        } else if(sum < M){
            end++;
            sum += arr[end];  
        } 
    }
    cout << answer << endl;
}