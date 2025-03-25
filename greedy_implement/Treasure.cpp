// 백준 문제 : 보물

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    int B[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<N;i++){
        cin >> B[i];
    }

    stable_sort(B,B+N); 
    stable_sort(A,A+N,greater<>());

    int sum = 0;
    for(int i=0;i<N;i++){
        sum += A[i] * B[i];
    }
    cout << sum << "\n";

}