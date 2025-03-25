// 삼성 대학생 동계방학 코테 특강 문제 : [사전 문제] AI의 반란 최후의 전쟁, 테스트 정답률 89퍼로 실패

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        int sum = 0;
        vector<vector<int>> extinction(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
        	int a;
        	int b;
        	int c;
			cin >> a >> b >> c;
            
            extinction[i][0] = b+c;
            extinction[i][1] = a+c;
            extinction[i][2] = a+b;
            // cout << extinction[i][0] << extinction[i][1] << extinction[i][2] << endl;
        }
        // cout << ".1" << endl;

        bool checked[3] = {false, false, false};
        int count = 0;
        for(int z=0;z<n;z++){
			//auto minIt = min_element(extinction.begin(),extinction.end());
            //int minValue = min_element(extinction.begin(),extinction.end());
            pair<int, int> minIndex(-1,-1);
            int otherMaxValue = 0; 
            int minValue = 10000000;
            
            // cout << "=====================" << endl;
            // for(int i=0;i<extinction.size();i++){
            //     for(int j=0;j<3;j++){
            //         cout << extinction[i][j] << " ";
            //     }
            //     cout << endl;
            // }
             
            
            
            for(int i=0;i<extinction.size();i++){
            	for(int j=0;j<3;j++){
                	if(extinction[i][j] < minValue){
                        if(checked[j] && count < 3){
                        	continue;
                        }
                    	minValue = extinction[i][j];
                        minIndex = {i,j};
                        otherMaxValue = extinction[i][(j+1)%3] + extinction[i][(j+2)%3]; // 만약 다른걸 골랐을때의 손실을 계산하기위해, 나머지 두 값의 합을 계산
                    } else if(extinction[i][j] == minValue && minIndex.second == j ) {
                        if(checked[j] && count < 3){
                        	continue;
                        }
                        if(otherMaxValue < extinction[i][(j+1)%3] + extinction[i][(j+2)%3]){
                            otherMaxValue = extinction[i][(j+1)%3] + extinction[i][(j+2)%3];
                            minIndex = {i,j};
                        }
                    }
                }
            }
            
            checked[minIndex.second] = true;
            sum += minValue;
            // cout << "{"<<minIndex.first <<"," << minIndex.second << "} "<<minValue << endl;
            extinction.erase(extinction.begin()+minIndex.first);
            if(count < 3){
            	count += 1;
            }    
        }
        if(count < 3){
            cout << "#" <<test_case << " " << -1 << endl;
        } else {
            cout << "#" <<test_case << " " << sum << endl;
        }
		
        
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}