###############################################################################
# Program Name: Change for a Dollar Game
# Filename:     main.py
# Author:       Brandon Montez
# Date:         9/14/2020
# Class:        15876
# Assignment:   03 pt. 2
# Description:  This program is a simple game where the user tries to make
#               $1.00 by inputting an amount of pennies, nickles, dimes,
#               and quarters.
#
# Sources:      Geeks for Geeks (https://www.geeksforgeeks.org/how-to-pass-multiple-arguments-to-function/)
#               Tutorials Point (https://www.tutorialspoint.com/returning-multiple-values-in-python#:~:text=Python%20functions%20can%20return%20multiple,one%2C%20two%20or%20more%20values.)
#               Digital Vidya (https://www.digitalvidya.com/blog/python-dictionary/))
#               Programiz (https://www.programiz.com/python-programming/if-elif-else)
###############################################################################


def main():
  display_info()
  test_total(get_coins())

  
# Module Name:  Program Info
# Parameters:   None
# Description:  Displays the program name and game rules for user
def display_info():
  print('Change for a Dollar Game')
  print('')
  print('The rules of this game are simple, try to enter the number of coins')
  print('required to make exactly one dollar.')
  print('')
  print('-------------------------------------------------------------------')
  print('')
  

# Module Name:  User Input
# Parameters:   None
# Description:  Collects the amount of each coin from user input
#               Returns the total value of coins as 1 float
def get_coins():
  pennies = int(input('Step 1. Enter the number of pennies: '))
  nickles = int(input('Step 2. Enter the number of nickles: '))
  dimes = int(input('Step 3. Enter the number of dimes: '))
  quarters = int(input('Step 4. Enter the number of quarters: '))
  return ((pennies + nickles * 5 + dimes * 10 + quarters * 25) / 100)


# Module Name:  Results
# Parameters:   1 float
# Description:  Tests whether the float value is more than, less than, or equal to 1
#               Displays user's score
def test_total(total):
  print('')
  if total > 1:
    print('Oops! You went over $1.00! Your total was: $', total, sep='')
  elif total < 1:
    print('Oops! You are under $1.00! Your total was: $', total, sep='')
  else:
    print('Congratulations! You\'ve made exactly $1.00!')


if __name__ == "__main__":
  main()

