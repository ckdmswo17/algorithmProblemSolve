// 백준 문제 : 종이의 개수

#include <iostream>

using namespace std;

int N;
int paper[2187][2187];
int answer1 = 0;
int answer2 = 0;
int answer3 = 0;

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
        paperLength /= 3;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cut(startY+paperLength*i,startX+paperLength*j,paperLength);
            }
        }

        // cut(startY,startX,paperLength);
        // cut(startY,startX+paperLength,paperLength);
        // cut(startY,startX+paperLength*2,paperLength);
        // cut(startY+paperLength,startX,paperLength);
        // cut(startY+paperLength,startX+paperLength,paperLength);
        // cut(startY+paperLength,startX+paperLength*2,paperLength);
        // cut(startY+paperLength*2,startX,paperLength);
        // cut(startY+paperLength*2,startX+paperLength,paperLength);
        // cut(startY+paperLength*2,startX+paperLength*2,paperLength);

        return;
    } else {
        switch (startElement){
            case -1:
                answer1 += 1;
                break;
            case 0:
                answer2 += 1;
                break;
            case 1:
                answer3 += 1;
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
    cout << answer1 << "\n" << answer2 << "\n" << answer3 << "\n";
    return 0;
}