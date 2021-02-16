% Activity HW 4.1:  Homework 4.1
% File:         HW_4p1_Task2_shuppewd.m
% Date:         02/05/21
% By:           Will Shuppert (shuppewd)
%
% Section:      011
% Team:         182
%
% ELECTRONIC SIGNATURE
% Will Shuppert
%
% The electronic signature above indicates the script
% submitted for evaluation is my individual work, and I
% have a general understanding of all aspects of its
% development and execution.
%
% A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
% Finds the nth term in the Padovan sequence

clear; clc;

pn = 0;
p1 = 1;
p2 = 1;
p3 = 1;

n = -1;

while n < 1
    n = input("enter nth term: ");
end

if n > 0
    fprintf("P0 = 1\n");
    if n > 1
        fprintf("P1 = 1\n");
        if n > 2
            fprintf("P2 = 1\n");
        end
    end
end

for i = 3:n
    pn = p2 + p3;
    fprintf("P%i = %i\n", i, pn);
    p3 = p2;
    p2 = p1;
    p1 = pn;
end