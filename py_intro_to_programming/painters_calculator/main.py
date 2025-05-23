###############################################################################
#
# Program Name: Painter's Calculator
# Filename:     main.py
# Author:       Brandon Montez
# Date:         2020-09-08
# Class:        15876
# Assignment:   02 pt 2/3
# Description:  This program will evaluate the costs associated with an
#               individual job based on the area to be painted and the price
#               per gallon of paint; assuming a labor cost of $20 per hour
#               and a completion rate of 14.375 square feet per hour.
#
# Sources:      Digital Ocean (https://www.digitalocean.com/community/tutorials/how-to-format-text-in-python-3#:~:text=By%20using%20the%20escape%20character,%5C's%20balloon%20is%20red.)
#
###############################################################################


# Constants
COST_LABOR_PER_HOUR = int(20)  # Assuming a cost of $20 per labor hour
RATE_OF_COMPLETION = 14.375  # Assuming a working rate of 14.375 square feet
                             # painted per hour


def main():
  # Display Program Info
  prog_info()

  # User Inputs
  area = wall_area()
  paint_cost_per_gallon = paint_price()

  # Calculations
  paint_gallons = calculate_paint_gallons_required(area)
  labor_hours = calculate_labor_hours_required(area)
  paint_total_cost = calculate_cost_of_paint(paint_gallons,
                                             paint_cost_per_gallon)
  labor_cost = calculate_cost_of_labor(labor_hours, COST_LABOR_PER_HOUR)
  total_cost = calculate_total_job_cost(paint_total_cost, labor_cost)

  # Display Outputs
  display_outputs(paint_gallons, labor_hours, paint_total_cost, labor_cost,
                  total_cost)


# Module Name:  Display Program Info
# Parameters:   None
# Description:  Informs the user what the program is for, and of the constants
#               being used.
def prog_info():
  print('Painter\'s Calculator')
  print('')
  print('This program will evaluate the costs associated with an individual')
  print('job based on the area to be painted and the price per gallon of')
  print('paint; assuming a labor cost of $20 per hour, and a completion rate')
  print('of 14.375 square feet per hour.')
  print('')
  print('--------------------------------------------------------------------')
  print('')


# Module Name:  Get Area
# Parameters:   None
# Description:  Collects the total area to be painted.
def wall_area():
  area = float(input('Area to be painted in square feet: '))
  return area


# Module Name:  Get Cost Per Gallon of Paint
# Parameters:   None
# Description:  Collects the cost per gallon of paint being used.
def paint_price():
  paint = float(input('Cost of paint per gallon: $'))
  return paint


# Module Name:  Calculate Paint Gallons
# Parameters:   1 Float
# Description:  Calculates the gallons of paint required for the job.
def calculate_paint_gallons_required(total_wall_space):
  return (total_wall_space / 115)


# Module Name:  Calulate Labor Hours
# Parameters:   1 Float
# Description:  Calculates the amount of labor hours required to
#               complete the job.
def calculate_labor_hours_required(total_wall_space):
  return total_wall_space / RATE_OF_COMPLETION


# Module Name:  Calculate Paint Cost
# Parameters:   2 Floats
# Description:  Calculates the cost of paint required for the job.
def calculate_cost_of_paint(paint_gallons_required, paint_price_per_gallon):
  return paint_gallons_required * paint_price_per_gallon


# Module Name:  Calculate Labor Cost
# Parameters:   1 Float, 1 Int Constant
# Description:  Calculates the cost of labor for the job.
def calculate_cost_of_labor(labor_hours_required, labor_cost_per_hour):
  return labor_hours_required * labor_cost_per_hour


# Module Name:  Calculate Total Cost
# Parameters:   2 Floats
# Description:  Calculates the total cost for the job.
def calculate_total_job_cost(cost_of_paint, cost_of_labor):
  return cost_of_paint + cost_of_labor


# Module Name:  Display Outputs
# Parameters:   5 Floats
# Description:  Displays all of the required resources in convenient format.
def display_outputs(paint_gallons, labor_hours, paint_cost, labor_cost,
                    total_price):
  print('')
  print('')
  print('Time required:', int(labor_hours), 'hours',
        int(round(labor_hours * 60 % 60, 0)), 'minutes')
  print('Gallons of paint required:', round(paint_gallons, 1))
  print('Cost of paint: $', round(paint_cost, 2), sep='')
  print('Cost of labor: $', round(labor_cost, 2), sep='')
  print('')
  print('Total cost of job: $', round(total_price, 2), sep='')


if __name__ == '__main__':
  main()

