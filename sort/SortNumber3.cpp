// 백준 문제 : 수 정렬하기 3

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int counting[10001] = {0};
    int max = -1;
    for(int i=0;i<N;i++){
        int e;
        cin >> e;
        counting[e] += 1;
        if(max < e){
            max = e;
        }
    }

    for(int i=0;i<=max;i++){
        if(counting[i] != 0){
            for(int j=0;j<counting[i];j++){
                cout << i << "\n";
            }
        }
    }
}