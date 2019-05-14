#!/usr/bin/python

import sys
import random

pcsSize = 4
dirTab = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def PrintPcs(pcs):
	for line in pcs:
		print (''.join(line))

def GenPcs(pcs, x, y):
	pcs[y][x] = '#'
	i = 1
	while (i < pcsSize):
		while (1):
			d = random.randint(0,pcsSize - 1)
			if (((y + dirTab[d][0] >= 0) and (y + dirTab[d][0] < pcsSize))
				and ((x + dirTab[d][1] >= 0) and (x + dirTab[d][1] < pcsSize))):
					if (pcs[y + dirTab[d][0]][x + dirTab[d][1]] == '#'):
						i -= 1;
					i += 1;
					pcs[y + dirTab[d][0]][x + dirTab[d][1]] = '#'
					y += dirTab[d][0];
					x += dirTab[d][1];
					break ;

def CreatePcs():
	pcs = [['.' for x in range(pcsSize)] for x in range(pcsSize)]
	GenPcs(pcs, random.randint(0,pcsSize - 1), random.randint(0,pcsSize - 1))
	PrintPcs(pcs)

if __name__ == '__main__':
    # If there is only one argument
	if (len(sys.argv) == 2):
        # Convert string to integer
		pcsNbr = int(sys.argv[1])
		if (pcsNbr > 0 and pcsNbr <= 26):
            # Until there are pieces to be shown
			while pcsNbr:
				CreatePcs()
				pcsNbr -= 1
				if (pcsNbr):
					print ('')
		else:
			print ("Piece number can't have to be between 1 and 26")
	else:
		print ("Usage: python3 generator.py [Piece number]")
