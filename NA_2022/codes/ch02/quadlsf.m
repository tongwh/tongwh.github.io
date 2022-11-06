function cof = quadlsf(xi, yi)
% Quadratic least square fitting
% Inputs: xi, yi sample points and values
% Output: coefficients of quadratic functions
assert(length(xi) == length(yi), 'the number points in xi and yi should be equal!');

A = [length(xi), sum(xi), sum(xi.^2); sum(xi), sum(xi.^2), sum(xi.^3); sum(xi.^2), sum(xi.^3), sum(xi.^4)];
      
b = [sum(yi); sum(xi.*yi); sum(xi.^2.*yi)];

cof = A \ b;
end


