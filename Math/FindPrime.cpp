// 백준 문제 : 소수 찾기

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int nums[N];
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }

    int answer = 0;
    for(auto i:nums){
        if(i == 1){
            continue;
        }
        int count = 0;
        for(int j=1;j<=i;j++){
            if(i%j == 0){
                count += 1;
            }
        }
        if(count == 2){
            answer += 1;
        }
    }

    cout << answer << "\n";
}