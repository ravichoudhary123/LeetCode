import numpy as np
import operator
#Enter jobs with their timing and cost
jobs = {(1,3):5, (2,5):6,(4,6):5,(6,7):4,(5,8):11,(7,9):2}

prof = [None]*len(jobs)

sorted_jobs =  sorted(jobs, key=operator.itemgetter(1))

j = 0
for n in sorted_jobs:
    prof[j] = jobs[n]
    j +=1

j = 0

for k in np.arange(1, len(sorted_jobs)):
    while j < k:
        if(sorted_jobs[j][1] <= sorted_jobs[k][0]):
            prof[k] = max(jobs[sorted_jobs[k]], prof[j]+jobs[sorted_jobs[k]])
        j += 1

    j = 0

print max(prof)