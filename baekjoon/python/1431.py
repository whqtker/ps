import sys

input=sys.stdin.readline

n=int(input())
list=[input().strip() for _ in range(n)]

def sum(str:str):
    ret=0
    for s in str:
        if s.isdecimal():
            ret+=int(s)

    return ret

list.sort(key=lambda x:(len(x),sum(x),x))

for l in list:
    print(l)