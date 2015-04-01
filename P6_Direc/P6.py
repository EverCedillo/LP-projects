import math
def distances(l):
	d=[]
	for i in range(len(l)-1):
	    mag= math.sqrt((l[i][0] - l[i+1][0])**2 + (l[i][1] - l[i+1][1])**2)
            x=l[i+1][0] - l[i][0]
            if x == 0:
               d.append((mag,90))
            else:
	       angle=math.atan2((l[i+1][1] - l[i][1]),x)
	       d.append((mag,math.degrees(angle)))
	return d

def reverse(l):
	d=[]
	for i in l.__reversed__():
		d.append(i)
	return d

	