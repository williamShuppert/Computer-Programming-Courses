% A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
% Find possible positions for a two-link robot arm.

clear; clc;

L1 = -1;
L2 = -1;

while L1 < 0
   L1 = input("Enter link length L1: "); 
end

while L2 < 0
   L2 = input("Enter link length L1: "); 
end

x = [];
y = [];

for theta1 = 0:5:90
    for theta2 = 0:5:180
        x(end + 1) = L1*cos(deg2rad(theta1))+L2*cos(deg2rad(theta1 + theta2));
        y(end + 1) = L1*sin(deg2rad(theta1))+L2*sin(deg2rad(theta1 + theta2));
    end
end

plot(x, y, '.');
title("Map of Possible Gripper Positions");
xlabel("x coorinate of gripper");
ylabel("y coordinate of gripper");
