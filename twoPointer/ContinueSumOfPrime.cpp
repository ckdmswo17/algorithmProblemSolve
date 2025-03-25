// 백준 문제 : 소수의 연속합

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> isPrime(4000001,true);
vector<int> primes;

int main(){
    cin >> N;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) { // 에라토스테네스의 체
        if (isPrime[i]) { // i가 소수라면
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false; // i의 배수들은 소수가 아님
            }
        }
    }

    for(int i=0;i<=N;i++){ 
        if(isPrime[i] == true){
            primes.push_back(i); 
        }
    }

    int start = 0;
    int end = 0;
    int answer = 0;
    int sum = 2;
    while(start < primes.size()&&end < primes.size()){
        if(sum == N){
            answer++;
        }

        if(sum >= N){
            sum -= primes[start];
            start++;
        } else {
            end++;
            sum += primes[end];  
        }
    }
    cout << answer << endl;
}
