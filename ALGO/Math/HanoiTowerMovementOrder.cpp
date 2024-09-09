// 백준 문제 : 하노이 탑 이동 순서, 유튜브 참고

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<pair<int,int>> orders;


void hanoi(int disk,int start, int sup,int end){ 
    if(disk == 1){
        orders.push({start,end});
        return;
    } else {
        hanoi(disk-1,start,end,sup);
        orders.push({start,end});
        hanoi(disk-1,sup,start,end);
    }
}

int main(){
    cin >> N;
    hanoi(N,1,2,3);
    cout << orders.size() << "\n";
    while(!orders.empty()){
        pair p = orders.front(); orders.pop();
        cout << p.first << " " << p.second << "\n"; // endl이 시간초과 유발
    }
}