import numpy as np 
import re


fh = open('a.gpx', 'r')
data = fh.readlines()
fh.close
counter = 0
HR = []
t = []
for line in data:
	if line.find("<ns3:hr>") != -1:
		startHR = line.find("<ns3:hr>")
		stopHR = line.find("</ns3:hr>")
		HR.append(line[startHR+8:stopHR])
	elif line.find("<time>") != -1:
		startT = line.find("<time>")
		stopT = line.find("</time>")
		
		t.append(line[startT+17:stopT-5])
		print t
