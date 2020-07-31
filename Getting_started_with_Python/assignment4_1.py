# Python programt to calculate the gross pay using functions

def computepay(hours, rate):
    if hours > 40:
        ans = rate * 40 + (hours - 40) * 1.5 * rate
        return ans
    else:
        ans = hours * rate
        return ans


hours = input("Enter hours:")
rate = input("Enter rate:")
try:
    hours = float(hours)
    rate = float(rate)
except:
    print("Not valid input!")
    quit()

print("Pay", computepay(hours, rate))
