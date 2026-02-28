import sys
from collections import deque

input=sys.stdin.readline

n,m=map(int,input().split())
list=[list(map(int,input().split()[1:])) for _ in range(m)]


inDegree=[0]*(n+1)
graph=[[] for _ in range(n+1)]
for pd in list:
    x=pd[0]
    for y in pd[1:]:
        inDegree[y]+=1
        graph[x].append(y)
        x=y

q=deque()
for i in range(1,n+1):
    if inDegree[i]==0:
        q.append(i)

ans=[]
for _ in range(n):
    if not q:
        print(0)
        exit()

    x=q.popleft()
    ans.append(x)

    for y in graph[x]:
        inDegree[y]-=1
        if inDegree[y]==0:
            q.append(y)

for a in ans:
    print(a)
