possible_primes = (3, 5, 7, 11, 13, 17)       # store possible prime sums, max possible sum is 9+8 = 17

swappable_nodes = (                           # only these indexed nodes can be swapped
    (0,1),(0,3),    (1,2),(1,4),    (2,5),    # [0 1 2]
    (3,4),(3,6),    (4,5),(4,7),    (5,8),    # [3 4 5]
    (6,7),          (7,8)                     # [6 7 8]
)

possible_grids = {(1,2,3,4,5,6,7,8,9):0}      # (combination) : swap counts to obtain the particular combination

queue = [[1,2,3,4,5,6,7,8,9]] # queue used for bfs

# Generate all possible grids using BFS. Start from (1,2,3,4,5,6,7,8,9)
while queue: # while queue is not empty
  
    cur_grid = queue.pop(0) # queue front
    for node in swappable_nodes:
        if cur_grid[node[0]] + cur_grid[node[1]] in possible_primes:
            # swap the matrix values
            new_grid = cur_grid[:]
            new_grid[node[0]], new_grid[node[1]] = new_grid[node[1]], new_grid[node[0]]

            if tuple(new_grid) not in possible_grids:
                possible_grids[tuple(new_grid)] = possible_grids[tuple(cur_grid)] + 1
                queue.append(new_grid)


# Search for input in all possible grids. If found, then print its swap_count, else print -1.
t = int(input()) # test cases
for _ in range(t):
    matrix = []
    input()
    for i in range(3):
        matrix += list(map(int, input().split()))

    matrix = tuple(matrix)
    if matrix in possible_grids:
        print(possible_grids[matrix])
    else:
        print(-1)
