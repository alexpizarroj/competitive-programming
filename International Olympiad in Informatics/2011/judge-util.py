import os
import subprocess
import time

def getTextFileContents(filePath):
	with open(filePath) as f:
		content = "".join(f.readlines())
	return content

def evaluate(graderPath, taskName):
	taskFolder = "./" + taskName + "/"
	nsolved = total = 0
	verdicts = []
	runtimes = []

	for p in os.listdir(taskFolder):
		if p.find("grader.in") == -1:
			continue
		# Judge it!
		running_time = -0.0001
		data = getTextFileContents(taskFolder + p)
		try:
			starting_time = time.time()
			res = subprocess.check_output(graderPath,
				input=data, universal_newlines=True)
			ending_time = time.time()
			running_time = ending_time - starting_time
		except:
			res = "RTE"
		expectFileName = p.replace("in", "expect")
		expect = getTextFileContents(taskFolder + expectFileName)
		if (res == expect):
			res = "AC"
		elif res != "RTE":
			res = "WA"
		# Results update
		verdicts.append(res)
		runtimes.append(running_time)
		total += 1
		if (res == "AC"):
			nsolved += 1
		print("\rSolved", nsolved, "out of", total, end="", flush=True)

	runtimes_str = [("%.3f" % round(x, 3)) for x in runtimes]
	print("\nVerdicts:", ", ".join(verdicts))
	print("Runtimes:", ", ".join(runtimes_str))
	print("Max. Running Time:", "%.3f" % max(runtimes))
	
	return (nsolved, total)

if __name__ == "__main__":
	graderProgram = "./api/grader.exe"
	totalPoints = score = partialScore = 0
	# Task folders look-up
	subtasks = [ x[7:].split('-') for x in os.listdir("./")
		if os.path.isdir(x) and x.startswith("subtask")
		and x.count('-') == 1 ]
	subtasks = [ (x[0], x[1]) for x in subtasks 
		if all((y.isdecimal() for y in x)) ]
	subtasks.sort()
	# Task evaluation
	for task in subtasks:
		# Properties
		taskFolder = "subtask" + task[0] + "-" + task[1]
		taskValue = int(task[1])
		# Judgement
		taskLegend = "Subtask " + task[0] + " (" + task[1] + " points)"
		print(taskLegend)
		print("-" * len(taskLegend))
		(nsolved, total) = evaluate(graderProgram, taskFolder)
		print("")
		# Update
		totalPoints += taskValue
		partialScore += taskValue * (nsolved / total)
		if ( nsolved == total ):
			score += taskValue
	# Evaluation results
	if totalPoints > 0:
		score = (score / totalPoints) * 100
		partialScore = (partialScore / totalPoints) * 100
		print("IOI Score:", round(score, 2), sep='\t')
		print("Partial Score:", round(partialScore, 2), sep='\t')
	else:
		print("No tasks were found.")
	