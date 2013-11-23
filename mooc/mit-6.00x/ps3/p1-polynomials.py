
def evaluatePoly(poly, x):
    '''
    Computes the value of a polynomial function at given value x. Returns that
    value as a float.
 
    poly: list of numbers, length > 0
    x: number
    returns: float
    '''
    # FILL IN YOUR CODE HERE...
    sum = 0.0
    for power, coefficient in enumerate(poly):
        sum += coefficient * (x**power)
    return sum

# print evaluatePoly([0.0, 0.0, 5.0, 9.3, 7.0], -13)
# print evaluatePoly([2, 0, 7, 1], 4)
# print evaluatePoly([-12], 3.7)

def computeDeriv(poly):
    '''
    Computes and returns the derivative of a polynomial function as a list of
    floats. If the derivative is 0, returns [0.0].
 
    poly: list of numbers, length &gt; 0
    returns: list of numbers (floats)
    '''
    # FILL IN YOUR CODE HERE...
    deriv = []
    for power, coefficient in enumerate(poly[1:], 1):
        deriv.append(float(coefficient)*power)
    if deriv == []:
        deriv = [0.0]
    return deriv

# print computeDeriv([-13.39, 0.0, 17.5, 3.0, 1.0])
# print computeDeriv([6, 1, 3, 0])
# print computeDeriv([20])

def computeRoot(poly, x_0, epsilon):
    '''
    Uses Newton's method to find and return a root of a polynomial function.
    Returns a list containing the root and the number of iterations required
    to get to the root.
 
    poly: list of numbers, length > 1.
         Represents a polynomial function containing at least one real root.
         The derivative of this polynomial function at x_0 is not 0.
    x_0: float
    epsilon: float > 0
    returns: list [float, int]
    '''
    # FILL IN YOUR CODE HERE...

    x = x_0
    number_of_iteration = 0

    while True:
        fx = poly
        d_fx = computeDeriv(poly)
        if abs(evaluatePoly(fx, x)) < epsilon:
            break
        x = x - evaluatePoly(fx, x) / evaluatePoly(d_fx, x)
        number_of_iteration += 1
    return (x, number_of_iteration)

print computeRoot([-13.39, 0.0, 17.5, 3.0, 1.0], 0.1,  .0001)
print computeRoot([1, 9, 8], -3, .01)
print computeRoot([1, -1, 1, -1], 2, .001)
