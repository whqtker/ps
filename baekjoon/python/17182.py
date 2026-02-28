import sys

input=sys.stdin.readline

n,k=map(int,input().split())

graph=[list(map(int,input().split())) for _ in range(n)]

for mid in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j]=min(graph[i][j],graph[i][mid]+graph[mid][j])

ans=sys.maxsize
visited=[0]*n

def dfs(cur,cnt,dist):
    global ans

    if dist>=ans:
        return

    if cnt==n:
        ans=min(ans,dist)
        return
    
    for i in range(n):
        if not visited[i]:
            visited[i]=1

            dfs(i,cnt+1,dist+graph[cur][i])

            visited[i]=0

visited[k]=1
dfs(k,1,0)

print(ans)