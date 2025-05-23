"""
Program Name: File Management
Filename:     main.py
Author:       Arthur Nesbitt, Brandon Montez
Instructor:		Prof. Eldridge
Course:				CISP 300
Date:         11-20-2020
Assignment:   Extra Credit (Scrum Role Play)
Description:  
"""

def main():
  """
  Module Name:	main
  Parameters:		None
  Description:	Primary program execution
  """
  # Initialize the variable 'user_selection'.
  user_selection = ""

  while user_selection != "4":
    # Collect user input.
    user_selection = display_menu_and_get_user_selection()

    # Select case.
    if user_selection == "1":
      file = open_document()

    elif user_selection == "2":
      close_document(file)

    elif user_selection == "3":
      print_document(file)


def display_menu_and_get_user_selection():
  """
  Module Name: display_menu_and_get_user_selection
  Parameters:  None
  Description: Collects and validates user's menu selection
               Returns a valid input
  """
  # Set user's input to a starting variable.
  user_selection = ""
  # Flag for input being in range.
  valid = False

  # Check to see if their selection is valid.
  while not(user_selection.isdigit()) or not(valid):
    # Display menu.
    print_menu()
    # Prompt user for their selection.
    print("\nPlease enter your menu option: ", end="")
    user_selection = input()
    # Display error message if invalid input.
    if user_selection.isdigit():
      if 1 <= int(user_selection) and int(user_selection) <= 4:
        valid = True
      else:
        print("Error: Selection is out of range.\n")
    else:
      print("Error: Not a digit.\n") 
 
  return user_selection

def print_menu():
  """
  Module Name: print_menu
  Parameters:  None
  Description: Displays list of menu options to the user
  """
  print("     Main Menu:")
  print("1. Open a new document.")
  print("2. Close the document.")
  print("3. Print the current document.")
  print("4. Exit the program.")

def open_document():
  """
  Module Name: open_document
  Parameters:  None
  Description: Returns an opened file which the user designates
  """
  print("\nPlease enter the file name: ", end="")
  filename = input()
  file = open(filename, "r")
  print("The file", filename, "has been opened\n")
  return file

def print_document(file):
  """
  Module Name: print_document
  Parameters:  file -> 1 file which is opened to read
  Description: Prints each line in the file
  """
  print()
  for i in file:
    print(i)
  print()

def close_document(file):
  """
  Module Name: close_document
  Parameters:  file -> 1 file which is opened to read
  Description: Closes the file
  """
  print("The file has been closed.\n")
  file.close()

main()
