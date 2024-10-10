// 백준 문제 : 1로 만들기 2 (https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x10/solutions/12852.cpp 참고)

#include <iostream>
// #include <algorithm>
// #include <vector>

using namespace std;

int minStep[1000001];
int pre[1000001];

// int make(int n,int count){ // 상향식 재귀
//     if(n==1){
//         return 0;
//     } else {
//         if(mins[n] != 1000001){
//             return mins[n];
//         }

//         int m1 = 1000001;
//         int m2 = 1000001;
//         int m3 = 1000001;
//         int step = 0;
//         if(n % 3 == 0){
//             m1 = 1+make(n/3,count+1);
//         }
//         if(n%2 == 0){
//             m2 = 1+make(n/2,count+1);
//         }
//         m3 = 1+make(n-1,count+1);

//         int answer = min(m1,min(m2,m3));
//         mins[n] = answer;
//         return answer;
//     }

// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    minStep[0] = 0;
    minStep[1] = 0;
    for(int i=2;i<N+1;i++){
        minStep[i] = minStep[i-1] + 1;
        pre[i] = i-1;
        if(i % 2 == 0 && minStep[i] > minStep[i/2]+1){
            minStep[i] = minStep[i/2]+1;
            pre[i] = i/2;
        }
        if(i % 3 == 0 && minStep[i] > minStep[i/3]+1){
            minStep[i] = minStep[i/3]+1;
            pre[i] = i/3;
        }
    }
    
    cout << minStep[N] << "\n";
    int cur = N;
    while(true){
        cout << cur << " ";
        if(cur == 1){
            break;
        }
        cur = pre[cur];
    }
    cout << "\n";
}