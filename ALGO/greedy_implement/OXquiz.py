# 그냥 백준 문제 : OX퀴즈

n = int(input())
quiz = []
for i in range(n):
    quiz.append(input())

score = []
for i in range(n):
    sum = 0
    plusScore = 0
    for j in range(len(quiz[i])):
        if quiz[i][j]=='X':
            plusScore = 0
        else :
            plusScore += 1
            sum += plusScore
    score.append(sum)

for i in score:
    print(i)

# a = input()
