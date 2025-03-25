// 백준 문제 : 나무 자르기

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[1000000];

bool solve(int n){
    long long cur = 0;
    for(int i=0;i<N;i++){
        if(arr[i]-n > 0){
            cur += arr[i]-n;
        }
    }
    return cur>=M;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    stable_sort(arr,arr+N);

    int start = 0;
    int end = 1000000000; 
    while(start < end){
        int mid = (start+end+1)/2;
        if(solve(mid)){
            start = mid;
        } else {
            end = mid-1;
        }
    }
    cout << start << endl;
}