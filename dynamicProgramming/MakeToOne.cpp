// 백준 문제 : 1로 만들기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mins(1000001,1000001);

int make(int n){
    if(n==1){
        return 0;
    } else {
        if(mins[n] != 1000001){
            return mins[n];
        }

        int m1 = 1000001;
        int m2 = 1000001;
        int m3 = 1000001;
        if(n % 3 == 0){
            m1 = 1+make(n/3);
        }
        if(n%2 == 0){
            m2 = 1+make(n/2);
        }
        m3 = 1+make(n-1);
        // cout << m1 <<" "<< m2 <<" " << m3 << " " << n << "\n";
        int answer = min(m1,min(m2,m3));
        mins[n] = answer;
        return answer;
    }

}

int main(){
    int N;
    cin >> N;

    cout << make(N) << "\n";
}