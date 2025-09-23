// 백준 문제 : 최소, 최대

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int numbers[N];
    for(int i=0;i<N;i++){
        cin >> numbers[i];
    }

    cout << *min_element(numbers,numbers+N) << " " << *max_element(numbers,numbers+N) << "\n"; 
}