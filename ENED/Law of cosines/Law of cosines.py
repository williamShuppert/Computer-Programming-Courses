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
