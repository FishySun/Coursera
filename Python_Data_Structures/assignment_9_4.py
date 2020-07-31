
fname = input("Enter the file name")
try:
    fh = open(fname)
except:
    print("File cannot be opened!")
    quit()

words = dict()

for lines in fh:
    if lines.startswith("From "):
        spl_words = lines.split()
        words[spl_words[1]] = words.get(spl_words[1], 0) + 1

maxval = None
maxword = None

for key, val in words.items():
    if maxval is None or val > maxval:
        maxword = key
        maxval = val

print(maxword, maxval)

fh.close()
