# Finds the maximum profit without overlapping the jobs
# Using dynamic programming in O(n^2)

class Job:
    def __init__(self, start, finish, profit):
        self.start  = start
        self.end = finish
        self.profit  = profit


def schedule(job):
    # Sort jobs according to finish time
    job = sorted(job, key = lambda j: j.end)
  
    n = len(job) 
    table = [0 for _ in range(n)]
  
    table[0] = job[0].profit

    for i in range(1,n):
        table[i] = max(job[i].profit, table[i-1])
        for j in range(i-1,-1,-1):
            if job[j].end <= job[i].start:
                table[i] = max(table[i], job[i].profit + table[j])
                break
    
    maxVal = 0
    for val in table:
        if val > maxVal:
            maxVal = val

    return maxVal

# main
job = [Job(1, 3, 5), Job(2, 5, 6), Job(4, 6, 5), Job(6, 7, 4), Job(5, 8, 11), Job(7, 9, 2)]
print("Optimal profit is "+str(schedule(job)))
