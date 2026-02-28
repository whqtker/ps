import sys
sys.setrecursionlimit(10**6)

input=sys.stdin.readline

n=int(input())
cnt=list(map(int,input().split()))

graph=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

dp=[[0,0] for _ in range(n+1)] # dp[i][0]: i를 우수 마을로 선정하지 않음, dp[i][1]: i를 우수 마을로 선정함

def dfs(cur,parent):
    dp[cur][0]=0
    dp[cur][1]=cnt[cur-1]

    for nxt in graph[cur]:
        if nxt==parent:
            continue

        dfs(nxt,cur)

        dp[cur][0]+=max(dp[nxt][1],dp[nxt][0])
        dp[cur][1]+=dp[nxt][0]

dfs(1,0)
print(max(dp[1][0],dp[1][1]))