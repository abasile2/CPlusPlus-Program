import re
import string

# included in starter py file
def printsomething():
    print("Hello from python!")

# included in starter py file
def PrintMe(v):
    print("You sent me: " + v)
    return 0;

# included in starter py file
def SquareValue(v):
    return v * v

# double the value by multiplying by 2
def DoubleValue(v):
    return v * 2

# function to create and print a multiplication table
def MultiplicationTable(v):
    for x in range(1, 11):
        print("{} x {} = {}".format(v, x, v * x))
    return 0