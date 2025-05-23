"""
Program Name: Ackermann's Function
Filename:     main.py
Author:       Brandon Montez
Date:         2020-11-24
Assignment:   12
Description:  This program implements Ackermann's function into a recursive
              module.
Sources:      none
"""

def main():
  """
  Module Name:  main
  Parameters:   None.
  Description:  Program starting point
  """
  # Collect user input values
  m = int(input("Please enter a value for m: "))
  n = int(input("Please enter a value for n: "))

  # Compute Ackermann value
  result = ackermann(m, n)

  # Display result
  print("\nThe ackermann value for", m, ",", 4, "is:", result)

def ackermann(m, n):
  """
  Module Name:  ackermann
  Parameters:   m, n -> 2 ints
  Description:  Recursively evlauates the ackermann value for two
                given integers.
  """
  if m == 0:
    return n + 1
  if n == 0:
    return ackermann(m - 1, 1)
  else:
    return ackermann(m - 1, ackermann(m, n - 1))

if __name__ == "__main__":
  main()
