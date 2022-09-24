def calcSumList(student_list):
	list_of_calculated_sum = []
	totl = 0
	for k in range(len(student_list)):
	    for i in range(len(student_list[k])):
	        if i == 2:
	            for j in student_list[k][2]:
	                totl = j + totl
	            student_list.append(totl - 1)
	            student_list[k][2] = totl 
	            list_of_calculated_sum.append(student_list[k])
	return list_of_calculated_sum

                
