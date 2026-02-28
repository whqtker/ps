from itertools import permutations
import sys

input=sys.stdin.readline

n,m=map(int,input().split())

list=[i+1 for i in range(n)]

iters=permutations(list,m)
ans=[" ".join(map(str,iter)) for iter in iters]

print("\n".join(ans))