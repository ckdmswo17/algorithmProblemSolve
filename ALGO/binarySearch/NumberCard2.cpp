// 백준 문제 : 숫자 카드 2 (https://velog.io/@embeddedjune/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%9D%B4%EA%B2%83%EC%9D%B4-%EC%BD%94%EB%94%A9-%ED%85%8C%EC%8A%A4%ED%8A%B8%EB%8B%A4-%EC%9D%B4%EC%A7%84%ED%83%90%EC%83%89-Q27-%EC%A0%95%EB%A0%AC%EB%90%9C-%EB%B0%B0%EC%97%B4%EC%97%90%EC%84%9C-%ED%8A%B9%EC%A0%95-%EC%88%98%EC%9D%98-%EA%B0%9C%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0 참고)

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int Ns[N];
    for(int i=0;i<N;i++){
        cin >> Ns[i];
    }
    stable_sort(Ns,Ns+N);
    
    int M;
    cin >> M;
    int Ms[M];
    for(int i=0;i<M;i++){
        cin >> Ms[i];
    }

    for(int i=0;i<M;i++){
        // int* rightMost = upper_bound(Ns,Ns+N,Ms[i]); // algorithm 라이브러리 사용방법 
        // int* leftMost = lower_bound(Ns,Ns+N,Ms[i]);
        // cout << rightMost-leftMost << " ";

        int left = 0;
        int right = N-1;
        int center = (left+right)/2;
        int answer = 0;
        int leftMost = 0;
        int rightMost = -1;
        while(right >= left){
            // cout << i<<" "  << 1 << " "<<left << " " << center << " " << right << "\n";
            if((center == 0 || Ms[i] > Ns[center-1])&& Ms[i] == Ns[center]){
                leftMost = center;
                break;
            } else if(Ms[i] > Ns[center]){
                left = center+1;
                center = (left+right)/2;
            } else {
                right = center-1;
                center = (left+right)/2;
            }
        }

        left = 0;
        right = N-1;
        center = (left+right)/2;
        while(right >= left){
            // cout << i << " " << 2<<" " <<left << " " << center << " " << right << "\n";
            if((center == N-1 || Ms[i] < Ns[center+1])&& Ms[i] == Ns[center]){
                rightMost = center;
                break;
            } else if(Ms[i] >= Ns[center]){
                left = center+1;
                center = (left+right)/2;
            } else {
                right = center-1;
                center = (left+right)/2;
            }
        }
        cout << rightMost - leftMost + 1 << " ";
    }
    cout << "\n";
}