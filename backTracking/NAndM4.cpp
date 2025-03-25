// 백준 문제 : N과 M (4)

#include <iostream>

using namespace std;

int N,M;
int arr[8];

void p(int count){
    if(count == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1;i<N+1;i++){
        if(count > 0){
            if(arr[count-1] > i){
                continue;
            }
        }
        arr[count] = i;
        p(count+1);
    }
}

int main(){
    cin >> N >> M;  
    
    p(0);
}
