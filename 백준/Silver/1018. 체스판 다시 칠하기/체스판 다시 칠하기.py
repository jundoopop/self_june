row, column = map(int, input().split())  # 8 <= row, column <= 50
plane = []  # 8 * 8
result = 32
wbw = ["WBWBWBWB", "BWBWBWBW"]  # white, black

for i in range(row):  # input
    plane.append(input())

for i in range(row - 7):  # Loop for the times of row numbers
    for j in range(column - 7):  # Loop for the times of column numbers
        temp = 0  # Count the number to correct the color
        if plane[i][j] == "W":  # If first column of first row starts with "W"
            odd, even = wbw[0], wbw[1]  # Odd numbered rows should be "WBWBWBWB"
        else:  # If first element starts with "B"
            odd, even = wbw[1], wbw[0]  # Odd numbered rows should be "BWBWBWBW"

        # Cut 8 x 8 plane to iterate for counting
        current_plane = [plane[x][j : j + 8] for x in range(i, i + 8)]

        for k in range(8):  # Loop for 8 rows
            if (
                k % 2 == 0
            ):  # On the odd lined rows: Index starts from 0, so 0 is assumed as 1st row
                temp += sum(
                    1 for a, b in zip(current_plane[k], odd) if a != b
                )  # Count different characters by each strings
            else:  # On the even lined rows
                temp += sum(1 for a, b in zip(current_plane[k], even) if a != b)

        result = min(result, temp, 64 - temp)  # Consider the reverse chessboard as well

print(result)
