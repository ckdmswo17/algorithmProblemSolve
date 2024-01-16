// 백준 문제 : 분수찾기

#include <iostream>

using namespace std;

int main(){
    int X;
    cin >> X;

    int fractions[1000][1000] = {0};
    bool direction = true; // 방향이 오른위라면 true, 왼아래라면 false
    int count = 1;
    int i = 0;
    int j = 0;
    while(count != X){
        // cout << i << " "<< j << endl;
        if(direction){
            if((0<=i-1) && (j+1 <1000)){
                i--;
                j++;
            } else if( j+1 <1000) {
                j++;
                direction = false;
            }
        } else {
            if((i+1<1000) && (0<= j-1)){
                i++;
                j--;
            } else if(i+1<1000) {
                i++;
                direction = true;
            }
        }
        count++;
    }
    cout << i+1 << "/" << j+1 << endl;

}