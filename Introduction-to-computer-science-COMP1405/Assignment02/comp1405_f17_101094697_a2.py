# ============================================================
#                                                             
# Student Name (as it appears on cuLearn): Khushal Kumar    
# Student ID (9 digits in angle brackets): <101094697>        
# Course Code (for this current semester): COMP1405A          
#                                                             
# ============================================================



import sys
convert=int(sys.argv[1])
fdfr=((convert//1000)%10)
print('fourth digit from right is',fdfr)
i=str.find(sys.argv[1],'0')
print('the index of leftmost 0 character  is',i)
sm=fdfr+i
print('the sum of step 2 and step 4 is',sm)
new_var=sm+6
print('the value of new variable is',new_var)
new_var = new_var+(new_var-1)
print('the new value of new variable is',new_var)
new_var=new_var-20
print('value of new variable after subtracting 20 is',new_var)
new_var=float(new_var/2)
print('value of new variable after dividing it by 2 is',new_var)
new_var=new_var-sm
print('the remaining value of new variable after subtracting sum from step 6 is',new_var)
new_var=int(new_var+101.5)
new_var= chr(new_var).upper()
print(new_var)



