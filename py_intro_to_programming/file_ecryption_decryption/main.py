"""
Program Name: File Encryption/Decryption 
              (Ch 12 Programming Exercises #10 & #11)
Filename:     main.py
Author:       Brandon Montez
Date:         2020-11-13
Assignment:   11
Description:  Allows user to convert a program file into cipher-text
              and decrypt cipher-files back into their original state.
Sources:      None.
"""

# shift each character's ASCII value by this much
SHIFT = 3

def main():
  """
  Module Name:  main
  Parameters:   None.
  Description:  Program starting point
  """
  selection = -1
  while selection != 3:
    selection = display_menu_and_get_user_selection()
    if selection == 1:
      encrypt_file()
    elif selection == 2:
      decrypt_file()
    elif selection == 3:
      pass
    else:
      print("Error: Invalid input.\n")

def display_menu_and_get_user_selection():
  """
  Module Name:  display_menu_and_get_user_selection
  Parameters:   None.
  Description:  Displays program menu and returns the user's selection
  """
  # display menu contents
  print("File Encryption/Decryption")
  print("1. Encrypt a file.")
  print("2. Decrypt a file.")
  print("3. End the program.")

  # collect and return unverified user selection
  return int(input())

def encrypt_file():
  """
  Module Name:  encrypt_file
  Parameters:   None.
  Description:  Creates a cipher-text file when given the name of the
                program to convert and the name of the output file.
  """
  # open file to be read
  filename = input("Please enter the name of the file to encrypt: ")
  original_file = open(filename, "r")

  # create file to be written to
  new_file_name = input("Please enter the name of the cipher-text file: ")
  cipher_file = open(new_file_name, "w")

  # read each character in original file
  for i in original_file:
    for j in i:
      # if character isn't a space convert to cipher text and write to cipher_file
      if not(j.isspace()):
        cipher_file.write(chr(ord(j) + SHIFT))
      # else if character is a space write the non-converted text to cipher_file
      else:
        cipher_file.write(j)

  # display status message
  print("\nCompleted: cipher-text available in:", new_file_name, "\n")

  # close files
  original_file.close()
  cipher_file.close()

def decrypt_file():
  """
  Module Name:  decrypt_file
  Parameters:   None.
  Description:  Decodes a cipher-text file when given the name of the
                program to convert and the name of the output file.
  """
  # open file to be read
  filename = input("Please enter the name of the file to decrypt: ")
  cipher_file = open(filename, "r")

  # create file to be written to
  new_file_name = input("Please enter the name of the clear-text file: ")
  clear_file = open(new_file_name, "w")

  # read each character in cipher file
  for i in cipher_file:
    for j in i:
      # if character isn't a space convert to original text and write to clear_file
      if not(j.isspace()):
        clear_file.write(chr(ord(j) - SHIFT))
      # if character is a space write the non-converted text to clear_file
      else:
        clear_file.write(j)

    # display status message
  print("\nCompleted: clear-text available in:", new_file_name, "\n")

  # close files
  cipher_file.close()
  clear_file.close()

if __name__ == "__main__":
  main()
