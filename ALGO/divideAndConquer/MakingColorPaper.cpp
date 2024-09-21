// 백준 문제 : 색종이 만들기

#include <iostream>

using namespace std;

int N;
int paper[128][128];
int answer0 = 0;
int answer1 = 0;

void cut(int startY, int startX, int paperLength){
    int startElement = paper[startY][startX];
    bool notEqual = false;
    for(int i=startY;i<=startY+paperLength-1;i++){
        for(int j=startX;j<=startX+paperLength-1;j++){
            if(startElement != paper[i][j]){
                notEqual = true;
                break;
            }
        }
        if(notEqual){
            break;
        }
    }

    if(notEqual){ // 2중 for문 순서대로
        paperLength /= 2;

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cut(startY+paperLength*i,startX+paperLength*j,paperLength);
            }
        }

        return;
    } else {
        switch (startElement){
            case 0:
                answer0 += 1;
                break;
            case 1:
                answer1 += 1;
                break;
        }
        return;
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> paper[i][j];
        }
    }

    cut(0,0,N);
    cout << answer0 << "\n" << answer1 << "\n";
    return 0;
}