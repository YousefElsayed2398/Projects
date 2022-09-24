#------------------------------------------------------------------------------- # YOUSEF ELSAYED: George Mason
# Assignment 8
# Due Date: 04/20/2022 #------------------------------------------------------------------------------- # Honor Code Statement: I received no assistance on this assignment that
# violates the ethical guidelines set forth by professor and class syllabus. #-------------------------------------------------------------------------------
# References: (Professor, Self) #-------------------------------------------------------------------------------
# Comments and assumptions: A note to the grader as to any problems or
# uncompleted aspects of the assignment, as well as any assumptions about the
# meaning of the specification. #-------------------------------------------------------------------------------
# NOTE: width of source code should be <=80 characters to be readable on-screen. #2345678901234567890123456789012345678901234567890123456789012345678901234567890
# 10 20 30 40 50 60 70 80 #-------------------------------------------------------------------------------



    
def read_grades_file(filename, project = False):
    file = open(filename, 'r')  #opening the file to be read]
    new_dict = {}  #empty dict for later
    lines = file.readlines()   #reading the lines 
    trimmed_lines = []    #new list
    for string in lines:    #looping through the list of words
        if string[len(string)-1] == '\n':    #runs through the lines back ward and checks to see their length
            string = string[:-1]
        string = string.split(', ')  #divided the words by , and space
        trimmed_lines.append(string)     #adding to the original file 
    new_dict[trimmed_lines[0][0]] = trimmed_lines[0][1]    #for the name
    trimmed_lines.pop(0)      #deleted the unnecessary line
    for lst in trimmed_lines:    #loops through the list that i created
        for i in range(len(lst)):    #uses the index of the list
            if i !=0:
                lst[i] = float(lst[i])
    for i in range(len(trimmed_lines)):     #indexes of my list
        if trimmed_lines[i][0] == 'pa' or trimmed_lines[i][0] == 'lab' or trimmed_lines[i][0] == 'zy':
            new_dict[trimmed_lines[i][0]] = []   #creating a list for the grades
        else:
            new_dict[trimmed_lines[i][0]] = 0.0   
    for lst in trimmed_lines:    
        for i in range(len(lst)):    #loops through the lines and their indexes once again
            if lst[0] == 'pa' or lst[0] == 'lab' or lst[0] == 'zy': 
                if i !=0:
                    new_dict[lst[0]].append(lst[i])  #using the indexes and their values to be added to the dict
            else:
                new_dict[lst[0]] = lst[1]   #if it's not list
    file.close()  #closing the file
    if project == True:
        for x,y in new_dict.items():  #looping through the keys and values
            if x != "name" and type(y) != float:    #checks to see if it's a name or num
                find_avg = sum(y)/len(y)    #finds the averages 
            if x == 'pa':         #findes out where to place the average
                length = len(y)
                while length < 9:    #using the length to add it to the right area
                    y.append(find_avg)
                    length += 1
            elif x == 'lab':
                length = len(y)
                while length < 11:
                    y.append(find_avg)  
                    length += 1
            elif x == 'zy':
                length = len(y)
                while length < 15:
                    y.append(find_avg)
                    length += 1
    return new_dict
    
    
    
def write_grades_file(filename, grades):
    file = open(filename, 'w')   #opening the file to write in it 
    for k,v in grades.items():   #looping through
        if type(v) == list:    #checks to see if it's list or string
            file.write(k + ', ')   #adding the , and space
            for i in range(len(v)):    #using the index of the values
                if(i != len(v)-1):    
                    file.write(str(v[i]) + ', ')   #checking the length while adding it to the doc
                else:
                    file.write(str(v[i]) + '\n')
        elif k != 'final':
            file.write(k + ', ' +str(v) + '\n')    #for finial and if not list
        else:
            file.write(k + ', ' + str(v) )    #if it's anything else thats not a list or it;s finial 
    file.close()












