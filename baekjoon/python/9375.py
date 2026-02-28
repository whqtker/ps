import sys
from collections import Counter

input=sys.stdin.readline

T=int(input())
for _ in range(T):
    n=int(input())

    cnts = Counter(input().split()[1] for _ in range(n))

    ans=1
    for cnt in cnts.values():
        ans*=(cnt+1)

    print(ans-1)