
fname = input("Enter the filename: ")
try:
    fh = open(fname)
except:
    print("File cannot be opened!")
    quit()

words = list()

for lines in fh:
    lines = lines.rstrip()
    if lines.startswith("From "):
        mlines = lines.split()
        print(mlines[1])
        words.append(mlines[1])

print("There were", len(words), "lines in the file with From as the first word")

fh.close()
