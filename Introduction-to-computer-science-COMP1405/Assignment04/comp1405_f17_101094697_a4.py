# ============================================================
#
# Student Name (as it appears on cuLearn): Khushal Kumar
# Student ID (9 digits in angle brackets): <101094697>
# Course Code (for this current semester): COMP1405A
#
# ============================================================

from comp1405_f17_assistant_a4 import *
if ask_question("Do you have hair? ").upper() == ("YES"):
	if ask_question('Do you smoke pipe? ').upper() ==("YES"):
		if ask_question('do you wear tattoo? ').upper()== ("YES"):
			if ask_question('do you wear glasses? ').upper()==("YES"):
				make_a_guess('Frances')
			else :
				make_a_guess('Julian')
		else :
			if ask_question('do you wear eyepatch? ').upper()==("YES") :
				make_a_guess('Spencer')
			else:
				make_a_guess('Emery')
	else :
		if ask_question('do you wear a tie? ').upper()==("YES"):
			if ask_question('Do you have moustache? ').upper()==("YES") :
				make_a_guess('Karter')
			else :
				make_a_guess('Toby')
		else :
			if  ask_question('do you wear eyepatch? ').upper()==("YES"):
				make_a_guess('Blake')
			else:
				make_a_guess('Hayden')
else :
	if ask_question('Do you wear hat? ').upper()==("YES") :
		if ask_question('Do you have earring? ').upper()==("YES") :
			if ask_question('Do you wear glasses? ').upper()==("YES") :
				make_a_guess('Harley')
			else:
				make_a_guess('Gray')
		else:	
			if ask_question('Do you wear pipe? ').upper()==("YES") :
				make_a_guess('Sydney')
			else:
				make_a_guess('London')
					
	else :
		if ask_question('Do you wear eyepatch? ').upper()==("YES") :
			if ask_question('Do you have moustache? ').upper()==("YES") :
				make_a_guess('Kelsey')
			else:
				make_a_guess('Hudson')
		else:
			if ask_question('Do you have tattoo? ').upper()==("YES") :
				make_a_guess('Elloit')
			else:
				make_a_guess('Pheonix')

















