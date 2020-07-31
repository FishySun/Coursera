
fname = input("Enter a file name")
try:
    fh = open(fname)
except:
    print("File cannot be opened!")
    quit()

hours = dict()

for lines in fh:
    if lines.startswith('From '):
        mline = lines.split()
        mh = mline[5].split(':')[0]
        hours[mh] = hours.get(mh, 0) + 1

mhours = hours.items()
mhours.sort()

for key, value in mhours:
    print(key, value)

fh.close()

