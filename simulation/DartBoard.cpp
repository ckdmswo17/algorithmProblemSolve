// 백준 문제 : 다트판

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score[20];
    for(int i=0;i<20;i++){
        cin >> score[i];
    }

    double aliceScore = 0;
    double BobScore = 0;
    for(int i=0;i<20;i++){
        if(score[i] == 20){
            aliceScore += score[i];
            // 20점의 왼쪽 점수
            if(i == 0){
                aliceScore += score[19];
            } else {
                aliceScore += score[i-1];
            }
            // 20점의 오른쪽 점수
            if(i == 19){
                aliceScore += score[0];
            } else {
                aliceScore += score[i+1];
            }
        }
        BobScore += score[i];
    }

    aliceScore /= 3;
    BobScore /= 20;
    if(aliceScore > BobScore){
        cout << "Alice\n";
    } else if(aliceScore < BobScore) {
        cout << "Bob\n";
    } else {
        cout << "Tie\n";
    }
}