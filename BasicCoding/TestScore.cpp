// 백준 문제 : 시험 성적

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score;
    cin >> score;
    cout << ((score>=90) ? "A" : ((score>=80) ? "B" : ((score >= 70) ? "C" : ((score >= 60) ? "D" : "F")))) << "\n"; 
}