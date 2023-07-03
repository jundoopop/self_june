# https://www.acmicpc.net/problem/10799

"""
Iron Cut

Cutting Iron stick by laser.

"""

# Input
iron_stick = input()
num_of_iron = 0
cut = []

for element in iron_stick:
    cut.append(element)
    if cut[-2:] == ["(", ")"]:
        num_of_iron += len(cut[:-2])
        
