# Write a Python Program to extract the number at the end of the line
# Convert the number to a floating point value and print it.

text = "X-DSPAM-Confidence:    0.8475"
pos = text.find('0')    # Grab the starting location of the number in the string
num = text[pos:]        # Capture the total number from the string
num = float(num)        # Convert the string literal to float value
print(num)

