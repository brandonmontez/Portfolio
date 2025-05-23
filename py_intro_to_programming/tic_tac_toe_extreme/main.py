"""
Program Name: Tic-Tac-Extreme!
Filename:     main.py
Author:       Brandon Montez
Date:         2020-11-17
Assignment:   Extra Credit
Description:  Tic-Tac-Toe game for 2 players. Supports board sizes up to 9x9.
              BUG: Program crashes on board_menu non-integer input
              BUG: board_menu doesn't reprint on invalid selection
              TODO: Allow user to exit back to main menu prematurely
Sources:      None.
"""

P1 = "Player 'X'"
P2 = "Player 'O'"
P1_MARK = "X"
P2_MARK = "O"


def main():
  """
  Module Name:  main
  Parameters:   none
  Description:  main program execution
  """
  print("""                       Welcome to Tic-Tac-Extreme!
Think outside of the box in this exciting new spin on the classic game!
Challenge your friends and play on boards from 3x3 all the way up to 9x9!""")
  # verify menu selection
  selection = "-1"
  size = 3  # default board size is 3x3
  while selection != "3":
    show_main_menu(size)
    selection = input("Please enter your selection: ")
    # start game
    if selection == "1":
      play(size)
    # change board size
    elif selection == "2":
      size = board_menu(size)
    # end program
    elif selection == "3":
      pass
    else:
      print("Error: Invalid menu choice.")

  # exit message
  print("\nThanks for playing!")


def show_main_menu(size):
  """
  Module Name:  show_main_menu
  Parameters:   1 int indicating board size
  Description:  displays the main program menu
  """
  print("\nMain Menu:")
  print("1. Play Game (", size, "x", size, ")", sep="")
  print("2. Change Board")
  print("3. End Program\n")


def board_menu(size):
  """
  Module Name:  board_menu
  Parameters:   1 int containing current board size
  Description:  displays the menu to change board size, returns length of board
                sides based on user selection, default return value is current
                board size
  """
  # print board menu
  print("\nChange Board")
  for i in range(3, 10):
    print(i, ". ", i, "x", i, sep="")
  print("0. Back")

  # verify user selection
  selection = -1
  valid = False
  while selection != 0 and not valid:
    print("\nPlease enter your selection: ", end="")
    selection = int(input())
    # when selection is in range set size to selection
    if 3 <= selection and selection <= 9:
      size = selection
      valid = True
    # sentinel value to return to main menu
    elif selection == 0:
      pass
    else:
      print("Error: Invalid menu choice.")

  # size is the length of gameboard sides
  return size


def play(dimensions):
  """
  Module Name:  play
  Parameters:   1 int carrying board dimensions
  Description:  starts the game
  """
  # play game loop
  keep_playing = True
  while keep_playing:
    area = dimensions ** 2
    # 2D game board intialized with *
    board = [["*" for y in range(dimensions)] for x in range(dimensions)]

    # display title
    print("\nTic-Tac-Extreme!")

    move_counter = 0
    tie = False
    won = False
    while not (won or tie):
      # update board with player 1 move
      board = player_move(board, P1, P1_MARK)
      move_counter += 1

      # check for win or tie
      won = evaluate(board, P1, P1_MARK)
      if won:
        winner = P1
      elif move_counter == area:
        tie = True

      # if game is not over
      else:
        # update board with player 2 move
        board = player_move(board, P2, P2_MARK)
        move_counter += 1

        # check for win or tie
        won = evaluate(board, P2, P2_MARK)
        if won:
          winner = P2
        elif move_counter == area:
          tie = True
    
    # display game results
    print_board(board)
    if won:
      print("Game over: ", winner, " wins!\n", sep="")
    elif tie:
      print("Game over: Tie!\n")
    else:
      print("Error: How did you get here?")

    # after game is over, prompt user to play again or exit to main menu
    keep_playing = play_loop()


def player_move(board, player, mark):
  """
  Module Name:  player_move
  Parameters:   1 two dimensional array with board state, 1 string indicating
                player name, 1 string indicating player marker
  Description:  updates the game board with player's move
  """
  
  rows = len(board)
  cols = len(board[0])

  rows_coord_len = len(str(rows))
  cols_coord_len = len(str(cols))

  valid = False
  while not valid:
    # collect input
    player_move = ""
    while len(player_move) < 2 or ((rows_coord_len + cols_coord_len) < 
                                    len(player_move)):
      # print board
      print_board(board)

      # collect coordinate input
      print(player, ", please enter the (x, y) coordinates for your move: ",
            sep="", end="")
      player_move = input()

      # keep only digits
      player_move = keep_digits(player_move)

      # verify coordinate length
      if len(player_move) < 2:
        print("Error: Coordinates contain not enough digits.")
      elif (rows_coord_len + cols_coord_len) < len(player_move):
        print("Error: Coordinates contain too many digits.")

    # split move string into x, y integer coordinates
    # useful when expanding code to allow double digit boards
    x_coord = ""
    y_coord = ""
    for i in range(0, cols_coord_len):
      x_coord += player_move[i]
    for i in range(cols_coord_len, rows_coord_len + cols_coord_len):
      y_coord += player_move[i]
    x_coord = int(x_coord)
    y_coord = int(y_coord)
    
    # validate input exists on board and has not yet been taken
    valid = validate_input(board, x_coord, y_coord, mark)

  # place mark on board
  (board[y_coord - 1][x_coord - 1], mark) = (mark,
                                             board[y_coord - 1][x_coord - 1])
  # return board state
  return board


def validate_input(board, x, y, mark):
  """
  Module Name:  validate_input
  Parameters:   1 two dimensional array with board state, 2 ints indicating
                move coordinates (x, y), 1 string indicating player marker
  Description:  returns true if user input reflects a valid location on the
                board that is not already occupied
  """
  # board dimensions
  rows = len(board)
  cols = len(board[0])

  valid = False
  # verify that coordinates are within range
  if x < 1 or rows < x:
    print("Error: Coordinate x (", x, ") is out of range.", sep="")
    if y < 1 or cols < y:
      print("Error: Coordinate y (", y, ") is out of range.", sep="")
  elif y < 1 or cols < y:
    print("Error: Coordinate y (", y, ") is out of range.", sep="")
  # verify that coordinates are unoccupied
  else:
    if board[y - 1][x - 1] != "*":
      print("Error: That tile is occupied.")
    else:
      valid = True

  return valid


def keep_digits(move):
  """
  Module Name:  keep_digits
  Parameters:   1 string as an unformatted player move
  Description:  returns player move as a string of digits
  """
  mutable = ""
  for i in move:
    # keeps only digits from user input
    if i.isdigit():
      mutable += i
  move = "".join(mutable)
  # move returns as a string of digits
  return move


def print_board(board):
  """
  Module Name:  print_board
  Parameters:   1 two dimensional array with board state
  Description:  displays the game board
  """
  print()
  # print board in coordinate plane format with accompanying y values
  for i in range(len(board) - 1, -1, -1):
    print(i + 1, board[i])
  # print x values
  for i in range(1, len(board[0]) + 1, 1):
    print("   ", i, end="")
  print("\n")


def evaluate(board, player, mark):
  """
  Module Name:  evaluate
  Parameters:   1 two dimensional array carrying board state, 1 string
                indicating player name, 1 string indicating player marker
  Description:  evaluates the position, if there is a winner it is declared
                and the result returns true, otherwise returns false
  """
  rows = len(board)
  cols = len(board[0])

  won = False
  ascend_diag = 0
  descend_diag = 0
  for i in range(0, rows):  # this only works on square boards
    vert = 0
    # descending diagonal check
    if board[i][cols - 1 - i] == mark:
      descend_diag += 1
    # ascending diagonal check
    if board[i][i] == mark:
      ascend_diag += 1
    # horizontal check
    if "".join(board[i]) == mark * cols:
      won = True
    # vertical check
    for j in range(0, cols):
      if board[j][i] == mark:
        vert += 1
    if vert == rows:
      won = True

  # check results of diagonal tests
  if ascend_diag == rows or descend_diag == rows:  # only works on square boards
    won = True

  return won


def play_loop():
    """
    Module Name:  play_loop
    Parameters:   none
    Description:  collects an input and performs case-insensitive check on
                  first character to determine if user wants to continue,
                  returns a boolean value
    """
    loop = True
    while loop:
        # collect user input string
        play_again = input("Would you like to play again? y/n: ")
        # collect first character of user input
        play_letter = play_again[0:1].lower()
        # verify character
        if (play_letter == "y"):
            loop = False
            result = True
        elif (play_letter == "n"):
            loop = False
            result = False
        else:
            print("Error: Invalid input.\n")
    # return boolean
    return result


main()
