// 백준 문제 : 연속합

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // s = 최대 부분 배열 (k일때 최대의 합을 기록)
    // k = 현재 인덱스
    // 점화식 : s[k] = max(s[k-1]+arr[k],arr[k])

    int s[n];
    s[0] = arr[0];
    int ans = arr[0];
    for(int i=1;i<n;i++){
        s[i] = max(s[i-1]+arr[i],arr[i]);
        ans = max(s[i],ans);
    }
    cout << ans << "\n";

}