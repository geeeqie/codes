def logInner(x, b, isNegative):
    product = 1
    i = 0
    while product < x:
        product *= b
        i += 1
    if product == x:
        if isNegative:
            return -i
        else:
            return i
    else:
        if isNegative:
            return -i
        else:
            return i - 1


def myLog(x, b):
    '''
    x: a positive integer
    b: a positive integer

    returns: log_b(x), or, the logarithm of x relative to a base b.
    '''
    # Your Code Here
    if x == 1:
        return 0
    if b > 1 and x > 1:
        return logInner(x, b, False)
    elif b > 1 and x < 1:
        return logInner(1/x, b, True)
    elif b < 1 and x > 1:
        return logInner(x, 1/b, True)
    else:
        return logInner(1/x, 1/b, False)


from math import *

print myLog(16, 2), log(16,2)
print myLog(15, 2), log(15,2)

print myLog(16, 1/2.0), log(16, 1/2.0)
print myLog(15, 1/2.0), log(15, 1/2.0)

print myLog(1/16.0, 2), log(1/16.0, 2)
print myLog(1/15.0, 2), log(1/15.0, 2)

print myLog(1/16.0, 1/4.0), log(1/16.0, 1/4.0)
print myLog(1/15.0, 1/4.0), log(1/15.0, 1/4.0)

print myLog(2,2), log(2,2)
print myLog(1/2.0, 1/2.0), log(1/2.0, 1/2.0)
print myLog(1/2.0, 2), log(1/2.0, 2)
print myLog(2, 1/2.0), log(2, 1/2.0)
