def findPath(maze, n):
    path = [0 for i in range(100)]
    findPathUtil(maze, n, 0, 0, path, 0)
def findPathUtil(maze, n, i, j, path, index):
    if i < 0 or i >= n or j < 0 or j >= n:
        return
    if i == n - 1 and j == n - 1:
        path[index] = '\0'
        printPath(path, index)
        return
    if maze[i][j] == 0:
        return
    maze[i][j] = 0
    path[index] = 'D'
    findPathUtil(maze, n, i + 1, j, path, index + 1)
    path[index] = 'R'
    findPathUtil(maze, n, i, j + 1, path, index + 1)
    path[index] = 'U'
    findPathUtil(maze, n, i - 1, j, path, index + 1)
    path[index] = 'L'
    findPathUtil(maze, n, i, j - 1, path, index + 1)
maze[i][j] = 1    
def printPath(path, n):
    for i in range(n):
        print(path[i], end = "")
    print()
n = 4
maze = []
print("Enter the entries rowwise:")
for i in range(n):
    row = list(map(int, input().split()))
    maze.append(row)
print(maze)
findPath(maze, n)
