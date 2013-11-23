def interlace(s1, s2):
    newstring = []
    for i in range(len(s1)):
        newstring.append(s1[i])
        newstring.append(s2[i])
    return ''.join(newstring)

def laceStrings(s1, s2):
    """
    s1 and s2 are strings.

    Returns a new str with elements of s1 and s2 interlaced,
    beginning with s1. If strings are not of same length,
    then the extra elements should appear at the end.
    """
    # Your Code Here

    if len(s1) > len(s2):
        return interlace(s1[:len(s2)], s2) + s1[len(s2):]
    elif len(s1) < len(s2):
        return interlace(s1, s2[:len(s1)]) + s2[len(s1):]
    else:
        return interlace(s1, s2)

print laceStrings("abcd", "efghi")
print laceStrings("", "abcd")
print laceStrings("abcd", "")
print laceStrings("", "")
print laceStrings("abcd", "abcdefg")
print laceStrings("abcdefg", "abcd")
