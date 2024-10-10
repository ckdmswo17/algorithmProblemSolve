// 백준 문제 : 계단 오르기 (https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x10/solutions/2579.cpp 참고, 이 문제는 상향식 하향식 재귀로 풀수있는 문제가 아님, 올라가면서 동시에 하향값으로 채워야하는 문제)

#include <iostream>
#include <algorithm>

using namespace std;

int s;
int sumScores[301][2]; // 2차원의 0은 건너뛰었을때, 1은 이전거에서 넘어왔을 때
int scores[301];

int main(){
    cin >> s;

    for(int i=1;i<s+1;i++){
        cin >> scores[i];
    }

    sumScores[1][0] = scores[1];
    sumScores[1][1] = 0;
    sumScores[2][0] = scores[2];
    sumScores[2][1] = scores[1] + scores[2];
    for(int i =3;i<=s;i++){
        sumScores[i][0] = max(sumScores[i-2][0],sumScores[i-2][1])+scores[i];
        sumScores[i][1] = sumScores[i-1][0]+scores[i]; // 2차원 1번을 쓰면 이전의 횟수가 포함되면서 3 이상이 됨
    }
    cout << max(sumScores[s][0],sumScores[s][1]) << "\n";
}