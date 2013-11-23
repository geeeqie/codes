total_paid = 0
for i in range(0,13):
    monthly_interest_rate = annualInterestRate/12.0
    minimum_monthly_payment = monthlyPaymentRate * balance
    balance = (balance - minimum_monthly_payment) * (1 + monthly_interest_rate)
    total_paid += minimum_monthly_payment
    if i != 0:
        print "Month:", i
        print "Minimum monthly payment: %.2f" % minimum_monthly_payment
        print "Remaining balance: %.2f" % balance

print "Total paid: %.2f"% total_paid
print "Remaining balance: %.2f"% balance
