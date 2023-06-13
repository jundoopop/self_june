# https://www.acmicpc.net/problem/1406

# https://seongonion.tistory.com/53


"""
text_to_edit Problem

location_of_cursor's location:
- Between the characters
- Left to the first of the sequence
- Right to the last of the sequence

L: move location_of_cursor one character to the left.
D: move location_of_cursor one character to the right.
B: delete character left of the location_of_cursor
P $: add character $ right of the location_of_cursor.

end: right of the last
beginning: left of the first

When the operation start, location_of_cursor is at the end of the text.
"""

# this code is not passed because operating time is exceeded to the standard.

text_to_edit = (
    input()
)  # A string would be modified during the command entered in the iteration
print(f"Input text: {text_to_edit}")
location_of_cursor = len(text_to_edit)  # The start point is on the end
for i in range(int(input())):  # Iterate for the number entered on the input
    command = input()  # Put the command: L / D / B / P $

    # Command L works when cursor is not on the first of the string
    if command == "L" and location_of_cursor != 0:
        location_of_cursor -= 1

    # Command D works when cursor is not on the end of the string
    if command == "D" and location_of_cursor != len(text_to_edit):
        location_of_cursor += 1

    # Command B works when cursor is not on the start of the string
    if command == "B" and location_of_cursor != 0:
        text_to_edit = (
            text_to_edit[: location_of_cursor - 1] + text_to_edit[location_of_cursor:]
        )
        location_of_cursor -= 1  # Remain the character on the right of the cursor same

    # P $ should be splited to the two elemented array for the command working
    if command.split()[0] == "P":
        text_to_edit = (
            text_to_edit[:location_of_cursor]
            + command.split()[1]
            + text_to_edit[location_of_cursor:]
        )
        location_of_cursor += 1

    print(f"Current text: {text_to_edit}")

print(text_to_edit)
