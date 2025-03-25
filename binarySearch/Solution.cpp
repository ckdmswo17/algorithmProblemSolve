// 백준 문제 : 용액

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[100000];

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    int start = 0;
    int end = N-1;
    int mn = 0x7fffffff;
    pair minSol = {-1,-1};
    while(start < end){
        int sum = arr[start]+arr[end];
        int absSum = abs(sum);
        // cout << arr[start] << " "<< arr[end] <<" " << sum<< endl;
        
        mn = min(mn,absSum);
        if(mn == absSum){
            minSol = {arr[start],arr[end]};
        }

        if(sum>0){
            end -= 1;
        } else if(sum<0){
            start += 1;
        } else {
            break;
        }
    }
    cout << minSol.first << " " << minSol.second << endl;
}