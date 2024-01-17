// 이코테 문제 : 거스름돈

#include <iostream>

using namespace std;

int main(){
    int N;
    int coin[4] = {500, 100, 50, 10};
    cin >> N;
    int count = 0;

    for(int i=0;i<4;i++){
        count += N/coin[i];
        N %= coin[i];
        if(N == 0){
            break;
        }
    }
    cout << count << "\n";
}