import sys
import math

input=sys.stdin.readline

n=int(input())

ac=[]
bd=[]
for i in range(1,int(math.sqrt(n))+1):
    if n%i==0:
        ac.append((i,n//i))
        ac.append((n//i,i))

for i in range(1,int(math.sqrt(n+2))+1):
    if (n+2)%i==0:
        bd.append((-i,(n+2)//i))
        bd.append(((n+2)//i,-i))
        bd.append((i,-(n+2)//i))
        bd.append((-(n+2)//i,i))

for a,c in ac:
    for b,d in bd:
        if b*c+a*d==n+1:
            print(a,b,c,d)
            exit()

print(-1)
