#!/usr/bin/env python3

import sys
import time
import json
import generate
import subprocess

def printHelp():
	print(f'Usage: {sys.argv[0]} <config> <result>', file=sys.stderr)

def saveResults(results, filename):
	f = open(filename, 'w')
	f.write(json.dumps(results))
	f.close()

def main():
	if len(sys.argv) != 3:
		printHelp()
		sys.exit(1)

	appFilename, configFilename, resultsFilename = sys.argv

	results = {
		'tests': {}
	}

	config = json.loads(open(configFilename, 'r').read())
	for test in config['tests']:
		testName = test['name']
		print(f'Running test "{testName}"')

		results['tests'][testName] = {}
		
		for testNumber in range(test['size_range']['count']):
			currentSize = test['size_range']['start'] + test['size_range']['step'] * testNumber
			generator = generate.functions[test['generate_function']]

			print(f'\tData size of {currentSize}')
			
			for repeat in range(test['repeats']):
				print(f'\t\tRepeat nr {repeat}')
				dataSet = generator(currentSize)
				inputData = ' '.join(list(map(str, dataSet))).encode()

				for appIndex, app in enumerate(test['applications']):
					appName = app['name']
					print(f'\t\t\tRunning app "{appName}"')
					
					if not appName in results['tests'][testName]:
						results['tests'][testName][appName] = {}
					
					if not currentSize in results['tests'][testName][appName]:
						results['tests'][testName][appName][currentSize] = []
					

					startTime = time.time()
					subprocess.check_output(
						app['command'].split(),
						input=inputData	
					)
					endTime = time.time()
					
					interval = endTime - startTime
					results['tests'][testName][appName][currentSize].append(interval)

				saveResults(results, resultsFilename)

					

if __name__ == '__main__':
	main()