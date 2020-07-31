
fname = input("Enter the file name: ")
try:
    fh = open(fname)
except:
    print("File cannot be opened!")
    quit()

words = list()

for lines in fh:
    lines = lines.rstrip()
    stripped_words = lines.split()
    for split_words in stripped_words:
        if split_words not in words:  
            words.append(split_words)


words.sort()
print(words)
