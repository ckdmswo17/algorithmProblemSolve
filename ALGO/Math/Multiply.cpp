// 백준 문제 : 곱셈
#include <iostream>

using namespace std;

unsigned long long A,B,C;

unsigned long long multiply(unsigned long long pow){
    unsigned long long sum;
    if(pow == 0){
        return 1;
    }
    else if(pow == 1){
        // cout << A << endl;
        return A;
    } else {
        if(pow % 2 == 0){
            sum = multiply(pow/2) * multiply(pow/2);
            // cout << sum << endl;
            if(sum > C){
                sum %= C;
            }
            return sum;
        } else {
            sum = multiply(pow/2) * multiply(pow/2+1);
            // cout << sum << endl;
            if(sum > C){
                sum %= C;
            }
            return sum;  
        }
    }
}

int main(){
    cin >> A >> B >> C;

    unsigned long long answer = multiply(B);
    // cout << answer << endl;
    cout << answer%C << endl;
}