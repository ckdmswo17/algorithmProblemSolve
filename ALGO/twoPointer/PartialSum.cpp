// 백준 문제 : 부분합

#include <iostream>

using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    int arr[N];
    for(int i=0;i<N;i++)
    cin >> arr[i];
    
    int start = 0;
    int end = 0;
    int sum = arr[0];
    int answer = 0x7fffffff;
    while(end < N){
        // cout << sum;
        if(sum >= S){
            answer = min(answer,end+1-start);
            if(start == end){
                break;
            } else {
                sum -= arr[start];
                start += 1;
            }
        } else {
            sum += arr[++end];
        }
    }

    if(answer ==  0x7fffffff){
        cout << 0 << endl;
    } else {
        cout << answer << endl;
    }
}