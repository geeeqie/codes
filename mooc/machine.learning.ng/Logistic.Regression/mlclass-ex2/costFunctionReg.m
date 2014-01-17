function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
part1 = 0;
for i=1:m
    hx = sigmoid(X(i,:)*theta);
    part1 += -y(i)*log(hx) - (1-y(i)) * log(1 - hx);
end

part1 = part1 / m;

part2 = 0;
for j=2:size(theta)
    part2 += theta(j)^2;
end
part2 = lambda*part2 / (2*m);

J = part1 + part2;

for j = 1:size(theta)
    s = 0;
    for i = 1:m
        s += (sigmoid(X(i,:)*theta) - y(i)) * X(i, j);
    end
    s = s / m;
    if j >= 2
            s += lambda*theta(j) / m;
    end
    grad(j) = s;
end

%%% QY: vectored version, much faster!
% h = sigmoid(X*theta);
% J = (1/m) * sum(-y'*log(h) - (1-y)'*log(1-h)) + lambda/(2*m)*sum(theta(2:end,:).^2);
% 
% grad = (1/m) * (X' * (h - y));
% grad(2:end,:) += lambda/m * theta(2:end,:);
%%%

% =============================================================

end
