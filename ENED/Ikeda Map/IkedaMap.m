% Activity HW 5.1:  Homework 5.1
% File:         HW_5p1_Task1_shuppewd.m
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
% plot an Ikeda map given a value for Mu

clear; clc;

u = -1;
while u > 1 || u < 0
    u = input("Enter value between 0 and 1: ");
    disp(u)
end

x = [.4];
y = [.4];
t = [.4];

for n = 2:10001
    x(n) = 1+u*(x(n-1)*cos(t(n-1))-y(n-1)*sin(t(n-1)));
    y(n) = u*(x(n-1)*sin(t(n-1))+y(n-1)*cos(t(n-1)));
    t(n) = .4-(6/(1+x(n)^2+y(n)^2));
end

plot(x(2001:10001), y(2001:10001), '.','MarkerSize',10);
xlim([-.5 2]);
ylim([-2.5 1]);
title("Ikeda Map: Mu = " + u);
xlabel("x");
ylabel("y");



