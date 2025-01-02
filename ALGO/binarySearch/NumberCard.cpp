// 백준 문제 : 숫자 카드

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    int nn[N];
    for(int i=0;i<N;i++){
        cin >> nn[i];
    }

    int M;
    cin >> M;
    int mm[M];
    for(int i=0;i<M;i++){
        cin >> mm[i];
    }

    stable_sort(nn,nn+N);
    // for(int i=0;i<N;i++){
    //     cout << nn[i] << " ";
    // }
    // cout << endl;

    for(int i=0;i<M;i++){
        int start = 0;
        int end = N-1;
        int mid = (start+end)/2;
        bool isFind = false;
        while(start <= end){
            if(mm[i] < nn[mid]){
                end = mid-1;
            } else if(mm[i] > nn[mid]){
                start = mid+1;
            } else {
                isFind = true; 
                break;
            }
            mid = (start+end)/2;
        }
        if(isFind == true){
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;
}