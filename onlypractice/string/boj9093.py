# https://www.acmicpc.net/problem/9093

"""
Word Reversal Problem

Print the line with the words reversed.
ex) I am a boy -> I ma a yob

Input
    T: the number of test cases
    S: the sentence to be reversed
"""

import sys

# sys.stdin.readline() is faster than input()
input = sys.stdin.readline

# the number of test cases
T = int(input())

# repeat for T times
for i in range(T):
    # split the sentence into words
    sentence = input().split()
    # print the reversed sentence
    print(" ".join([word[::-1] for word in sentence]))
