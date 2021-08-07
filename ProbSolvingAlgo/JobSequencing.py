# JOB SEQUENCING ALGORITHM -- problem statement : https://www.geeksforgeeks.org/job-sequencing-problem/
# sequences the jobs to make maximum profit
# GREEDY TECHNIQUE - O(m*n) time


class Job:
    def __init__(self, profit=0, deadline=0):
        self.profit = profit
        self.deadline = deadline
        self.id = 0
        
        
class Solution:
    def JobScheduling(self,Jobs,n):
        profit = 0  # counts the overall profit
        count = 0   # counts number of jobs
        T = 0       # maximum deadline to prepare ganntt chart
        for i in range(0,n):
            if Jobs[i].deadline > T:
                T = Jobs[i].deadline
        slot = [-1] * T     #indicates available slots
        
        #sort in decreasing order of profits
        Jobs.sort(key=lambda x: x.profit, reverse=True)
     
        for job in Jobs:
            for j in reversed(range(job.deadline)):
                if j < T and slot[j] == -1:
                    count += 1
                    slot[j] = job.id
                    profit += job.profit
                    break
                    
                    
