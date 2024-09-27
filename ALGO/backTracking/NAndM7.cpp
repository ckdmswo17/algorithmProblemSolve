// 백준 문제 : N과 M (6)

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int nums[8];
int arr[8];

void p(int count){
    if(count == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<N;i++){
        arr[count] = nums[i];
        p(count+1);
    }
}

int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums,nums+N);
    p(0);
}
