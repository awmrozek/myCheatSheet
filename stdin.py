# How to read integers from STDIN
# To read strings, remove int() typecast
# Cred: mans et code@lth

from collections import *
import sys
itr = (line for line in sys.stdin.read().split('\n'))
INP = lambda: next(itr)

# Returns next integer from STDIN
def ni(): return int(INP())

# Returns next line
def nl(): return [int(_) for _ in INP().split()]

