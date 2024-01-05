// 이코테 문제 : 모험가 길드
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }
    sort(a,a+N);
    
    int group;
    int remain = 0;
    int count;
    int mainValue; // 현재 조사중인 값
    int curIndex = 0; // 현재 인덱스
    while(curIndex < N){
        count = remain; // 그룹에 끼지 못한 숫자들을 다음 숫자 개수에 이월
        mainValue = a[curIndex];
        
        for(;a[curIndex]==mainValue;curIndex++){
            count += 1;
        }
        group += count/mainValue;
        remain = count%mainValue;
    }
    
    cout << group;
}