def tickets(persons, iss_member):
	ticket_price = 0
	if iss_member == 'Ture':
		persons -= 5
		persons *= 5
		ticket_price = persons
		return ticket_price
	elif iss_member == 'False':
		if persons >= 7:
			persons *= 6
			ticket_price = persons
			return ticket_price
		else:
		    persons *= 9
		    ticket_price = persons
		    return ticket_price
	
def print_triangle(height):
    a = ""
    count = 1
    for i in range(height):
        for j in range(count):
            a += "*"
        a += "\n"
        count = count + 2
    return a
 
 
print(print_triangle(5))