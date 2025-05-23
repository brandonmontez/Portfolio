"""
Program Name: Celsius to Farenheit GUI
Filename:     main.py
Author:       Brandon Montez
Date:         2020-12-7
Assignment:   14
Description:  GUI for a Celsius to Fahrenheit calculator.
Sources:      none
"""

from tkinter import *

def calculate_button_click():
  """
  Module Name:  calculate_button_click
  Parameters:   none
  Description:  Takes the celsius value from the input text within
                celsius_text_box and sets farhenheit_text_box to the
                corresponding fahrenheit value.
  """
  celsius = float(celsius_text_box.get())

  fahrenheit = 9 / 5 * celsius + 32

  fahrenheit_text_box["text"] = fahrenheit

def exit_button_click():
  """
  Module Name:  exit_button_click
  Parameters:   none
  Description:  Closes the calculator.
  """
  window.destroy()

# Create window structure
window = Tk()

# Create celsius components
celsius_label = Label(window,
                      text="Please enter the temperature in degrees Celsius:")

celsius_label.grid(row=0, column=0)

celsius_text_box = Entry(window)

celsius_text_box.grid(row=0, column=1)

# Create fahrenheit components
fahrenheit_label = Label(window, text="The degrees Fahrenheit is:")

fahrenheit_label.grid(row=1, column=0, sticky="e")

fahrenheit_text_box = Label(window)

fahrenheit_text_box.grid(row=1, column=1, sticky="w")

# Create calculate button
calc_button = Button(window, text="Calculate", command=calculate_button_click)

calc_button.grid(row=2, column=0)

# Create exit button
exit_button = Button(window, text="Exit", command=exit_button_click)

exit_button.grid(row=2, column=1)

# Run window
window.mainloop()