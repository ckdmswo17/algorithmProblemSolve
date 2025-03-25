// 백준 문제 : N-Queen (https://tear94fall.github.io/lecture/2020/09/16/n-queen-problem.html 참고)

#include <iostream>

using namespace std;

int n, cnt=0;
int temp[15]={0}; // 인덱스가 x, 값이 y

void nqueen(int col){
    if(col==n){
        cnt+=1;
        return;
    }
	
    for(int i=0;i<n;i++){
        int check = true;
        for(int j=0;j<col;j++){ // 이전 체스말들 검사
            temp[col]=i;
            if(temp[j]==temp[col]||((j-col)==(temp[j]-temp[col]))||((j-col)==(temp[col]-temp[j]))){
                check = false;
                break;
            }
        }
		
        if(check){
            nqueen(col+1);
        }
    }
}

int main(void){
    cin >> n;
	
    for(int i=0;i<n;i++){
        temp[0]=i;
        nqueen(1);
    }

    cout << cnt << "\n";

    return 0;
}