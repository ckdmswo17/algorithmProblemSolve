// 백준 문제 : 윷놀이

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<3;i++){
        int zeroCnt = 0;
        for(int j=0;j<4;j++){
            int yut;
            cin >> yut;
            if(yut == 0){
                zeroCnt++;
            }
        }

        if(zeroCnt == 1){
            cout << "A\n";
        } else if(zeroCnt == 2){
            cout << "B\n";
        } else if(zeroCnt == 3){
            cout << "C\n";
        } else if(zeroCnt == 4){
            cout << "D\n";
        } else {
            cout << "E\n";
        }
    }
}
