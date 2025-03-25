// 백준 문제 : 좌표 압축

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    int nums[N];
    int sortedNums[N];
    for(int i=0;i<N;i++){
        cin >> nums[i];
        sortedNums[i] = nums[i];
    }

    stable_sort(sortedNums,sortedNums+N);
    int steps[N];
    int step = 0;
    int beforeNum = sortedNums[0];
    for(int i=0;i<N;i++){
        if(beforeNum != sortedNums[i]){
            step += 1;
            beforeNum = sortedNums[i];
            steps[i] = step;
        } else {
            steps[i] = step;
        }
    }

    for(int i=0;i<N;i++){
        int left = 0;
        int right = N-1;
        int mid = (left+right)/2;
        while(left <= right){
            if(nums[i] > sortedNums[mid]){
                left = mid+1;
                mid = (left+right)/2;
            } else if(nums[i] < sortedNums[mid]){
                right = mid-1;
                mid = (left+right)/2;
            } else {
                cout << steps[mid] << " ";
                break;
            }
        }
    }
    cout << "\n";
}

