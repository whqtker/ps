import sys
from bisect import bisect_left, bisect_right

input=sys.stdin.readline

n=int(input())
arr=list(map(int,input().split()))
arr.sort()

m=int(input())
find=list(map(int,input().split()))
for f in find:
    print(bisect_right(arr,f)-bisect_left(arr,f),end=' ')

