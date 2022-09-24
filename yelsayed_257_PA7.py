#------------------------------------------------------------------------------- # YOUSEF ELSAYED: George Mason
# Assignment 7
# Due Date: 04/17/2022 #------------------------------------------------------------------------------- # Honor Code Statement: I received no assistance on this assignment that
# violates the ethical guidelines set forth by professor and class syllabus. #-------------------------------------------------------------------------------
# References: (Professor, Self) #-------------------------------------------------------------------------------
# Comments and assumptions: A note to the grader as to any problems or
# uncompleted aspects of the assignment, as well as any assumptions about the
# meaning of the specification. #-------------------------------------------------------------------------------
# NOTE: width of source code should be <=80 characters to be readable on-screen. #2345678901234567890123456789012345678901234567890123456789012345678901234567890
# 10 20 30 40 50 60 70 80 #-------------------------------------------------------------------------------

def fraction_count(num1, num2):
    res = 0 #empty value i can use to store the divion
    vals = num1 / num2   #the math
    if vals != int(vals):   #checks of the calculated number is a decimal or not
        res = 1 + fraction_count(int(vals),num2)  #function calls it's self once again
    return res        
        
    
def concat_order(str1, str2):
    tgthr = ''  #empty string for later 
    res = ''
    if len(tgthr) == len(str1 + str2): #base case for the problem
        return tgthr
    res = str1[0] + str2[0]   #adds the strings in the first index
    if len(str1 + str2) != len(tgthr):   #checks if the length of it is the same 
        res = res + concat_order(str1[0+1:] , str2[0+1:])  #adds up the entire stack and returns 
    return res
    
    
def sum_product(some_list, i ,j):
    if i == j:   #base case, checks when the two values are equal to each other
        return some_list[i]  #returns the list if's it's equal 
    if i > j:
        return 0  #checks to see if the i value is greater
    totls = 0 #for the calculations
    sub_lst = some_list   #setting the list to make a sub list later
    return sub_lst[i] * sub_lst[j] + sum_product(some_list, i+1 ,j-1)  #multiplies the sublists and adds them together 
                                                                       #then calls the functions again while changing the 
                                                                       # i and j values 

def calc_res(some_list, res=0):
    if some_list == []: #returns zero once the string is empty 
        return res
    if some_list[0] == 0:  #makes it so that if it's 0 it's skipped over
        return calc_res(some_list[1:],res)  #moves to the one after the 0
    pan = 0  #empty val to use in my calculations 
    if some_list[0] % 2 == 0:  #checks if the val is even but divisibility
        pan = some_list[0] * res  #multiplies the val with the res val
        return calc_res(some_list[1:],pan)  #adds it to the stack and recalls the function
    elif some_list[0] %2 != 0:  #checks for if it's not divisible, odd
        pan = res + some_list[0] #adds the 'odd' val with the res
        return calc_res(some_list[1:],pan)  #stacks the odd val and recalls the function