// 백준 문제 : 수 찾기 (이진탐색으로 찾았지만 맵으로 중복검사해서 찾는 방법도 가능할듯)

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    stable_sort(A,A+N);
    
    int M;
    cin >> M;
    int Ms[M];
    for(int i=0;i<M;i++){
        cin >> Ms[i];
    }

    for(int i=0;i<M;i++){
        int left = 0;
        int right = M-1;
        int center = (left+right)/2;
        while(right >= left){
            if(Ms[i] > A[center]){
                left = center+1;
                center = (left+right)/2;
            } else if(Ms[i] < A[center]){
                right = center-1;
                center = (left+right)/2;
            } else {
                cout << "1\n";
                break;
            }
            if(right<left){
                cout << "0\n";
                break;
            }
        }
    }
}