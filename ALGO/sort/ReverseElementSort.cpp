// 백준 문제 : 역원소 정렬

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    long long newArr[n];
    for(int i=0;i<n;i++){
        long long divide = arr[i];
        long long remain;
        string reverseString = "";
        while(divide != 0){
            remain = divide%10;
            divide /= 10;
            reverseString += to_string(remain);
        }

        newArr[i] = stoll(reverseString);
    }

    sort(newArr,newArr+n);
    for(int i=0;i<n;i++){
        cout << newArr[i] << "\n";
    }
}