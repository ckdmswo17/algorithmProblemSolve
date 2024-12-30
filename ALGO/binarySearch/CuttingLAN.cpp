// 백준 문제 : 랜선 자르기

#include <iostream>

using namespace std;

int k, n;
int arr[10001];

bool solve(long long x){
    long long cur = 0;
    for(int i=0;i<k;i++){
       cur += arr[i]/x; 
    }
    return cur >= n;
}

int main(){
    cin.tie(0);
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }

    long long en = 0x7fffffff; // 2^31-1
    long long st = 0;
    while(st < en){
        long long mid = (st+en+1)/2;
        if(solve(mid)){
            st = mid;
        } else {
            en = mid-1;
        }
    }
    cout << st << endl;
}