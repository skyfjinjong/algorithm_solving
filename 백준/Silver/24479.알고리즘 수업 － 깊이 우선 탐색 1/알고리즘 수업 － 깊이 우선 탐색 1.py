import sys
sys.setrecursionlimit(10**6)

def dfs(x):
    global order
    visited[x] = order
    
    for node in graph[x]:
        if visited[node]==0:
            order += 1
            dfs(node)

if __name__ == "__main__":
    n, m, r = map(int, sys.stdin.readline().split())
    visited = [0 for i in range(n+1)]
    order = 1
    graph = dict()
    for i in range(1, n+1):
        graph[i] = []
    
    for i in range(m):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    for key, value in graph.items():
        value.sort()

    dfs(r)

    for i in range(1,n+1):
        print(visited[i])