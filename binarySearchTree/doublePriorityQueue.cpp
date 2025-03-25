// 백준 문제 : 이중 우선순위 큐

#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int k[T];

    string answer[T];
    for(int i=0;i<T;i++){
        cin >> k[i];
        multiset<int> dpq = {};
        for(int j=0;j<k[i];j++){
            char c;
            cin >> c;
            int n;
            cin >> n;
            if(c == 'I'){
                dpq.insert(n);
            } else {
                if(n == 1){
                    if(!dpq.empty()){
                        dpq.erase(prev(dpq.end()),dpq.end()); // rbegin()은 reverse iterator를 반환, 여기에 base()를 사용해주면 정상 iterator로 전환 가능
                    }
                } else {
                    if(!dpq.empty()){
                        dpq.erase(dpq.begin(),next(dpq.begin()));
                    }
                }
            }
        }
        if(dpq.empty()){
            answer[i] = "EMPTY\n";
        } else {
            answer[i] = to_string(*dpq.rbegin()) + " " + to_string(*dpq.begin()) + "\n";
        }
    }

    for(auto i:answer){
        cout << i;
    }
}
