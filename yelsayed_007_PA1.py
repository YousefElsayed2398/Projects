#------------------------------------------------------------------------------- # YOUSEF ELSAYED: George Mason
# Assignment 1
# Due Date: 02/07/2022 #------------------------------------------------------------------------------- # Honor Code Statement: I received no assistance on this assignment that
# violates the ethical guidelines set forth by professor and class syllabus. #-------------------------------------------------------------------------------
# References: (Professor, Self) #-------------------------------------------------------------------------------
# Comments and assumptions: A note to the grader as to any problems or
# uncompleted aspects of the assignment, as well as any assumptions about the
# meaning of the specification. #-------------------------------------------------------------------------------
# NOTE: width of source code should be <=80 characters to be readable on-screen. #2345678901234567890123456789012345678901234567890123456789012345678901234567890
# 10 20 30 40 50 60 70 80 #-------------------------------------------------------------------------------



print('Sage\'s Wedding Cake Price Calculator')  

total_ppl = int(input('Total People Attending: '))

amount_of_cake = total_ppl / 30

hour_rate = 15.00       #rate for baker
consult_rate = 12.50    #rate for consultant
    
baker_hours = amount_of_cake * 15 * hour_rate   #takes the amount of cake needed X the hours it takes to make cake A X the rate of baker
conslt_hours = 1 * amount_of_cake * consult_rate   #the amount that you pay the consultant
ccakes = amount_of_cake * 35
cakeA_labor = round(baker_hours + conslt_hours,3)
cakeA_labor = round(baker_hours + conslt_hours,2)  #calculates the labor cost of the baker and consultant
cost_A = round(cakeA_labor + ccakes,3)
cost_A = round(cakeA_labor + ccakes,2)          #calculates the cost to make the cake by using the cost of labor and cost of the ingredients
calc = cost_A * .10
charge_A = round(calc + cost_A,3)          #finial the cost to charge the customer including labor, ingredients, 10% charge rate 
charge_A = round(calc + cost_A,2)
print('----------------------------------------')

print('Cake A') 
print('Labor Cost:     \t''$' + str(cakeA_labor))
print('Cost to Make:   \t''$' + str(cost_A))
print('Charge Customer: \t''$' + str(charge_A))


baker_hoursB = amount_of_cake * 14 * hour_rate     #calculating the amount the backer will be paid 
conslt_hoursB = amount_of_cake * 2 * consult_rate 
   #calculating the amount the consultant will be paid 
bcake = amount_of_cake * 30           #calculating that the ingredients will cost 
#cakeB_labor = round(baker_hoursB + conslt_hoursB, 3)
cakeB_labor = round(baker_hoursB + conslt_hoursB, 2)
cost_B = round(cakeB_labor + bcake,3)  
cost_B = round(cakeB_labor + bcake,2)                  #how much the cake will cost to make 
calc = cost_B * .10                          #how much the cake will cost after labor, ingredients, 10% charge rate

charge_B = round(calc + cost_B,3)
charge_B = round(calc + cost_B,2)

print('----------------------------------------')

print('Cake B') 
print('Labor Cost:     \t''$' + str(cakeB_labor))
print('Cost to Make:   \t''$' + str(cost_B))
print('Charge Customer: \t''$'+ str(charge_B))



baker_hoursC = amount_of_cake * 16 * hour_rate     #calculating the amount the backer will be paid 
conslt_hoursC = amount_of_cake * 1.5 * consult_rate #calculating the amount the consultant will be paid 
cakeC =amount_of_cake * 40                        #calculating that the ingredients will cost 
#cakeC_labor = round(baker_hoursC + conslt_hoursC,3)      #cost of labor of cake 
cakeC_labor = round(baker_hoursC + conslt_hoursC,2)
#cost_C = round(cakeC_labor + cakeC,3)
cost_C = round(cakeC_labor + cakeC,2)  #cost of cake ingredients  and lobor  
calc = cost_C * .10
charge_C = round(calc + cost_C, 3)             #finial the cost to charge the customer including labor, ingredients, 10% charge rate 
charge_C = round(calc + cost_C, 2)    
print('----------------------------------------')

print('Cake C') 
print('Labor Cost:     \t''$' + str(cakeC_labor))
print('Cost to Make:   \t''$' + str(cost_C))
print('Charge Customer: \t''$' + str(charge_C))


