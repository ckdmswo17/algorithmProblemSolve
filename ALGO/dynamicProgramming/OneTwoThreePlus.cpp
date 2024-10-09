// 백준 문제 : 1, 2, 3 더하기

#include <iostream>
#include <vector>

using namespace std;

vector<int> cases(12,0);

int make(int n){
    if(n == 0){
        return 1;
    } else if(n < 0){
        return 0;
    }
    
    if(cases[n] != 0){
        return cases[n];
    }
    
    int answer = make(n-3)+make(n-2)+make(n-1);
    cases[n] = answer;
    return answer;
}

int main(){
    int T;
    cin >> T;
    
    int nums[T];
    for(int i=0;i<T;i++){
        cin >> nums[i];
    }
    
    for(int i=0;i<T;i++){
        cout << make(nums[i]) << "\n";
    }

    // for(int i=0;i<12;i++){
    //     cout << cases[i] << "\n" ;
    // }
}