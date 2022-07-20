// 이코테 문제 : 시각
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int N;
    cin >> N;
    
    int all = 60 * 60 * (N+1);
    int notThree = 0;
    for(int i=0; i<=N;i++) {
        if(i % 10 != 3) { // 시간에 3이 없으면
            notThree += 5 * 9 * 5 * 9; // 
        }
    }
    int answer = all - notThree;
    cout << answer;
}