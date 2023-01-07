# 이코테 문제 : 공유기 설치 (미해결, 다른사람 코드 복붙)

import sys
from bisect import bisect_right, bisect_left

input = sys.stdin.readline
N, C = map(int,input().split(" "))
house = []
for i in range(N):
    house.append(int(input()))
house.sort()
# print(house)

start = 1
end = house[-1]-house[0]
result = 0
while start<=end: 
    mid = (start+end)//2
    index = 0
    count = 1
    # print(start,mid,end)
    for j in range(len(house)):
        # print(j,index)
        if (house[j] - house[index]) >= mid:
            # print("반복 :",house[j] - house[index],mid,"count :",count)
            index = j
            count +=1
    if count >= C:   
        result = mid
        start = mid+1
    else:
        end = mid-1
print(result)