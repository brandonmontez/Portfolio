"""
Program Name: Slot Machine Simulator V2
Filename:     main.py
Author:       Brandon Montez
Date:         2020-09-27
Description:  Simulated slot machine.
              User inserts money, then selects their bet amount and how many
              times to spin. Game then simulates all spins by rolling 3
              independent events with 5 mutually exclusive outcomes each, and
              awarding a payout upon matching events: 0 matches = bet * 0;
              2 matches = bet * 2; 3 matches = bet * 3.
              Game has +$0.08 EV for the user.
Sources:      W3 Schools (https://www.w3schools.com/python/python_for_loops.asp)
"""

# Import libraries
from locale import *
setlocale(LC_ALL, "")
from random import *


def main():
    """
    Module Name:  main
    Parameters:   None
    Description:  Main program execution.
    """
    print('--** Roll 3 Slot Machine! **--')
    print("Match 2 symbols: +2x your bet!")
    print("Match 3 symbols: +3x your bet!")
    print("")

    # Collect user's money
    insert_cash = float(input("How much money would you like to insert?: $"))

    # Play game
    slot_total = main_machine(insert_cash)

    # Output results
    print("")
    print("----------")
    print("")
    print("Cash in:", currency(insert_cash))
    print("Profit:", currency(slot_total - insert_cash))
    print("Cash out:", currency(slot_total))


def main_machine(start_cash):
    """
    Module Name:  main_machine
    Parameters:   1 float
    Description:  Calls upon all main functions of machine after recieving $
    """
    play_game = True
    while play_game:
        print("")
        print("----------")
        print("Good Luck!")
        print("----------")
        print("")
        print("In machine:", currency(start_cash))

        # User input for bet per spin and number of spins
        bet = float(input("Bet denomination: $"))
        max_val = int(input("Number of spins: "))
        min_val = 0  # Counter starting value for machine spins
        print("")

        # Compute results
        slot_total = slot_sim(bet, start_cash, min_val, max_val)
        profit = slot_total - start_cash

        # Display results
        print("----------")
        print("")
        print("Start amt:", currency(start_cash))
        print("Profit:", currency(profit))
        print("End amt:", currency(slot_total))

        # Set variables for new game
        start_cash = slot_total
        play_game = play_again()
    return slot_total


def slot_sim(bet, slot_total, min_val, max_val):
    """
    Module Name:  slot_sim
    Parameters:   1 user float, 1 float, 1 int constant, 1 user int
    Description:  Returns a new slot total after iterating the machine a given
                  amount of times.
    """
    for i in range(min_val, max_val):
        match_0 = 0 
        match_2 = 2
        match_3 = 3
        print("In machine:", currency(slot_total))
        print("Bet:", currency(bet))

        # End game if user is broke
        if (slot_total < bet):
            print("")
            print("Error: You don't have enough money!")
            print("")
            break

        # Generate 3 random events to test
        fruit1 = fruit_rng()
        fruit2 = fruit_rng()
        fruit3 = fruit_rng()
        print("[", fruit1, "]", "[", fruit2, "]", "[", fruit3, "]", sep="")

        # 0 matches: 0.48 probability
        if (fruit1 != fruit2 and fruit2 != fruit3 and fruit1 != fruit3):
            scale = match_0
        # 3 matches: 0.04 probability
        elif (fruit1 == fruit2 and fruit2 == fruit3 and fruit1 == fruit3):
            scale = match_3
        # 2 matches: 0.48 probability
        else:
            scale = match_2

        prize = bet * scale
        slot_total = slot_total - bet + prize
        print("You win:", currency(prize))
        print("")
    return slot_total


def fruit_rng():
    """
    Module Name:  fruit_rng
    Parameters:   None
    Description:  Simulates one slot machine roll
    """
    cherry_int = 1
    orange_int = 2
    plum_int = 3
    melon_int = 4
    bar_int = 5

    cherry_str = "Cherry"
    orange_str = "Orange"
    plum_str = "Plum"
    melon_str = "Melon"
    bar_str = "Bar"

    fruit_int = randint(1, 5)
    if (fruit_int == cherry_int):
        fruit = cherry_str
    elif (fruit_int == orange_int):
        fruit = orange_str
    elif (fruit_int == plum_int):
        fruit = plum_str
    elif (fruit_int == melon_int):
        fruit = melon_str
    else:
        fruit = bar_str
    return (fruit)


def play_again():
    """
    Module Name:  play_again
    Parameters:   None
    Description:  Determines whether the user wants to play again.
                  Case insensitive to user input.
                  Returns a boolean value.
    """
    loop = True
    while loop:
        print("")
        play_again = input("Play again? (y/n): ")
        play_letter = play_again[0:1]
        if (play_letter.lower() == "y"):
            loop = False
            return True
        elif (play_letter.lower() == "n"):
            loop = False
            return False
        else:
            print("Error: Invalid input.")    


if __name__ == "__main__":
    main()
