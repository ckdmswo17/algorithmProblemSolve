// 백준 문제 : 쿼드트리

#include <iostream>
#include <string>

using namespace std;

int N;
int video[64][64];

void zip(int startY, int startX, int videoLength){
    int startElement = video[startY][startX];
    bool notEqual = false;
    for(int i=startY;i<=startY+videoLength-1;i++){
        for(int j=startX;j<=startX+videoLength-1;j++){
            if(startElement != video[i][j]){
                notEqual = true;
                break;
            }
        }
        if(notEqual){
            break;
        }
    }

    if(notEqual){ // 2중 for문 순서대로
        videoLength /= 2;

        cout << "(";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                zip(startY+videoLength*i,startX+videoLength*j,videoLength);
            }
        }
        cout << ")";
        return;

    } else {
        switch (startElement){
            case 0:
                cout << "0";
                break;
            case 1:
                cout << "1";
                break;
        }
        return;
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<N;j++){
            video[i][j] = str[j]-'0';
        }
    }

    zip(0,0,N);
    cout << "\n";
    return 0;
}