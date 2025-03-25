// 백준 문제 : 합이 0

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10002];

// int binarySearch(int start, int end, int n){
//     int mid;
//     int answer = -1;
//     while(start <= end){
//         mid = (start+end)/2;
//         if(n > arr[mid]){
//             start = mid+1;
//         } else if(n < arr[mid]){
//             end = mid-1;
//         } else {
//             answer = mid;
//             break;
//         }
//     }
//     return answer;
// }

int main(){

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    stable_sort(arr,arr+N);
    // for(int i=0;i<N;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    long long cnt = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            auto low = lower_bound(arr+j+1,arr+N,-(arr[i]+arr[j]));
            auto up = upper_bound(arr+j+1,arr+N,-(arr[i]+arr[j]));
            cnt += up - low;
            // cout << arr[i] << " " << arr[j] << " " << cnt << endl; 
        }
    }
    cout << cnt << endl;

}