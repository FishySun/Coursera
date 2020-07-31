# Write a program that prompts for a file name, then opens that file 
# and read throughout the file and print the contents in upper case.

filename = input("Enter the filename: ")
try:
    fhand = open(filename)
except:
    print("The given file doesn't exists!")
    quit()

for lines in fhand:
    lines = lines.rstrip()
    print(lines.upper())

fhand.close()
