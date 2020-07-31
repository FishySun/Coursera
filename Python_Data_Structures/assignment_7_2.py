
filename = input("Enter the filename: ")
try:
    fhand = open(filename)
except:
    print("File cannot be opened!")
    quit()

fs = 0
count = 0

for line in fhand:
    line = line.rstrip()
    if line.startswith("X-DSPAM-Confidence:"):
        pos = line.find('0')
        num = line[pos:]
        num = float(num)
        fs += num
        count += 1
    else:
        continue

fhand.close()
print("Average spam confidence:", fs/count)
