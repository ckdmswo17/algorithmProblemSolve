// 이코테 문제 : 1이 될때까지
#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    int count = 0;
    while(N != 1)
    {
       if(N%K==0){ // 배수일때
           N /= K;
           count++;
       } else { // 배수아닐때
           N -= 1;
           count++;
       }
    }

    cout << count;
}