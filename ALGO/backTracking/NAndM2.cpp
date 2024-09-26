// 백준 문제 : N과 M (2)

#include <iostream>
#include <vector>

using namespace std;

int N,M;
int arr[8];

void p(vector<bool> isUsed,int count){
    if(count == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1;i<N+1;i++){
        if(isUsed[i] == false){
            if(count > 0){ // 1번과 달라진 부분
                if(arr[count-1] > i){
                    continue;
                } else {
                    arr[count] = i;
                }
            } else {
                arr[count] = i;
            }
            isUsed[i] = true;
            p(isUsed,count+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    vector<bool> isUsed(N+1,false);    
    
    p(isUsed,0);
}