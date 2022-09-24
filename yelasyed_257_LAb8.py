gnom = False
def isSequenceValid(s):
    global gnom
    if (s[0:3] == 'UAA' or s[0:3] == 'UAG' or s[0:3] == "UGA") and gnom == True:
        return  'valid' 
    if len(s) == 0:
        return 'invalid'
    if s[0:3] == 'AUG' and gnom == False :
        gnom = True
        return isSequenceValid(s[3:])
    return isSequenceValid(s[1:])


