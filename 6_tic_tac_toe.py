board = [" "] * 9
player = "X"

while " " in board:
    print(f"\n{board[0]}|{board[1]}|{board[2]}\n-+-+-\
          \n{board[3]}|{board[4]}|{board[5]}\n-+-+-\
          \n{board[6]}|{board[7]}|{board[8]}\n")
    
    move = int(input(f"{player}'s turn (0-8): "))
    
    if board[move] == " ":
        board[move] = player
        
        # 2. Check all 8 win conditions in a single line using any()
        if any(board[i] == board[j] == board[k] == player 
               for i, j, k in [(0,1,2), (3,4,5), (6,7,8), (0,3,6), (1,4,7), (2,5,8), (0,4,8), (2,4,6)]):
            print(f"{player} wins!")
            break
            
        player = "O" if player == "X" else "X"