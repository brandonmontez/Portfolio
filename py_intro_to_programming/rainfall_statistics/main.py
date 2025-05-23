"""
Program Name: Rainfall Statistics
Filename:     main.py
Author:       Brandon Montez
Date:         2020-10-20
Class:        15876
Assignment:   07
Description:  This program is designed to collect monthly rainfall amounts and
              return the total and average rainfall for the year, as well as
              the months containing the highest and lowest amounts of rainfall.
Sources:      None.
"""

# Global Constants
MONTH_NAMES = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']


def main():
  """
  Module Name:  main
  Parameters:   None.
  Description:  Program starting point
  """
  # Set Variables
  month_len = 12  # Number of months in a year
  rain_per_month = [0.0] * month_len

  # Input Array Values
  get_monthly_rainfall(rain_per_month, month_len)

  # Compute Total Rainfall for Year
  yearly_rainfall = get_total_rainfall(rain_per_month, month_len)

  # Compute Avg Value of Array
  avg = get_average_monthly_rainfall(rain_per_month, month_len)

  # Compare Array Values
  most_rainfall = get_month_with_highest_rainfall(rain_per_month, month_len)
  least_rainfall = get_month_with_lowest_rainfall(rain_per_month, month_len)

  # Display Outputs
  print("")
  print("Total Rainfall:", yearly_rainfall)
  print("Average Monthly Rainfall:", avg)
  print("Month With Highest Rainfall:", MONTH_NAMES[most_rainfall])
  print("Month With Lowest Rainfall:", MONTH_NAMES[least_rainfall])


def get_monthly_rainfall(months, months_len):
  """
  Module Name:  get_monthly_rainfall
  Parameters:   1 array, 1 int constant
  Description:  Collects the amount of rainfall for each month.
  """
  for i in range(0, months_len):
    print("Please enter the rainfall for month [", MONTH_NAMES[i], "]")
    months[i] = float(input())


def get_total_rainfall(months, months_len):
  """
  Module Name:  get_total_rainfall
  Parameters:   1 array, 1 int constant
  Description:  Returns the added total of rainfall for the year.
  """
  total = 0
  for i in range(0, months_len):
    total += months[i]
  return total


def get_average_monthly_rainfall(months, months_len):
  """
  Module Name:  get_average_monthly_rainfall
  Parameters:   1 array, 1 int constant
  Description:  Returns the average rainfall per month.
  """
  return get_total_rainfall(months, months_len) / months_len


def get_month_with_highest_rainfall(months, months_len):
  """
  Module Name:  get_month_with_highest_rainfall
  Parameters:   1 array, 1 int constant
  Description:  Utilizes a sequential search algorithm to return the index value
                for the month with the highest amount of rainfall.
  """
  # Set highest index value
  high_i = 0
  # Sequential search for the month with highest value
  for i in range(1, months_len):
    if months[i] > months[high_i]:
      high_i = i
  return high_i


def get_month_with_lowest_rainfall(months, months_len):
  """
  Module Name:  get_month_with_lowest_rainfall
  Parameters:   1 array, 1 int constant
  Description:  Utilizes a sequential search algorithm to return the index value
                for the month with the lowest amount of rainfall.
  """
  # Set lowest index value
  lowest_i = 0
  # Sequential search for the month with lowest value
  for i in range(1, months_len):
    if months[i] < months[lowest_i]:
      lowest_i = i
  return lowest_i


if __name__ == "__main__":
  main()
