function cof = linlsf(xi, yi)
% Linear least square fitting
% Inputs: xi, yi sample points and values
% Output: coefficients of linear functions
assert(length(xi) == length(yi), 'the number points in xi and yi should be equal!');

A = [length(xi), sum(xi); sum(xi), sum(xi.^2)];
      
b = [sum(yi); sum(xi.*yi)];

cof = A \ b;
end

