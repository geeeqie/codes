def McNuggets(n):
    """
    n is an int

    Returns True if some integer combination of 6, 9 and 20 equals n
    Otherwise returns False.
    """
    # Your Code Here

    for a in range(0, n/6+1):
        for b in range(0, n/9+1):
            for c in range(0, n/20+1):
                if 6*a+9*b+20*c == n:
                    return True
    return False

for i in range(100):
    print i, McNuggets(i)
