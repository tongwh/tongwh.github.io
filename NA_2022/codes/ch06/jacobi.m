function x = jacobi(A, b, M, tol)
% Jacobi method
% Inputs: full or sparse matrix A, r.h.s. b,
%            number of Jacobi iterations M, tolerance tol 
% Output: solution x
n = length(b);                          % find n
D = diag(A);                           % extract diagonal of A
R = A-diag(D);                        % R is the remainder
x=zeros(n,1);                          % initialize vector x
for k=1:M                               % loop for Jacobi iteration
    u = (b-R*x)./D; 
    
    fprintf('k = %d, x(k) = (', k);   % output x(k)
    for j=1:n-1
        fprintf('%.16f, ', u(j));
    end
    fprintf('%.16f), ', u(n));
    fprintf('||x(k) - x(k-1)|| = %.16f. \n', norm(u-x, 2));
    
    if norm(u-x, 2) < tol
        x = u;
        return;
    else
        x = u;
    end
end                                       % End of Jacobi iteration loop

fprintf('can not solve the linear equation Ax = b by Jacobi method.\n');
end