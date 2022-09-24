def calcAverage(data_dictionary):
    avg_grade = {}
    for g in data_dictionary.keys():
        sum = 0
        for k in data_dictionary[g]:
            sum += k
        avg = sum/len(data_dictionary[g])
        avg_grade[g] = round(avg,2)
    return avg_grade 
               
    