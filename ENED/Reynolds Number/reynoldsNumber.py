# Activity Python 1: Task 2
# File: HW_11p2_Task2_shuppewd.py
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
# This program finds the reynolds number and determines the type of flow

import math

def getNumericInput(prompt, min=float("-inf"), max=float("inf")):
    while True:
        try: num = float(input(prompt))
        except: 
            print("Invalid input: Enter a number between",min,"and",max)
            continue
        if num >= min and num <= max: return num
        else: print("Invalid input: Enter a number between",min,"and",max)

while True:
    if (siUnits := input("SI or US: ").lower()) in ["si","us"]: 
        siUnits = siUnits == "si"
        break
    else: print("Invalid input: Enter \"SI\" or \"US\"")

v = getNumericInput("Enter velocity (" + ("ft/s","m/s")[siUnits] + "): ")
l = getNumericInput("Enter length (" + ("ft","m")[siUnits] + "): ",0)
h = getNumericInput("Enter height (" + ("ft","m")[siUnits] + "): ",0)

if siUnits:
    v *= 3.28084
    l *= 3.28084
    h *= 3.28084 
    
if h<=36152: 
    t = 59-0.00356*h
    p = 2116*((t+459.7)/(518.6))**5.256
elif h<82345:
    t = -70
    p = 473.1*math.e**(1.73-.000048*h)
else:
    t = -205.05+0.00164*h
    p = 51.97*((t+489.7)/(389.98))**-11.3889

d = p/(1718*(t+459.7))
usl = 3.737*(10**-7)
tsl = 288.15
t = (t-32) * (5/9) + 273.15
u = usl*((t/tsl)**(3/2))*((110+tsl)/(110+t))
r = d*v*l/u

print("Re =",r,"\nThe flow is",(("turbulent","transient")[r<=4000],"laminar")[r<2300])