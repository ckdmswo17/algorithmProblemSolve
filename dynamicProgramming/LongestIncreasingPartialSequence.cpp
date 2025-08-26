// 백준 문제 : 가장 긴 증가하는 부분 수열

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int A[N]; // 원본 배열
    int S[N]; // 인덱스 i까지의 최대 증가 부분 수열 원소 수

    for(int i=0;i<N;i++){
        cin >> A[i];
        S[i] = 1;
    }

    int ans = S[0];
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            // i로 각 원소 반복
            // j로 i보다 작을 동안 이전 원소 반복
            if(A[j] < A[i]) { // 두 요소가 증가하는 관계에 있을 때

                // 대소 비교해서 개수 배열에 저장 
                S[i] = max(S[i],S[j]+1); 

                if(ans < S[i]) {
                    ans = S[i];
                }
            }
        }
    }

    cout << ans << "\n";

}