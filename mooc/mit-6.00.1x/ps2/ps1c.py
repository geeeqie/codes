balance = 999999
annualInterestRate = 0.18

monthly_interest_rate = annualInterestRate / 12.0
lower = balance / 12.0
upper = (balance * (1+monthly_interest_rate)**12) / 12.0

while True:
    lowerst_payment = (lower + upper) / 2
    unpaid = balance
    for i in range(0,12):
        unpaid = unpaid - lowerst_payment
        unpaid = unpaid * (1+monthly_interest_rate)

    if abs(unpaid) <= 0.01:
        break
    elif unpaid < 0:
        upper = lowerst_payment
    else:
        lower = lowerst_payment

print "Lowest Payment: %0.2f" % lowerst_payment
