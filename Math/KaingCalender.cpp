// 백준 문제 : 카잉 달력 (https://hagisilecoding.tistory.com/115 참고)

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    int M[T],N[T],x[T],y[T];
    for(int i=0;i<T;i++){
        cin >> M[i] >> N[i] >> x[i] >> y[i];
    }

    for(int i=0;i<T;i++){
        // int g = get<1>(xGCD(M[i],-N[i])); // 중국인의 나머지정리로 풀어볼려했으나 이 문제에 어떻게 적용할지 모르겠음
        // int e = M[i]*N[i];
        // int f = M[i]*invNum*(y[i]-x[i])+x[i];
        // cout << M[i] << " " << g << " " << x[i]  << "\n";
        // int answer = M[i]*g+x[i];
        // if(answer > lcm(M[i],N[i])){
        //     cout << -1 << "\n";
        // } else {
        //     cout << answer << "\n";
        // }

        int lcmNum = lcm(M[i],N[i]);
        vector<int> mNum;
        int e = x[i]; 
        while(e <= lcmNum){
            mNum.push_back(e);
            e += M[i];
        }

        int answer = -1;
        for(auto j:mNum){
            int jn = j % N[i];
            if(jn == 0){
                jn = N[i];
            }
            if(jn == y[i]){
                answer = j;
            }
        }
        cout << answer << "\n";
    }
}