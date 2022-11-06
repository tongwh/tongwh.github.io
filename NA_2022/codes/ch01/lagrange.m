function yy = lagrange(x, y, xi)
% Lagrange interpolation
% x: interpolation abscissas
% y: interpolation ordinates
% xi: interpolation values 
    m = length(x);
    n = length(y);
    if m ~= n  
        error('the length of x must agree with the length of y!');
    end
    
    s = 0;
    for i = 1:n
        z = ones(1, length(xi));
        for j = 1:n
            if j ~= i
                z = z .* (xi - x(j)) / (x(i) - x(j));
            end
        end
        s = s + z * y(i);
    end
    
    yy = s;
end

