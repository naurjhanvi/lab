cost = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

n = len(cost)

visited = [False] * n
path = [0]
visited[0] = True
current = 0
total_cost = 0

for _ in range(n - 1):
    nearest = -1
    min_cost = 9999

    for city in range(n):
        if not visited[city] and cost[current][city] < min_cost:
            min_cost = cost[current][city]
            nearest = city

    path.append(nearest)
    visited[nearest] = True
    total_cost += min_cost
    current = nearest

total_cost += cost[current][0]
path.append(0)

print("Path:", path)
print("Total Cost:", total_cost)