def dfs():
    stack = [(0, 0)]
    visited = set()

    while stack:
        x, y = stack.pop()

        if (x, y) in visited:
            continue

        visited.add((x, y))
        print((x, y))

        if x == 2 or y == 2:
            print("Target reached!")
            return

        next_states = [
            (4, y),  # Fill Jug1
            (x, 3),  # Fill Jug2
            (0, y),  # Empty Jug1
            (x, 0),  # Empty Jug2 
            (x - min(x, 3 - y), y + min(x, 3 - y)),  # Jug1 -> Jug2
            (x + min(y, 4 - x), y - min(y, 4 - x))   # Jug2 -> Jug1
        ]

        for state in next_states:
            if state not in visited:
                stack.append(state)

dfs()