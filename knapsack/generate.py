#!/usr/bin/env python3

# Skrypt, który generuje zestawy danych dla problemu plecakowego
# Jest wykorzystywany przez skrypt benchmark
# Na wejściu znajduje się jedna liczba
# zależnie od trybu pracy skryptu jest to ilość przedmiotów
# lub maksymalny udźwig plecaka

import sys
import random

def fprint(*args, **kwargs):
	print(*args, **kwargs, file=sys.stderr)

def displayHelp():
	fprint(f'Usage: {sys.argv[0]} <mode> <value>')
	fprint('Where:')
	fprint('\t<mode>: capacity, items')
	fprint('\t<value> - given value\n')

	fprint('Give the opposite value at stdin\n')
	sys.exit(1)

def getCapacityAndItems(mode, value):
	if mode == "capacity":
		return (int(value), int(input()))
	elif mode == "items":
		return (int(input()), int(value))
	else:
		displayHelp()


def generateItems(capacity, items):
	WEIGHT_RANGE = (1, int(0.777 * capacity))
	VALUE_RANGE = (1, 100)

	for _ in range(items):
		yield (random.randint(*WEIGHT_RANGE), random.randint(*VALUE_RANGE))


def main():
	if len(sys.argv) != 3:
		displayHelp()

	_, mode, value = sys.argv
	capacity, items = getCapacityAndItems(mode, value)

	print(capacity)	
	for item in generateItems(capacity, items):
		print(item[0], item[1])

if __name__ == '__main__':
	main()
