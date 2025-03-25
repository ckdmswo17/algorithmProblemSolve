// 백준 문제 : 행렬 제곱 / 재귀 + 메모이제이션 방법은 시간초과로 실패 / https://heespace.tistory.com/15 참고해서 반복문 방법으로 해결

// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <algorithm>
// #include <iterator>
// #include <climits>

// using namespace std;

// unsigned long long N,B;
// vector<vector<unsigned long long> > matrix; // (N,vector<unsigned long long>(N,0)) ;


// vector<string> split(const string& str) {
//     istringstream iss(str);
//     vector<string> result;

//     for (string s; iss >> s; ) {
//         result.push_back(s);
//     }

//     return result;
// }

// vector<vector<unsigned long long> > getMatrix(unsigned long long pow,vector<vector<vector<unsigned long long> >>& tmp) {
//     // cout << "pow : " << pow << endl;
//     // cout << tmp[pow].size() << endl;
//     // cout << "before seg" << endl;
//     if(tmp[pow].size()==N){
//         // for(int i=0;i<N;i++){
//         //     for(int j=0;j<N;j++){
//         //         cout << tmp[pow][i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         // cout << "not empty" << endl;
//         return tmp[pow];
//     }
//     // cout << "after seg" << endl;
//     if(pow == 1 & tmp[pow].size() == 0){
//         // cout << "push 1" << endl;
//         tmp[pow] = matrix;
//         return matrix;
//     }

//     vector<vector<unsigned long long> > result;
//     if(pow % 2 == 0){
//         vector<vector<unsigned long long> > first = getMatrix(pow/2,tmp);
//         vector<vector<unsigned long long> > second = getMatrix(pow/2,tmp);
//         for(int i=0;i<N;i++){
//             vector<unsigned long long> result2;
//             for(int j=0;j<N;j++){
                
//                 unsigned long long sum = 0;
//                 for(int z=0;z<N;z++){
//                     sum += first[i][z] * second[z][j];
//                 }
//                 // cout << sum << " ";
//                 result2.push_back(sum);
//             }
//             // cout << endl;
//             if(tmp[pow].size()!=N){
//                     // cout << "push!" << endl;
//                     tmp[pow].push_back(result2);
//             }
//             result.push_back(result2);
//         }
//     } else {
//         vector<vector<unsigned long long> > first = getMatrix(pow/2,tmp);
//         vector<vector<unsigned long long> > second = getMatrix(pow/2,tmp);
//         vector<vector<unsigned long long> > third;
//         for(int i=0;i<N;i++){
//             vector<unsigned long long> result2;
//             for(int j=0;j<N;j++){
//                 unsigned long long sum = 0;
//                 for(int z=0;z<N;z++){
//                     sum += first[i][z] * second[z][j];
//                 }
//                 result2.push_back(sum);
                
//             }
//             third.push_back(result2);
//         }
//         for(int i=0;i<N;i++){
//             vector<unsigned long long> result2;
//             for(int j=0;j<N;j++){
//                 unsigned long long sum = 0;
//                 for(int z=0;z<N;z++){
//                     sum += third[i][z] * matrix[z][j];
//                 }
//                 // cout << sum << " ";
//                 result2.push_back(sum);
                
//             }
//             // cout << endl;
//             if(tmp[pow].size()!=N){
//                 // cout << "push!" << endl;
//                 tmp[pow].push_back(result2);
//             }
//             result.push_back(result2);
//         }

//     }

//     return result;
// }

// int main() {
//     // cout << __LONG_LONG_MAX__ << endl;
//     cin >> N >> B;
//     // cout << N << " " << B << endl;
//     vector<vector<vector<unsigned long long>> > tmp(B+1);
    
//     cin.ignore();
//     for(int i=0;i<N;i++){
//         string sentence;
//         getline(cin,sentence);
//         vector<string> a = split(sentence);
//         vector<unsigned long long> b;
//         // cout << i << endl;
//         for(int j=0;j<N;j++){
//             b.push_back(stoll(a[j]));
//         }
//         matrix.push_back(b);
//     }
//     // cout << "s" << endl;

//     vector<vector<unsigned long long> > result = getMatrix(B,tmp);
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             cout << result[i][j]%1000 << " ";
//         }
//         cout << endl;
//     }
// }


#include <iostream>

using namespace std;

long long N,B;
long long a[5][5];
long long ans[5][5];
long long tmp[5][5];

void multiMatrix(long long first[5][5], long long second[5][5] ){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmp[i][j] = 0;
            for(int z=0;z<N;z++){
                tmp[i][j] += first[i][z] * second[z][j];
            }
            tmp[i][j] %= 1000;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            first[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> N >> B;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }

    while(B > 0){
        if(B % 2 == 1){
            multiMatrix(ans,a);
        }
        multiMatrix(a,a);
        B /= 2;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << ans[i][j]%1000 << " ";
        }
        cout << endl;
    }
    return 0;

}