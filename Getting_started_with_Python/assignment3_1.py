# Program to calculate gross pay. For every hour above 40 
# increase the rate to 1.5 times the original

hrs = input("Enter Hours:")
hrs = float(hrs)
rate = input("Enter hourly rate:")
rate = float(rate)
if hrs > 40:
    ans = 40 * rate + (hrs - 40) * 1.5 * rate
    print(ans)
else :
    ans = hrs * rate
    print(ans)
