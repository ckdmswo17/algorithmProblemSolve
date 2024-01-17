# 이코테 문제 : 럭키 스트레이트
N = input()
leng = len(N)

prag1 = N[:leng//2]
prag2 = N[leng//2:]
print(prag1, prag2)

sum1 = 0
for i in prag1:
    sum1 += int(i)

sum2 = 0
for i in prag2:
    sum2 += int(i)

if sum1 == sum2:
    print("LUCKY")
else :
    print("READY")