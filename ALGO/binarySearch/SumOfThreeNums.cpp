// 백준 문제 : 세 수의 합
// a[i] + a[j] + a[k] = a[l], a[i]+a[j]의 모든 경우의 수를 sum[i]으로 만들고 sum에서 a[l]-a[k]를 이분탐색, 이러면 N^2logN에 탐색 가능

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    int N;
    cin >> N;
    int nums[N];
    for(int i=0;i<N;i++){
        cin >>nums[i];
    }
    stable_sort(nums,nums+N);

    set<int> testS;
    vector<int> sums;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            int s = nums[i]+nums[j];
            if(testS.insert(s).second == true){
                sums.push_back(s);
            }
        }
    }
    stable_sort(sums.begin(),sums.end());

    for(int i=N-1;i>0;i--){
        for(int j=0;j<i;j++){
            int sum = nums[i]-nums[j];

            int left = 0;
            int right = sums.size()-1;
            int mid = (left+right)/2;
            while(left <= right){
                if(sum > sums[mid]){
                    left = mid+1;
                    mid = (left+right)/2;
                } else if(sum < sums[mid]){
                    right = mid-1;
                    mid = (left+right)/2;
                } else {
                    cout << nums[i] << "\n";
                    return 0;
                }
            }
        }
    }
}