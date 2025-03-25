// 백준 문제 : 홍익 투어리스트

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,Q;
    cin >> N >> Q;

    set<int> hp;
    for(int i=0;i<N;i++){
        int e;
        cin >> e;
        if(e == 1){
            hp.insert(i);
        }
    }

    int currentLocation = 0;
    for(int i=0;i<Q;i++){
        // cout << currentLocation << " : ";
        // for(auto z:hp){
        //     cout << z << " ";
        // }
        // cout << "\n";
        int q1;
        cin >> q1;
        if(q1 != 3){
            int q2;
            cin >> q2;
            if(q1 == 1){
                auto j = hp.find(q2-1);
                if(j == hp.end()){
                    hp.insert(q2-1);
                } else {
                    hp.erase(q2-1);
                }
            } else {
                currentLocation = (currentLocation+q2)%N;
            }
        } else {
            if(hp.empty()){
                cout << -1 << "\n";
            } else {
                auto j = hp.lower_bound(currentLocation); // <algorithm>의 lower_bound는 이진탐색을 기반으로 해서 시간초과의 위험이 있음
                if(j == hp.end()){
                    cout << (N-1)-currentLocation+(*hp.begin()+1) << "\n";
                } else {
                    cout << *j-currentLocation << "\n";
                }
            }
        }
    }
}