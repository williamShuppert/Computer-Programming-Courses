# Activity Python 1: Task 1
# File: HW_11p1_Task1_shuppewd.py
# Date:    11/11/20
# By:      William Shuppert
# Section: 013
# Team:    165
# 
# ELECTRONIC SIGNATURE
# William Shuppert
#
# The electronic signature above indicates the script
# submitted for evaluation is my individual work, and I
# have a general understanding of all aspects of its
# development and execution.
#
# A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
# This program finds side length c of a triangle using law of cosine

import math

def isValid(num, min = 0, max = float('inf')):
    return (num >= min and num <= max)

a, b, c = float(input("Enter side a: ")), float(input("Enter side b: ")), float(input("Enter angle C (degree): "))

invalidInput = False

if not isValid(a): 
    print("a is invalid")
    invalidInput = True
if not isValid(b):
    print("b is invalid")
    invalidInput = True
if not isValid(c, 0, 180):
    print("c is invalid")
    invalidInput = True

if not invalidInput: print(math.sqrt(a**2+b**2-2*a*b*math.cos(math.radians(c))))