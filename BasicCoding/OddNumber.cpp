// 백준 문제 : 홀수

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int min = 100;
    for(int i=0;i<7;i++){
        int n;
        cin >> n;
        
        if(n%2 == 1){
            sum += n;
            if(min > n){
                min = n;
            }
        }
    }
    if(sum == 0){
        cout << -1;
    } else {
        cout << sum << endl << min;
    }
}