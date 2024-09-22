// 백준 문제 : N과 M

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
            isUsed[i] = true;
            arr[count] = i;
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
