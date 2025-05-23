"""
Program Name: Golf Score Modification
Filename:     main.py
Author:       Brandon Montez
Date:         2020-11-8
Assignment:   10
Description:  Revision provides a menu for user choice. Program collects
              records of player names with accompanying scores and stores
              them in a file called "golf.dat".
Sources:      None.
"""

def main():
  """
  Module Name:  main
  Parameters:   None.
  Description:  Main progam execution
  """
  user_choice = -1
  while user_choice != 3:
    # Collect user input
    user_choice = display_menu_and_get_user_selection()
    if user_choice == 1:
      # Initialize and write contents to file
      get_records_from_user_and_write_to_file("golf.dat")
    elif user_choice == 2:
      # Read and display contents from file
      read_records_from_file_and_display("golf.dat")

def display_menu_and_get_user_selection():
  """
  Module Name:  display_menu
  Parameters:   None.
  Description:  Displays program menu for user
  """
  # Display menu contents
  print("Golf Score Menu")
  print("1. Enter golf scores to be saved.")
  print("2. Display previously-entered golf scores.")
  print("3. End the program.")

  # Verify input is within the menu bounds
  selection = int(input())
  if selection < 1 or 3 < selection:
    print("Error: Invalid input")
    
  return selection

def get_records_from_user_and_write_to_file(filename):
  """
  Module Name:  get_records_from_user_and_write_to_file
  Parameters:   1 string which holds the file name to be written to.
  Description:  Appends player name and accompanying score into a file.
  """
  print()
  # Open file to write in append mode
  file = open(filename, "a")

  # Loop until user decides to end
  keep_going = True
  while keep_going == True:
    # Collect name and score for each player
    print("Please enter the player's name: ")
    name = input()
    print("Please enter",  name, "'s score: ")
    score = input()
    # Write contents to file
    file.write("\t".join((name, score)) + "\n")

    # Determine whether user wants to write another
    print()
    keep_going = play_loop()

  # Close file
  file.close()

def play_loop():
    """
    Module Name:  play_loop
    Parameters:   None
    Description:  Performs case-insensitive check on first character of an input to
                  determine if user wants to continue. Returns a boolean value.
    """
    loop = True
    while loop:
        # Collect user input string
        play_again = input("Would you like to enter another record (y/n)?: ")
        # Collect first character of user input
        play_letter = play_again[0:1]
        # Verify character
        if (play_letter.lower() == "y"):
            loop = False
            result = True
        elif (play_letter.lower() == "n"):
            loop = False
            result = False
        else:
            print("Error: Invalid input.")
    # Return a boolean value
    print()
    return result

def read_records_from_file_and_display(filename):
  """
  Module Name:  read_records_from_file_and_display
  Parameters:   1 string which holds the file name to be accessed
  Description:  Reads and displays each record in a file onto a new line.
  """
  # Open file with contents to be read
  file = open(filename, "r")
  print()

  # Scan each line in file
  for line in file:
    # Remove white spaces at the end of the line
    line = line.rstrip()
    # Split record into its fields and store them into seperate variables
    (name, score) = line.split("\t")
    # Display associated field contents
    print(name, "had a score of:", score)

  # Close file
  print()
  file.close()  

main()
