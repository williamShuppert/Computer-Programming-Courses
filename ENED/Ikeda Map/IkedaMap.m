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



