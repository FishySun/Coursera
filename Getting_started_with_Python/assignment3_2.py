# Python program to print grades according to scores

score = input("Enter score: ")
try: 
    score = float(score)
except:
    print("Not a valid score!")
    quit()

if score < 0.0 or score > 1.0:
    print("Not a valid score!")
elif score >= 0.9:
    print('A')
elif score >= 0.8:
    print('B')
elif score >= 0.7:
    print('C')
elif score >= 0.6:
    print('D')
else:
    print('F')
