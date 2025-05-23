"""
Program Name: ---
Filename:     main.py
Author:       Brandon Montez
Date:         2024-6-07
Class:        Math 156-LEC-1
Assignment:   01
Description:  This script is a simple demonstration of polynomial regression.
            Submission for HW1, problem 3.
Sources:      None.
"""

# Import libraries
from random import *   #RNG import
from math import *     #Math import
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

def main():
    """
    Module Name:  main
    Parameters:   None
    Description:  Main program execution.
    """
    # Initialize vars
    m = 4	# Degree of polynomial to fit
    weights = np.ones(m+1)	# m+1 weights including bias term
    running_sum = 0

    # Load data
    data = pd.read_csv('hw1-fitting.csv', header=None, index_col=0,
      names = ['x', 'y'])

    x = data['x']
    y = data['y']

    # Part (A)
    # Show scatterplot
    # Optional params: 'save=' boolean, 'name =' filename
    # scatterplot(x, y)

    # Part (B)
    phi_x = phi(x, m)

    print(phi_x)
    # for row in phi_x:
    #   for i in range(m+1):
    #     running_sum += weights[i] * float(row)
    #     print(float(row[1])**i)
    #     print(weights)


def scatterplot(x, y, save = False, name = 'scatterplot.png'):
    """
    Module Name:  scatterplot
    Parameters:   x, y: numpy array of values to plot
                  save: boolean indicating whether to save the plot
                  name: string indicating the name and type of the saved output
                        ('scatterplot.png' by default)
    Description:  Makes a scatterplot and saves to a file if boolean is set
    """
    plt.scatter(x, y)
    if save:
      plt.savefig(name)
    plt.show()

def phi(x, m):
    """
    Module Name:  phi
    Parameters:   x: numpy array of observed variables
                  m: degree of desired polynomial
    Description:  Convert a numpy array of variables into a polynomial design matrix. 
    """
    phi_of_x = np.ones((x.size, m + 1))
    for i in range(0, m+1):
      phi_of_x[:,i] = x**i

    return phi_of_x

if __name__ == "__main__":
    main()