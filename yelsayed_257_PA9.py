#------------------------------------------------------------------------------- # YOUSEF ELSAYED: George Mason
# Assignment 9
# Due Date: 04/1/2022 #------------------------------------------------------------------------------- # Honor Code Statement: I received no assistance on this assignment that
# violates the ethical guidelines set forth by professor and class syllabus. #-------------------------------------------------------------------------------
# References: (Professor, Self) #-------------------------------------------------------------------------------
# Comments and assumptions: A note to the grader as to any problems or
# uncompleted aspects of the assignment, as well as any assumptions about the
# meaning of the specification. #-------------------------------------------------------------------------------
# NOTE: width of source code should be <=80 characters to be readable on-screen. #2345678901234567890123456789012345678901234567890123456789012345678901234567890
# 10 20 30 40 50 60 70 80 #-------------------------------------------------------------------------------

class Criminal:

    def __init__(self, name, num_fraud, num_assault, num_murder, victims):
        self.name = name   #name for the criminal
        self.num_fraud = num_fraud  # number of fraud charges
        self.num_assault = num_assault #number of assault charges
        self.num_murder = num_murder   #numer of murder charges
        self.victims = victims   #the victims
        totol = self.num_fraud + self.num_assault + self.num_murder  
        if totol != len(self.victims):    #checks if the number of charges match the len of victims 
            raise InfoError('No. of crimes and no. of victims must match!')   #raising an error
            
    
    def __str__(self):   # returns a string of the criminal and the charges with discribtions
        return 'Criminal ' + self.name + ': fraud ' + str(self.num_fraud) + ', assault ' + str(self.num_assault) + ', murder ' + str(self.num_murder) + '.'
        
    def add_crimes(self, crimes):   
        if type(crimes) != dict:  #checks if it's a dict 
            raise InfoError('Crime information must be in a dictionary.')
        for x,y in crimes.items():  #loops through the dictionary through keys n vals
            if x == 'fraud':   #checka using the key
                 for k in y:  # checks if the val is in victims
                    if k not in self.victims:  # checks if the val is in victims
                        self.num_fraud += 1  #adds to the amount of the charge
                        self.victims.append(k)  #adds to the victims list

            elif x == 'assault':   #checks with the key 
                for k in y:  # checks if the val is in victims
                    if k not in self.victims:    # checks if the val is in victims
                        self.num_assault += 1    #adds to the amount of the charge
                        self.victims.append(k)     #adds to the victims list

      
            elif x == 'murder':
                for k in y:
                    if k not in self.victims:
                        self.num_murder += 1
                        self.victims.append(k)

    def exonerate(self, crimes):
        if type(crimes) != dict:
            raise InfoError('Crime information must be in a dictionary.')
        for x,y in crimes.items():   #loops through the keys and values of crimes
            if x == 'fraud':    #checks with the key 
                 for k in y:       # checks if the val is in victims
                    if k in self.victims:      # checks if the val is in victims
                        self.num_fraud -= 1  #subtracks from the num of charges
                        self.victims.remove(k)  #removes from the list of victims 

            elif x == 'assault':
                for k in y:
                    if k in self.victims:    # checks if the val is in victims
                        self.num_assault -= 1    #subtracks from the num of charges
                        self.victims.remove(k)   #removes from the list of victims 
      
            elif x == 'murder':
                for k in y:
                    if k in self.victims:
                        self.num_murder -= 1 #subtracks from the num of charges
                        self.victims.remove(k)         #removes from the list of victims  
                        
                        
class InfoError(Exception):   
    def __init__(self, msg):   #initializing the instance 
        self.msg = msg   #the imputed message 
    def __str__(self):  #returning  the messages 
        return self.msg
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    