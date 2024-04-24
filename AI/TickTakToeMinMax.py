# Tic-Tac-Toe board represented as a list
# 0 = empty, 1 = player X, 2 = player O
board = [0, 0, 0,
         0, 0, 0,
         0, 0, 0]
# Function to print the current board
def print_board(board):
    for i in range(0, 9, 3):
        print(board[i], board[i + 1], board[i + 2])
# Function to check if the game is over
def game_over(board):
    # Check rows, columns, and diagonals
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8),  # Rows
                      (0, 3, 6), (1, 4, 7), (2, 5, 8),  # Columns
                      (0, 4, 8), (2, 4, 6)]             # Diagonals
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] != 0:
            return True
    if 0 not in board:  # Board full
        return True
    return False
# Function to evaluate the board for the Minimax algorithm
def evaluate(board):
    # Check rows, columns, and diagonals for possible wins
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8),  # Rows
                      (0, 3, 6), (1, 4, 7), (2, 5, 8),  # Columns
                      (0, 4, 8), (2, 4, 6)]             # Diagonals
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] == 1:
            return 10  # Player X wins
        elif board[condition[0]] == board[condition[1]] == board[condition[2]] == 2:
            return -10  # Player O wins
    return 0  # Draw
# Minimax algorithm
def minimax(board, depth, is_maximizing):
    score = evaluate(board)
    # Base cases: game over or maximum depth reached
    if score == 10 or score == -10 or game_over(board):
        return score
    if is_maximizing:
        best_score = -float('inf')
        for i in range(9):
            if board[i] == 0:
                board[i] = 1
                best_score = max(best_score, minimax(board, depth + 1, False))
                board[i] = 0
        return best_score
    else:
        best_score = float('inf')
        for i in range(9):
            if board[i] == 0:
                board[i] = 2
                best_score = min(best_score, minimax(board, depth + 1, True))
                board[i] = 0
        return best_score
# Main function to find the optimal move using Minimax
def find_best_move(board):
    best_move = -1
    best_score = -float('inf')
    for i in range(9):
        if board[i] == 0:
            board[i] = 1
            move_score = minimax(board, 0, False)
            board[i] = 0
            if move_score > best_score:
                best_score = move_score
                best_move = i
    return best_move
# Example usage
print("Initial board:")
print_board(board)
while not game_over(board):
    player_move = int(input("Enter your move (0-8): "))
    if board[player_move] != 0:
        print("Invalid move. Try again.")
        continue
    board[player_move] = 2
    print("Updated board after your move:")
    print_board(board)
    if game_over(board):
        break
    print("Computer's move:")
    computer_move = find_best_move(board)
    board[computer_move] = 1
    print_board(board)
if evaluate(board) == 10:
    print("You lose!")
elif evaluate(board) == -10:
    print("You win!")
else:
    print("It's a draw!")
