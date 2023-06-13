"""
Parenthesis String Problem

VPS = Valid PS.
Check the input is VPS or not.

()() is vps, (())) is not.
"""

for i in range(int(input())):
    # get parenthesis
    parenthesis_case = input()

    # if the number 'status' is not 0, it's invalid case.
    status = 0
    for part in parenthesis_case:
        if part == "(":
            status -= 1
        if part == ")":
            status += 1
            # If rightside parenthesis is larger than leftside, it's invalid.
            if status > 0:
                break

    if status == 0:
        # The numbers of left/right parenthesis are same but sequence is invalid
        if parenthesis_case[-1] == "(":
            print("NO")
        else:
            print("YES")
    else:
        print("NO")
