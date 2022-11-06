function [y, x] = euler(f, a, b, m, y0)
% Euler's method for solving initial value problems
% Input: right-hand side function f(x, y) with two variables, interval [a,
% b], number of grid points m, and initial value y0
% Output: solution y
h = (b - a)/m;
x(1) = a; y(1) = y0;
for i = 1:m
    x(i+1) = x(i) + h;
    y(i+1) = y(i) + h * f(x(i), y(i));
end

% plot
%plot(x, y);

end

