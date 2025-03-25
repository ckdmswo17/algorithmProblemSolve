// 백준 문제 : 과자 나눠주기 (랜선자르기와 거의 유사)

#include <iostream>

using namespace std;

int M,N;
int arr[1000000];

bool solve(int n){
    int cur = 0;
    for(int i=0;i<N;i++){
        cur += arr[i]/n;
    }
    return cur >= M;
}

int main(void){
    cin >> M >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int start = 0;
    int end = 1000000000;
    
    while(start < end){
        int mid = (start+end+1)/2; 
        // cout << start << " " << mid << " " << end << endl;
        if(solve(mid)){
            start = mid;
        } else {
            end = mid-1;
        }
    }
    cout << start << endl;
}