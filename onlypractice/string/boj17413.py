"""
Word reverse:

Input String S:
1. lower letters a to z
2. numbers 0 to 9
3. special characters: <. >
4. space ' '

Strings inside special characters <, > are called tags:
- String in tag is not reversed
- Tag is not a word
- No space between tag and word
"""

S = input()  # Input string
temp = ""  # String to add to result
result = ""  # Result string
for ch in S:  # Inspect each character in String S
    temp += ch  # Add the character to the temp string

    if (
        len(temp) > 1 and temp[0] == "<" and ch == ">"
    ):  # If a tag is completely counted,
        result += temp  # Add a temp to result
        temp = ""  # Flush temp
        continue  # Go to next iteration

    if len(temp) > 1 and ch == "<":  # If another tag is started,
        result += temp[-2::-1]  # Add the reversed word to result,
        temp = "<"  # Flush except the tag opening
        continue  # Go to next iteration

    if (
        len(temp) > 1 and temp[0] != "<" and ch == " "
    ):  # If a word is completely counted with blank at the end
        result += (
            temp[-2::-1] + " "
        )  # Add a reversed word and blank to divide with next words
        temp = ""  # Flush the string in temp
        continue

if temp:  # If word is left
    result += temp[::-1]
print(result)  # Print the result
