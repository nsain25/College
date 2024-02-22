import heapq
class Node:
    def __init__(self, state, parent, move, depth, cost, heuristic):
        self.state = state
        self.parent = parent
        self.move = move
        self.depth = depth
        self.cost = cost
        self.heuristic = heuristic

    def __lt__(self, other):
        return self.cost < other.cost
class Puzzle:
    def __init__(self):
        self.initial_state, self.goal_state = self.accept_input()
    def accept_input(self):
        print("Enter the initial state of the 8 Puzzle (use 0 to represent the blank tile):")
        initial_state = []
        for i in range(3):
            row = list(map(int, input().split()))
            initial_state.append(row)
        print("Enter the goal state of the 8 Puzzle:")
        goal_state = []
        for i in range(3):
            row = list(map(int, input().split()))
            goal_state.append(row)
        return initial_state, goal_state
    def goal_test(self, state):
        return state == self.goal_state
    def find_blank(self, state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j] == 0:
                    return i, j
    def move_blank(self, state, direction):
        i, j = self.find_blank(state)
        if direction == 'up' and i > 0:
            state[i][j], state[i - 1][j] = state[i - 1][j], state[i][j]
        elif direction == 'down' and i < 2:
            state[i][j], state[i + 1][j] = state[i + 1][j], state[i][j]
        elif direction == 'left' and j > 0:
            state[i][j], state[i][j - 1] = state[i][j - 1], state[i][j]
        elif direction == 'right' and j < 2:
            state[i][j], state[i][j + 1] = state[i][j + 1], state[i][j]
    def generate_children(self, node):
        children = []
        directions = ['up', 'down', 'left', 'right']
        for direction in directions:
            child_state = [row[:] for row in node.state]
            self.move_blank(child_state, direction)
            if child_state != node.state:
                child_cost = node.cost + 1
                child_heuristic = self.calculate_heuristic(child_state)
                child = Node(child_state, node, direction, node.depth + 1, child_cost, child_heuristic)
                children.append(child)
        return children
    def calculate_heuristic(self, state):
        h = 0
        for i in range(3):
            for j in range(3):
                if state[i][j] != self.goal_state[i][j]:
                    h += 1
        return h
    def solve(self):
        initial_node = Node(self.initial_state, None, None, 0, 0, 0)
        frontier = [initial_node]
        heapq.heapify(frontier)
        explored = set()
        while frontier:
            current_node = heapq.heappop(frontier)
            explored.add(tuple(map(tuple, current_node.state)))
            if self.goal_test(current_node.state):
                return current_node
            children = self.generate_children(current_node)
            for child in children:
                if tuple(map(tuple, child.state)) not in explored:
                    heapq.heappush(frontier, child)
return None
    def print_solution(self, node):
        if node is None:
            print("No solution found.")
        else:
            path = []
            while node:
                path.append((node.state, node.move))
                node = node.parent
            path.reverse()
            for state, move in path:
                print("Move:", move)
                for row in state:
                    print(row)
                print()
# Example usage:
puzzle = Puzzle()
solution_node = puzzle.solve()
puzzle.print_solution(solution_node)
