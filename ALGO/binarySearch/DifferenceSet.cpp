// 백준 문제 : 차집합

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int nA,nB;
    cin >> nA >> nB;

    int A[nA];
    int B[nB];
    for(int i=0;i<nA;i++){
        cin >> A[i];
    }
    stable_sort(A,A+nA);

    for(int i=0;i<nB;i++){
        cin >> B[i];
    }
    stable_sort(B,B+nB);

    vector<int> notFoundElements;
    for(int i=0;i<nA;i++){
        int start = 0;
        int end = nB-1;
        int mid = (start+end)/2;
        bool isFind = false;
        while(start <= end){
            if(A[i] < B[mid]){
                end = mid-1;
            } else if(A[i] > B[mid]){
                start = mid+1;
            } else {
                isFind = true;
                break;
            }
            mid = (start+end)/2;
        }
        if(isFind == false){
            notFoundElements.push_back(A[i]);
        }
    }

    int vectorSize = notFoundElements.size();
    cout << vectorSize << endl;
    for(int i=0;i<vectorSize;i++){
        if(i==vectorSize-1){
            cout << notFoundElements[i] << endl;
        } else {
            cout << notFoundElements[i] << " ";
        }
    }
}