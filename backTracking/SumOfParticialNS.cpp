// 백준 문제 : 부분수열의 합

#include <iostream>
#include <vector>

using namespace std;

int N,S;
int arr[20];
int answer = 0;

void p(vector<bool> isUsed, int beforeIndex, int sum){
    if(sum == S && beforeIndex >= 0){
        answer += 1;
    }

    for(int i=beforeIndex+1;i<N;i++){
        if(isUsed[i] == false){
            isUsed[i] = true;
            sum += arr[i];
            p(isUsed, i, sum);
            sum -= arr[i];
            isUsed[i] = false;
        }
    }
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<bool> isUsed(N,false);
    p(isUsed,-1,0);
    cout << answer << "\n";
}