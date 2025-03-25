// 백준 문제 : 피보나치 함수

#include <iostream>

using namespace std;

// int fibonacci(int n) { // 문제에 제시된 함수
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }


int main(){
    int T;
    cin >> T;

    int nums[T];
    for(int i=0;i<T;i++){
        cin >> nums[i];
    }

    int d[41][2] = {0};

    // for(int i=0;i<40;i++){
    //     for(int j=0;j<2;j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i=0;i<T;i++){
        for(int j=2;j<=nums[i];j++){
            if(d[j][0] == 0 && d[j][1] == 0){
                d[j][0] = d[j-1][0] + d[j-2][0];
                d[j][1] = d[j-1][1] + d[j-2][1];
            }
        }
        cout << d[nums[i]][0] << " " << d[nums[i]][1] << "\n";
    }
}