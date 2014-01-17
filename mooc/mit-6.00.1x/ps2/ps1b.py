balance = 4773
annualInterestRate = 0.2

lowerst_payment = 10
monthly_interest_rate = annualInterestRate / 12.0

while True:
    unpaid = balance
    for i in range(0,12):
        unpaid = unpaid - lowerst_payment
        unpaid = unpaid * (1+monthly_interest_rate)
    if unpaid <= 0:
        break
    lowerst_payment += 10

print "Lowest Payment: %d" % lowerst_payment
