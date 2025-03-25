// 백준 문제 : 수 고르기

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    stable_sort(arr,arr+N);

    // 시간복잡도가 이중 for문과 거의 비슷하므로 좋은 코드는 X, 최적코드는 https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x14/solutions/2230.cpp 참고
    int start = 0;
    int mn = 0x7fffffff;
    for(int end=0;end<N;end++){
        if(arr[end] - arr[start] >= M){
            start = 0;
            while(arr[end] - arr[start] >= M){ 
                mn = min(mn,arr[end]-arr[start]);
                start++;
            }
        }
    }
    cout << mn << endl;

}