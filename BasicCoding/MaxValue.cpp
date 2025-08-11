// 백준 문제 : 최댓값

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e;
    int maxNum = -1;
    int maxIndex = 1;
    for(int i=1;i<=9;i++){
        cin >> e;
        if(maxNum < e){
            maxNum = e;
            maxIndex = i;
        }
    }
    cout << maxNum << "\n" << maxIndex << "\n";
}