// 백준 문제 : N과 M (5)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int nums[8];
int arr[8];

void p(vector<bool> isUsed,int count){
    if(count == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<N;i++){
        if(isUsed[i] == false){
            isUsed[i] = true;
            arr[count] = nums[i];
            p(isUsed,count+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    vector<bool> isUsed(N,false);

    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums,nums+N);
    p(isUsed,0);
}
