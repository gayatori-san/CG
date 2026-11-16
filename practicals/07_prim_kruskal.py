# Vertices: A=0, B=1, C=2, D=3, E=4
edges = [(0,1,2), (1,2,3), (0,3,6), (1,3,8), (1,4,5), (2,4,7)]
names = "ABCDE"

# Kruskal
parent = list(range(5))
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

print("KRUSKAL")
total = 0
for u, v, w in sorted(edges, key=lambda x: x[2]):
    a, b = find(u), find(v)
    if a != b:
        parent[a] = b
        total += w
        print(names[u], "-", names[v], ":", w)
print("Total:", total)

# Prim
print("PRIM")
visited = [False] * 5
visited[0] = True
total = 0
for _ in range(4):
    best = None
    for u, v, w in edges:
        if visited[u] != visited[v]:
            if best is None or w < best[2]:
                best = (u, v, w)
    u, v, w = best
    visited[u] = visited[v] = True
    total += w
    print(names[u], "-", names[v], ":", w)
print("Total:", total)