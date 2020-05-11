# ============================================================
#
# Student Name (as it appears on cuLearn): Khushal Kumar
# Student ID (9 digits in angle brackets): <101094697>
# Course Code (for this current semester): COMP1405A
#
# ============================================================

from comp1405_f17_assistant_a5 import *

pointer = True
while pointer:
	move_down()	
	if am_i_standing_on(4):
		pointer = False 
while am_i_standing_on(1) == False :
	move_right()
pointer = True
while pointer:
	move_down()
	if what_number_am_i_standing_on() == 4:
		pointer = False
pointer = True
while pointer :
	move_left()
	if am_i_standing_on(1):
		break
for pointer in range(18) :
	move_down()
while not what_number_am_i_standing_on() == 1 :
	move_right()	

for pointer in range(22) :
	move_down()
while pointer:
	if what_number_am_i_standing_on() == 1 :
		break
	else:
		move_left()
for pointer in range(5) :
	move_down()






	
	

		

		



	

