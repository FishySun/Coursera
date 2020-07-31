""" Program to prompt the user for hours and rate per hours using input 
    and then compute the gross pay. Use 35 hours and 2.75 per hour to test
    the program """

hrs = input("Enter Hours:")
hrs = int(hrs)
rphrs = input("Enter Rate per Hours:")
rphrs = float(rphrs)
print("Pay:", hrs * rphrs)

