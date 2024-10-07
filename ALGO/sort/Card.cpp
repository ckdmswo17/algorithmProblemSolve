// 백준 문제 : 카드

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr,arr+N);
    // for(int i=0;i<N;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    int sum = 0;
    int sumMax = 0;
    long long maxElement = arr[0];
    long long curElement;
    long long beforeElement;
    for(int i=0;i<N;i++){
        curElement = arr[i];
        if(i >0){
            beforeElement = arr[i-1];
            if(curElement != beforeElement){
                if(sum > sumMax){
                    sumMax = sum;
                    maxElement = arr[i-1];
                } 
                sum = 0;
            } 
        }
        sum += 1;
        if(i == N-1){
            if(sum > sumMax){
                sumMax = sum;
                maxElement = arr[i];
            }
        }
    }

    cout << maxElement << "\n";
}