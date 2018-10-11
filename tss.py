import numpy as np 
import re
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle



def parseFile(fileName):
	fh = open(fileName, 'r')
	data = fh.readlines()
	fh.close
	counter = 0
	HR = []
	t = []
	for line in data:
		if line.find("<ns3:hr>") != -1:
			startHR = line.find("<ns3:hr>")
			stopHR = line.find("</ns3:hr>")
			HR.append(float(line[startHR+8:stopHR]))
		elif line.find("<time>") != -1:
			startT = line.find("<time>")
			stopT = line.find("</time>")
			t.append(float(line[startT+17:stopT-11])*3600+float(line[startT+20:stopT-8])*60+float(line[startT+23:stopT-5]))
	t[:] = [i - t[0] for i in t]
	t.pop(0) #Delete first element of time which corresponds to activity start time. 
	return(HR,t)

def getZones():
	zones = []
	fh = open('userData','r')
	data = fh.readlines()
	fh.close()
	HR = data[0].split(",")
	for i in range(0,6):
		zones.append((float(HR[1]) - float(HR[0]))*((i+5.0)/10.0) + float(HR[0]))
	return(zones)

def generatePlot(HR, t, zones):
	plt.figure()
	plt.plot(t, HR)
	plt.xlabel('Time (s)')
	plt.ylabel('HR (bpm)')
	plt.title('Heart Rate Over Time')
	currentAxis = plt.gca()
	currentAxis.add_patch(Rectangle((0, int(zones[0])), t[len(t)-1], zones[1] - zones[0], alpha=.15, label='Z1', facecolor='#d142f4'))
	currentAxis.add_patch(Rectangle((0, int(zones[1])), t[len(t)-1], zones[2] - zones[1], alpha=.15, label='Z2', facecolor='#6dc9ff'))
	currentAxis.add_patch(Rectangle((0, int(zones[2])), t[len(t)-1], zones[3] - zones[2], alpha=.15, label='Z3', facecolor='#1ecc00'))
	currentAxis.add_patch(Rectangle((0, int(zones[3])), t[len(t)-1], zones[4] - zones[3], alpha=.15, label='Z4', facecolor='#cc8400'))
	currentAxis.add_patch(Rectangle((0, int(zones[4])), t[len(t)-1], zones[5] - zones[4], alpha=.15, label='Z5', facecolor='#cc0000'))

	print zones[0]
	plt.show()


#fileName = raw_input("Enter file name:")
fileName = "a.gpx"
[HR, t] = parseFile(fileName)
zones = getZones()
print zones[0]
generatePlot(HR, t, zones)
