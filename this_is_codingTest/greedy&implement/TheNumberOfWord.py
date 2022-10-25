# 백준 문제 : 단어의 개수

if __name__ == "__main__":
    words = list(input().split(" "))
    count = 0
    for i in words:
        if i == "":
            count += 1
    print(len(words)-count)