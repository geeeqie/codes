# USACO 1.1.1
#
# input:
#
# COMETQ
# HVNGAT
#
#
# output:
#
# GO

comet = raw_input()
group = raw_input()
val = lambda string: reduce(lambda x,y:x*y, map(lambda x:ord(x)-ord('A')+1, list(string)))%47
if val(comet) == val(group):
    print 'GO'
else:
    print 'STAY'

