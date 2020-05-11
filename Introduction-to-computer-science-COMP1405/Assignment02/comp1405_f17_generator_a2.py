from os import getcwd as O0OO0O0O00O0OO0OO ,listdir as OO00OOOO0000OO0O0 ,path as O0O000OO0O0OOOOOO ,remove as OO00OOO0OO0000O0O #line:2
from sys import argv as O0OOO00OOO00OOO0O #line:3
from zipfile import ZipFile as O00OOOOOO0000000O #line:4
CURRENT_CLASS_LIST_FILE ="current_class_list.dat"#line:7
LIST_OF_REQUISITE_FILES =[CURRENT_CLASS_LIST_FILE ]#line:8
LIST_OF_LIBRARY_MODULES =["_liberr.py","_libtui.py","_libprg.py",]#line:13

def clean_current_working_directory ():#line:22
	OOO00O0OO0OO0OO00 =OO00OOOO0000OO0O0 (O0OO0O0O00O0OO0OO ())#line:24
	for OO0O0OO0OO0000000 in OOO00O0OO0OO0OO00 :#line:27
		OOOO0O0O0OO0O0O0O =O0O000OO0O0OOOOOO .join (O0OO0O0O00O0OO0OO (),OO0O0OO0OO0000000 )#line:30
		if not O0O000OO0O0OOOOOO .isdir (OOOO0O0O0OO0O0O0O )and (OO0O0OO0OO0000000 in LIST_OF_REQUISITE_FILES or OO0O0OO0OO0000000 in LIST_OF_LIBRARY_MODULES ):#line:33
			OO00OOO0OO0000O0O (OO0O0OO0OO0000000 )#line:35

def exit_program ():#line:44
	clean_current_working_directory ()#line:45
	exit ()#line:46

def generate_assignment_instructions (OO00OOOO00O00OOOO ):#line:55
	import _libprg as _OO0OOOOO0OOO0O0OO #line:57
	_OO0OOOOO0OOO0O0OO .set_random_source (OO00OOOO00O00OOOO )#line:60
	OOO000OOOOO0OO00O =["Use the 'find' method to find the index of the leftmost <param_arb_value_a> (i.e., the index where the character '<param_arb_value_a>' first appears) in the command-line argument. Refer to docs.python.org/3/library/stdtypes.html#text-sequence-type-str for details about this method.","Use the 'rfind' method to find the index of the rightmost <param_arb_value_a> (i.e., the index where the character '<param_arb_value_a>' last appears) in the command-line argument. Refer to docs.python.org/3/library/stdtypes.html#text-sequence-type-str for details about this method.","Use the 'count' method to count the number of times the <param_arb_value_a> (i.e., the character <param_arb_value_a>) appears in the command-line argument and store this integer in a new variable. Refer to docs.python.org/3/library/stdtypes.html#text-sequence-type-str for details about this method.",]#line:66
	O000OOOO000O0OOO0 =["Add the next highest number to the variable. To clarify, if the variable had a value of 10 after step 8, add 11 to produce the sum 21. Store the result but do _NOT_ create a new variable.","Add the next lowest number to the variable. To clarify, if the variable had a value of 10 after step 8, add 9 to produce the sum 19. Store the result but do _NOT_ create a new variable.",]#line:71
	OOO00O0O0OO0OO000 =_OO0OOOOO0OOO0O0OO .get_random_integer (0 ,2 )#line:73
	OOO000OOOO000O0O0 =_OO0OOOOO0OOO0O0OO .get_random_integer (0 ,1 )#line:74
	OOO0000OO0OOO000O ={"<param_arb_step_04>":OOO000OOOOO0OO00O [OOO00O0O0OO0OO000 ],"<param_arb_step_10>":O000OOOO000O0OOO0 [OOO000OOOO000O0O0 ],}#line:79
	O00O00000O00O0O00 ={"<param_arb_index_i>":_OO0OOOOO0OOO0O0OO .get_random_integer (2 ,8 ),"<param_arb_value_a>":_OO0OOOOO0OOO0O0OO .get_random_element (['0','1','2','3','4','5','6','7','8','9','0']),"<param_arb_adden_x>":_OO0OOOOO0OOO0O0OO .get_random_integer (2 ,20 ),"<param_arb_subtr_y>":_OO0OOOOO0OOO0O0OO .get_random_integer (2 ,20 ),}#line:87
	OOOOO0O0O000OO00O ={"<param_der_adden_z>":97 -(float ((2 *O00O00000O00O0O00 ["<param_arb_adden_x>"])+([1 ,-1 ][OOO000OOOO000O0O0 ])-O00O00000O00O0O00 ["<param_arb_subtr_y>"])/2 ),}#line:91
	O0O0000OOO000O0OO =["0th","1st","2nd","3rd","4th","5th","6th","7th","8th","9th"]#line:93
	OOO0O0OO00OOOO0O0 =["If you import the sys module (using 'import sys' at the top of your program), then the command-line argument provided by the user when your program was started is stored as a string in the variable 'sys.argv[1]'. Convert the command-line argument into an integer using the 'int' function and store that value in a new variable. Do _NOT_ attempt to verify that the user provided a nine character string, that the characters are all digits, etc. Assume that the user will always provide valid command-line argument.","Counting from the right, retrieve the "+O0O0000OOO000O0OO [O00O00000O00O0O00 ["<param_arb_index_i>"]]+" digit of that integer. The "+O0O0000OOO000O0OO [O00O00000O00O0O00 ["<param_arb_index_i>"]]+" digit from the right would correspond to the position marked with an asterisk in "+("-"*(9 -O00O00000O00O0O00 ["<param_arb_index_i>"]))+"*"+("-"*(O00O00000O00O0O00 ["<param_arb_index_i>"]-1 ))+". Do _NOT_ use indexing or slicing (i.e., do not use (i.e., variable[index] or variable[start_of_slice:end_of_slice]) to accomplish this; you _MUST_ use the integer division and modulation operators. These operators will compute the floored quotient and remainder respectively. Refer to docs.python.org/3/library/stdtypes.html for details about these operators.","Print the result of step 2 to the terminal using the 'print' function.","<param_arb_step_04>","Print the result of step 4 to the terminal using the 'print' function.","Compute the sum of the results of steps 2 and 4 and store this integer in a new variable.","Print the result of step 6 to the terminal using the 'print' function.","Add <param_arb_adden_x> to the variable you created in step 6. Create a new variable and store the result.","Print the result of step 8 to the terminal using the 'print' function.","<param_arb_step_10>","Print the result of step 10 to the terminal using the 'print' function.","Subtract <param_arb_subtr_y> from the variable. Store the result but do _NOT_ create a new variable.","Print the result of step 12 to the terminal using the 'print' function.","Divide the value of the variable by 2. Store the result but do _NOT_ create a new variable. Note that you may need to use the 'float' function before dividing to accomplish this correctly.","Print the result of step 14 to the terminal using the 'print' function.","Subtract the value from step 6 from the variable. Store the result but do _NOT_ create a new variable.","Print the result of step 16 to the terminal using the 'print' function.","Add <param_der_adden_z> to the variable. The result should _ALWAYS_ be 97. Store the result as an integer but do _NOT_ create a new variable.","Use the 'chr' function and the 'upper' method to convert the variable value into an uppercase letter. The result should _ALWAYS_ be the character 'A'. Refer to docs.python.org/3/library/functions.html#chr for details about the 'chr' function and to docs.python.org/3/library/stdtypes.html#text-sequence-type-str for details about the 'upper' method.","Print the uppercase letter from step 19 to the terminal using the 'print' function.",]#line:116
	for OOO0O00O0O0OO00OO in range (len (OOO0O0OO00OOOO0O0 )):#line:118
		for O0000OO00O0O0O0O0 in OOO0000OO0OOO000O :#line:120
			OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ]=OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ].replace (O0000OO00O0O0O0O0 ,str (OOO0000OO0OOO000O [O0000OO00O0O0O0O0 ]))#line:121
		for O0000OO00O0O0O0O0 in O00O00000O00O0O00 :#line:123
			OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ]=OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ].replace (O0000OO00O0O0O0O0 ,str (O00O00000O00O0O00 [O0000OO00O0O0O0O0 ]))#line:124
		for O0000OO00O0O0O0O0 in OOOOO0O0O000OO00O :#line:126
			OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ]=OOO0O0OO00OOOO0O0 [OOO0O00O0O0OO00OO ].replace (O0000OO00O0O0O0O0 ,str (OOOOO0O0O000OO00O [O0000OO00O0O0O0O0 ]))#line:127
	return OOO0O0OO00OOOO0O0 #line:129

def main ():#line:140
	clean_current_working_directory ()#line:143
	try :#line:146
		with O00OOOOOO0000000O (O0OOO00OOO00OOO0O [0 ].replace ("generator","companion").replace (".py","._z"),"r")as O0000OO0000O00O00 :#line:147
			O0000OO0000O00O00 .extractall ()#line:148
	except :#line:149
		print ("")#line:150
		print ("     ┌─[ ERROR 00 ]───────────────────────────────────────────────────────┐     ")#line:151
		print ("     │                                                                    │     ")#line:152
		print ("     │ One of the files required by this generator could not be found.    │     ")#line:153
		print ("     │ When you downloaded the generator from cuLearn it was part of a    │     ")#line:154
		print ("     │ zip archive of three files - the generator, the validator, and     │     ")#line:155
		print ("     │ the companion. The generator cannot proceed because it cannot      │     ")#line:156
		print ("     │ locate the companion file. Redownload the archive from cuLearn     │     ")#line:157
		print ("     │ and then try running the generator again.                          │     ")#line:158
		print ("     │                                                                    │     ")#line:159
		print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:160
		print ("")#line:161
		exit_program ()#line:162
	import _liberr as _O0OOO0OO0O0O0O0O0 #line:165
	import _libtui as _OO0O0O0OO0000O000 #line:166
	_OO0O0O0OO0000O000 .clear_screen ()#line:169
	print ()#line:171
	print ("     ** PLEASE NOTE:  IF YOU FAIL TO FOLLOW THESE INSTRUCTIONS PRECISELY **     ")#line:172
	print ("     **               YOUR SUBMISSION WILL RECEIVE A FINAL MARK OF ZERO. **     ")#line:173
	print ()#line:174
	O00OO000O0O0O0OO0 =len (O0OOO00OOO00OOO0O )#line:177
	if O00OO000O0O0O0OO0 <2 :#line:178
		_OO0O0O0OO0000O000 .print_with_a_frame (_O0OOO0OO0O0O0O0O0 .get_error_message (_O0OOO0OO0O0O0O0O0 .ERROR_INSUFFICIENT_ARGUMENTS ))#line:179
		exit_program ()#line:180
	O0OOO0O00O0OOOO00 =O0OOO00OOO00OOO0O [1 ]#line:183
	if not (O0OOO0O00O0OOOO00 .isdigit ()and len (O0OOO0O00O0OOOO00 )==9 ):#line:184
		_OO0O0O0OO0000O000 .print_with_a_frame (_O0OOO0OO0O0O0O0O0 .get_error_message (_O0OOO0OO0O0O0O0O0 .ERROR_INVALID_STUDENT_NUMBER ))#line:185
		exit_program ()#line:186
	OO0OO0OO0OO0OO0OO =False #line:189
	for OO00000O0O0OO00OO in LIST_OF_REQUISITE_FILES :#line:190
		if not O0O000OO0O0OOOOOO .exists (OO00000O0O0OO00OO ):#line:191
			OO0OO0OO0OO0OO0OO =True #line:192
			break #line:193
	if OO0OO0OO0OO0OO0OO :#line:194
		_OO0O0O0OO0000O000 .print_with_a_frame (_O0OOO0OO0O0O0O0O0 .get_error_message (_O0OOO0OO0O0O0O0O0 .ERROR_REQUISITE_FILES_ABSENT ))#line:195
		exit_program ()#line:196
	O0OO00OOO0OOO0000 =open (CURRENT_CLASS_LIST_FILE ,"r")#line:199
	OOOOO000000OOO000 =O0OO00OOO0OOO0000 .read ().split ()#line:200
	O0OO00OOO0OOO0000 .close ()#line:201
	if O0OOO0O00O0OOOO00 not in OOOOO000000OOO000 :#line:204
		_OO0O0O0OO0000O000 .print_with_a_frame (_O0OOO0OO0O0O0O0O0 .get_error_message (_O0OOO0OO0O0O0O0O0 .ERROR_MISSING_STUDENT_NUMBER ))#line:205
	print ("     ┌─[ OVERVIEW ]───────────────────────────────────────────────────────┐     ")#line:208
	print ("     │                                                                    │     ")#line:209
	print ("     │ For this assignment you will create a program that takes a student │     ")#line:210
	print ("     │ number from the user (submitted as a command-line variable) and    │     ")#line:211
	print ("     │ uses that data as part of a longer process. Regardless of the      │     ")#line:212
	print ("     │ student number the user submits, the process that was assigned to  │     ")#line:213
	print ("     │ your student number will always eventually produce an uppercase    │     ")#line:214
	print ("     │ letter 'A' as its final result.                                    │     ")#line:215
	print ("     │                                                                    │     ")#line:216
	print ("     │ As a clarifying example, the process defined below would always    │     ")#line:217
	print ("     │ produce the number 3 as its final result.                          │     ")#line:218
	print ("     │                                                                    │     ")#line:219
	print ("     │ PLEASE NOTE THAT THIS PROCESS IS ONLY INCLUDED AS AN EXAMPLE!      │     ")#line:220
	print ("     │                                                                    │     ")#line:221
	print ("     │ THE PROCESS THAT HAS BEEN ASSIGNED SPECIFICALLY TO YOUR STUDENT    │     ")#line:222
	print ("     │ NUMBER HAS BEEN DESCRIBED BELOW IN THE 'INSTRUCTIONS' SECTION!     │     ")#line:223
	print ("     │                                                                    │     ")#line:224
	print ("     │  1. Convert the command line argument to an integer.               │     ")#line:225
	print ("     │                                                                    │     ")#line:226
	print ("     │  2. Double that integer and print it to the screen.                │     ")#line:227
	print ("     │                                                                    │     ")#line:228
	print ("     │  3. Add 9 to the result and print it to the screen.                │     ")#line:229
	print ("     │                                                                    │     ")#line:230
	print ("     │  4. Subtract 3 from the result and print it to the screen.         │     ")#line:231
	print ("     │                                                                    │     ")#line:232
	print ("     │  5. Divide the result by 2 and print it to the screen.             │     ")#line:233
	print ("     │                                                                    │     ")#line:234
	print ("     │  6. Subtract the original number from the result.                  │     ")#line:235
	print ("     │                                                                    │     ")#line:236
	print ("     │  7. Print the final result to the screen. (It should be 3).        │     ")#line:237
	print ("     │                                                                    │     ")#line:238
	print ("     │ Thus, if you were to run this program from the terminal you        │     ")#line:239
	print ("     │ would see the following:                                           │     ")#line:240
	print ("     │                                                                    │     ")#line:241
	print ("     │ > python3 comp1405_f17_#########_a2.py 123456789                   │     ")#line:242
	print ("     │ 246913578                                                          │     ")#line:243
	print ("     │ 246913587                                                          │     ")#line:244
	print ("     │ 246913584                                                          │     ")#line:245
	print ("     │ 123456792                                                          │     ")#line:246
	print ("     │ 3                                                                  │     ")#line:247
	print ("     │                                                                    │     ")#line:248
	print ("     │ Your first seven lines of your submission must be a completed      │     ")#line:249
	print ("     │ copy of the following header and it must be reproduced exactly.    │     ")#line:250
	print ("     │                                                                    │     ")#line:251
	print ("     │ Check cuLearn for a sample assignment header that you may copy.    │     ")#line:252
	print ("     │                                                                    │     ")#line:253
	print ("     │ # ============================================================     │     ")#line:254
	print ("     │ #                                                                  │     ")#line:255
	print ("     │ # Student Name (as it appears on cuLearn): ????? ?????             │     ")#line:256
	print ("     │ # Student ID (9 digits in angle brackets): <?????????>             │     ")#line:257
	print ("     │ # Course Code (for this current semester): COMP1405?               │     ")#line:258
	print ("     │ #                                                                  │     ")#line:259
	print ("     │ # ============================================================     │     ")#line:260
	print ("     │                                                                    │     ")#line:261
	print ("     │ Replace the questions marks in the sample with your name,          │     ")#line:262
	print ("     │ student ID, and the letter indicating the section of COMP1405      │     ")#line:263
	print ("     │ (i.e., A or B) in which you are enrolled. Please note that the     │     ")#line:264
	print ("     │ student number must be enclosed in the angle brackets. As a        │     ")#line:265
	print ("     │ clarifying example, if your name was Robert Collier, your          │     ")#line:266
	print ("     │ student ID was 123456789, and you were enrolled in section A,      │     ")#line:267
	print ("     │ then the first seven lines of your submission must be:             │     ")#line:268
	print ("     │                                                                    │     ")#line:269
	print ("     │ # ============================================================     │     ")#line:270
	print ("     │ #                                                                  │     ")#line:271
	print ("     │ # Student Name (as it appears on cuLearn): Robert Collier          │     ")#line:272
	print ("     │ # Student ID (9 digits in angle brackets): <123456789>             │     ")#line:273
	print ("     │ # Course Code (for this current semester): COMP1405A               │     ")#line:274
	print ("     │ #                                                                  │     ")#line:275
	print ("     │ # ============================================================     │     ")#line:276
	print ("     │                                                                    │     ")#line:277
	print ("     │ Your submission must also use a specific filename in order for it  │     ")#line:278
	print ("     │ to be located by the marking utility; your submission must have    │     ")#line:279
	print ("     │ filename 'comp1405_f17_#########_a2.py', with the number signs     │     ")#line:280
	print ("     │ replaced by your nine digit student number.                        │     ")#line:281
	print ("     │                                                                    │     ")#line:282
	print ("     │ There are also several additional restrictions on your program.    │     ")#line:283
	print ("     │ You must not use functions that are not explicitly permitted, and  │     ")#line:284
	print ("     │ the only library you may import is sys. This assignment does not   │     ")#line:285
	print ("     │ use pygame in any way.                                             │     ")#line:286
	print ("     │                                                                    │     ")#line:287
	print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:288
	OO000O0OOO000O000 =generate_assignment_instructions (O0OOO0O00O0OOOO00 )#line:291
	_OO0O0O0OO0000O000 .print_with_a_frame (("INSTRUCTIONS",OO000O0OOO000O000 ))#line:294
	print ()#line:296
	print ("     ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^     ")#line:297
	print ("     SCROLL UP TO THE OVERVIEW SECTION AND ENSURE YOU READ ALL INSTRUCTIONS     ")#line:298
	print ("     ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^     ")#line:299
	print ()#line:300
	exit_program ()#line:303

if __name__ =="__main__":#line:307
    main ()
