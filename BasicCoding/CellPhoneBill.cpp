// 백준 문제 : 핸드폰 요금

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int time[N];
    for(int i=0;i<N;i++){
        cin >> time[i];
    }

    int yBill = 0;
    int mBill = 0;
    for(int i=0;i<N;i++){
        yBill += (time[i]/30+1)*10;
        mBill += (time[i]/60+1)*15;
    }

    if(yBill > mBill) cout << "M " << mBill << "\n";
    else if(mBill > yBill) cout << "Y " << yBill << "\n";
    else cout << "Y M " << yBill << "\n";
}