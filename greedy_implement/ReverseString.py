# 이코테 문제 : 문자열 뒤집기

S = input()

before = S[0]
count = 1
for now in S[1::]:
  if before != now:
    count += 1
  before = now
print(count//2)