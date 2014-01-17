balance = 4213
annualInterestRate = 0.2
monthlyPaymentRate = 0.04

total_paid = 0.0

for i in range(1,12+1):
    minimum_monthly_payment = balance * monthlyPaymentRate
    monthly_unpaid_balance = balance - minimum_monthly_payment
    balance = monthly_unpaid_balance + monthly_unpaid_balance * (annualInterestRate/12)
    total_paid += minimum_monthly_payment
    print "Month: %d" % i
    print "Minimum monthly payment: %.2f" % minimum_monthly_payment
    print "Remaining balance: %.2f" % balance

print "Total paid: %.2f" % total_paid
print "Remaining balance: %.2f" % balance
