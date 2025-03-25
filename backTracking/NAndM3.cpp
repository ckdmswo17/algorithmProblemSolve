// 백준 문제 : N과 M (3)

#include <iostream>

using namespace std;

int N,M;
int arr[8];

void p(int count){ // 중복을 허용하므로 isUsed 배열이 필요없음
    if(count == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1;i<N+1;i++){
        arr[count] = i;
        p(count+1);
    }
}

int main(){
    cin >> N >> M;  
    
    p(0);
}
