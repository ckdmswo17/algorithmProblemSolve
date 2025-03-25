# 이코테 문제 : 정렬된 배열에서 특정 수의 개수 구하기 (Zoho 인터뷰 출처)

from bisect import bisect_left,bisect_right

N, x = map(int,input().split(" "))
integer = list(map(int,input().split(" ")))

answer = bisect_right(integer,x) - bisect_left(integer,x)
if answer == 0:
    print(-1)
else :
    print(answer)