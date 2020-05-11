import pygame as O00000O0OO00OOO0O #line:2
from pygame .locals import *#line:3
from os import getcwd as O0OO0O0OOO00000O0 ,listdir as OOOO0O0O0O0OOO0O0 ,path as OO000OO0OO0OO0OO0 ,remove as O000OO0O00O0O00OO #line:5
from sys import argv as OO00O0OO00OOO00O0 #line:6
from zipfile import ZipFile as O0O0O0O0000OOO00O #line:7
from time import sleep as O0O0000O0OOOOO0OO #line:8
CURRENT_CLASS_LIST_FILE ="initial_class_list.dat"#line:12
LIST_OF_REQUISITE_FILES =[CURRENT_CLASS_LIST_FILE ]+["supplementary_data.dat"]#line:13
LIST_OF_LIBRARY_MODULES =["_liberr.py","_libtui.py","_libprg.py"]#line:18
'''
This will remove all the files that were extracted from the companion

@params                      none
@return                      none
'''#line:26
def clean_current_working_directory ():#line:27
	OOO0O00O00O00000O =OOOO0O0O0O0OOO0O0 (O0OO0O0OOO00000O0 ())#line:29
	for OO0O00O0OOO00OOO0 in OOO0O00O00O00000O :#line:32
		OO0O000OOO00O0OOO =OO000OO0OO0OO0OO0 .join (O0OO0O0OOO00000O0 (),OO0O00O0OOO00OOO0 )#line:35
		if not OO000OO0OO0OO0OO0 .isdir (OO0O000OOO00O0OOO )and (OO0O00O0OOO00OOO0 in LIST_OF_REQUISITE_FILES or OO0O00O0OOO00OOO0 in LIST_OF_LIBRARY_MODULES ):#line:38
			O000OO0O00O0O00OO (OO0O00O0OOO00OOO0 )#line:40
'''
This is end the program after cleaning the current working directory

@params                      none
@return                      none
'''#line:48
def exit_program ():#line:49
	clean_current_working_directory ()#line:50
	exit ()#line:51
'''
This is the actual instruction generator that is specific to this assignment

@params                      none
@return                      none
'''#line:59
def generate_assignment_instructions (O0OOO00O000OO0OO0 ):#line:60
	import _libprg as _OOOOO0OO0O0O0O000 #line:62
	OO0OO000O0OO0OO00 =48 #line:64
	OO0O00O0OO0O00OOO =56 #line:65
	O00O0OOOO0OOO0OO0 =open ("initial_class_list.dat","r")#line:71
	OO00OOO0O000OO000 =0 #line:72
	while True :#line:73
		OO00O0O0OO000OOOO =O00O0OOOO0OOO0OO0 .readline ().strip ()#line:74
		OO00OOO0O000OO000 +=1 #line:75
		if not OO00O0O0OO000OOOO or OO00O0O0OO000OOOO ==O0OOO00O000OO0OO0 :#line:77
			break #line:78
	O00O0OOOO0OOO0OO0 .close ()#line:79
	if not OO00O0O0OO000OOOO :#line:81
		OO00OOO0O000OO000 =0 #line:82
	OOOO00O0O0000O0O0 =open ("supplementary_data.dat",encoding ='utf-8')#line:86
	OOO00OO0O00OO00OO =OO00OOO0O000OO000 *OO0OO000O0OO0OO00 *OO0O00O0OO0O00OOO #line:87
	for _O00O0O0O0O0O00O00 in range (OOO00OO0O00OO00OO ):#line:88
		_O00O0O0O0O0O00O00 =OOOO00O0O0000O0O0 .read (3 )#line:89
	O00000O0OO00OOO0O .init ()#line:91
	OOO0OOO0OOOO0O0O0 =O00000O0OO00OOO0O .display .set_mode ((OO0OO000O0OO0OO00 *5 ,OO0O00O0OO0O00OOO *5 ))#line:92
	O00O0O0OOOOO0OO0O =O00000O0OO00OOO0O .Surface ((OO0OO000O0OO0OO00 ,OO0O00O0OO0O00OOO ))#line:93
	O00O0O0OOOOO0OO0O .fill ((0 ,0 ,0 ))#line:94
	O00O0O0OOOOO0OO0O =O00O0O0OOOOO0OO0O .convert ()#line:95
	OO000O0OO0OO0000O =0 #line:97
	OOO0000O0O000O00O =0 #line:98
	OOOOO000OO0OO0O0O ="right"#line:100
	O00OOOO0O000O00O0 =0 #line:102
	O00OOO0O00OOOO000 =(OO0OO000O0OO0OO00 -1 )#line:103
	O00OOO00OO00OO000 =1 #line:104
	OO0O00O00O000OO00 =(OO0O00O0OO0O00OOO -1 )#line:105
	for OO0OOO00OOOO0O0OO in range (OO0OO000O0OO0OO00 *OO0O00O0OO0O00OOO ):#line:107
		OOOO0O000OOOO0OOO =OOOO00O0O0000O0O0 .read (3 )#line:109
		(OO0O0OOOOO00OO0O0 ,OO00OOO00O0O00O0O ,OOOO0O00OO00O0O00 )=[ord (OO0OOOOO0OOO000OO )for OO0OOOOO0OOO000OO in OOOO0O000OOOO0OOO ]#line:110
		O00O0O0OOOOO0OO0O .set_at ((OO000O0OO0OO0000O ,OOO0000O0O000O00O ),(OO0O0OOOOO00OO0O0 ,OO00OOO00O0O00O0O ,OOOO0O00OO00O0O00 ))#line:112
		if OOOOO000OO0OO0O0O =="right":#line:114
			OO000O0OO0OO0000O =OO000O0OO0OO0000O +1 #line:115
			if OO000O0OO0OO0000O ==O00OOO0O00OOOO000 :#line:116
				O00OOO0O00OOOO000 =O00OOO0O00OOOO000 -1 #line:117
				OOOOO000OO0OO0O0O ='down'#line:118
		elif OOOOO000OO0OO0O0O =="down":#line:119
			OOO0000O0O000O00O =OOO0000O0O000O00O +1 #line:120
			if OOO0000O0O000O00O ==OO0O00O00O000OO00 :#line:121
				OO0O00O00O000OO00 =OO0O00O00O000OO00 -1 #line:122
				OOOOO000OO0OO0O0O ='left'#line:123
		elif OOOOO000OO0OO0O0O =="left":#line:124
			OO000O0OO0OO0000O =OO000O0OO0OO0000O -1 #line:125
			if OO000O0OO0OO0000O ==O00OOOO0O000O00O0 :#line:126
				O00OOOO0O000O00O0 =O00OOOO0O000O00O0 +1 #line:127
				OOOOO000OO0OO0O0O ='up'#line:128
		elif OOOOO000OO0OO0O0O =="up":#line:129
			OOO0000O0O000O00O =OOO0000O0O000O00O -1 #line:130
			if OOO0000O0O000O00O ==O00OOO00OO00OO000 :#line:131
				O00OOO00OO00OO000 =O00OOO00OO00OO000 +1 #line:132
				OOOOO000OO0OO0O0O ='right'#line:133
		if OO0OOO00OOOO0O0OO %10 ==0 :#line:135
			OOO0OOO0OOOO0O0O0 .blit (O00O0O0OOOOO0OO0O ,(0 ,0 ))#line:136
			O00000O0OO00OOO0O .display .flip ()#line:137
	OOOO00O0O0000O0O0 .close ()#line:139
	O00000O0OO00OOO0O .image .save (O00O0O0OOOOO0OO0O ,"your-assigned-image.png")#line:140
	O00O0O0OOOOO0OO0O =O00000O0OO00OOO0O .transform .scale (O00O0O0OOOOO0OO0O ,(OO0OO000O0OO0OO00 *5 ,OO0O00O0OO0O00OOO *5 ))#line:141
	OOO0OOO0OOOO0O0O0 .blit (O00O0O0OOOOO0OO0O ,(0 ,0 ))#line:142
	O00000O0OO00OOO0O .display .update ()#line:143
	OOO0OOO00O00OO0OO =["You must import and use the pygame library and you are not permitted to use any other libraries in your submission.","You may use the init, fill, polygon, save, set_mode, and update functions to complete this assignment. No other functions are permitted.","You must create a surface that is 48 pixels wide by 56 pixels high. If your image is not the correct size your submission is invalid.","You must use four calls to the pygame.draw.polygon function to create your shapes. No other shape or pixel drawing functions are permitted.","You must use the pygame.image.save function to save your image as a png file. You must use your student number as the filename, so you must save your drawing surface using '"+O0OOO00O000OO0OO0 +".png' as the filename.","The file 'your-assigned-image.png' has been created. This is image you are expected to reproduce, actual size. A window has also appeared, showing you a magnified (5x) copy of your assigned image. Close this window to end this program. Good luck!"]#line:155
	return OOO0OOO00O00OO0OO #line:157
'''
This is the main function, primarily responsible for extracting files from the
companion archive and ensuring that the generator will actually able be able
to function with the arguments that have been provided

@params                      none
@return                      none
'''#line:167
def main ():#line:168
	clean_current_working_directory ()#line:171
	try :#line:174
		with O0O0O0O0000OOO00O (OO00O0OO00OOO00O0 [0 ].replace ("generator","companion").replace (".py","._z"),"r")as O000O0O0OO000OO00 :#line:175
			O000O0O0OO000OO00 .extractall ()#line:176
	except :#line:177
		print ("")#line:178
		print ("     ┌─[ ERROR 00 ]───────────────────────────────────────────────────────┐     ")#line:179
		print ("     │                                                                    │     ")#line:180
		print ("     │ One of the files required by this generator could not be found.    │     ")#line:181
		print ("     │ When you downloaded the generator from cuLearn it was part of a    │     ")#line:182
		print ("     │ zip archive of three files - the generator, the validator, and     │     ")#line:183
		print ("     │ the companion. The generator cannot proceed because it cannot      │     ")#line:184
		print ("     │ locate the companion file. Redownload the archive from cuLearn     │     ")#line:185
		print ("     │ and then try running the generator again.                          │     ")#line:186
		print ("     │                                                                    │     ")#line:187
		print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:188
		print ("")#line:189
		exit_program ()#line:190
	import _liberr as _O0OOO0000000O0OO0 #line:193
	import _libtui as _O00OOOO00000O000O #line:194
	_O00OOOO00000O000O .clear_screen ()#line:197
	print ("     ** PLEASE NOTE:  IF YOU FAIL TO FOLLOW THESE INSTRUCTIONS PRECISELY **     ")#line:199
	print ("     **               YOUR SUBMISSION WILL RECEIVE A FINAL MARK OF ZERO. **     ")#line:200
	O000000000OOO0OOO =len (OO00O0OO00OOO00O0 )#line:203
	if O000000000OOO0OOO <2 :#line:204
		_O00OOOO00000O000O .print_with_a_frame (_O0OOO0000000O0OO0 .get_error_message (_O0OOO0000000O0OO0 .ERROR_INSUFFICIENT_ARGUMENTS ),False )#line:205
		exit_program ()#line:206
	O0OO0OO00OOOOOO0O =OO00O0OO00OOO00O0 [1 ]#line:209
	if not (O0OO0OO00OOOOOO0O .isdigit ()and len (O0OO0OO00OOOOOO0O )==9 ):#line:210
		_O00OOOO00000O000O .print_with_a_frame (_O0OOO0000000O0OO0 .get_error_message (_O0OOO0000000O0OO0 .ERROR_INVALID_STUDENT_NUMBER ),False )#line:211
		exit_program ()#line:212
	O00O0O00000O0OOOO =False #line:215
	for O0OO00O0O0OO0OOO0 in LIST_OF_REQUISITE_FILES +LIST_OF_LIBRARY_MODULES :#line:216
		if not OO000OO0OO0OO0OO0 .exists (O0OO00O0O0OO0OOO0 ):#line:217
			O00O0O00000O0OOOO =True #line:218
			break #line:219
	if O00O0O00000O0OOOO :#line:220
		_O00OOOO00000O000O .print_with_a_frame (_O0OOO0000000O0OO0 .get_error_message (_O0OOO0000000O0OO0 .ERROR_REQUISITE_FILES_ABSENT ),False )#line:221
		exit_program ()#line:222
	O0O000O0OO0OOO0O0 =open (CURRENT_CLASS_LIST_FILE ,"r")#line:225
	O0OO0O0O000000000 =O0O000O0OO0OOO0O0 .read ().split ()#line:226
	O0O000O0OO0OOO0O0 .close ()#line:227
	if O0OO0OO00OOOOOO0O not in O0OO0O0O000000000 :#line:230
		_O00OOOO00000O000O .print_with_a_frame (_O0OOO0000000O0OO0 .get_error_message (_O0OOO0000000O0OO0 .ERROR_MISSING_STUDENT_NUMBER ),False )#line:231
	print ("     ┌─[ OVERVIEW ]───────────────────────────────────────────────────────┐     ")#line:234
	print ("     │                                                                    │     ")#line:235
	print ("     │ For this assignment you will create a program that uses the        │     ")#line:236
	print ("     │ pygame library to reproduce the image that has been assigned to    │     ")#line:237
	print ("     │ you. This image has been magnified and made to appear on your      │     ")#line:238
	print ("     │ screen and it has also been saved to your computer as 'your-       │     ")#line:239
	print ("     │ assigned-image.png'. Your facsimile must use exactly the same      │     ")#line:240
	print ("     │ colours and fit on a surface that is 48 pixels wide and 56         │     ")#line:241
	print ("     │ pixels high. The mark you received on this assignment will be      │     ")#line:242
	print ("     │ determined by how accurately you have reproduced your assigned     │     ")#line:243
	print ("     │ image.                                                             │     ")#line:244
	print ("     │                                                                    │     ")#line:245
	print ("     │ Your first seven lines of your submission must be a completed      │     ")#line:246
	print ("     │ copy of the following header and it must be reproduced exactly.    │     ")#line:247
	print ("     │                                                                    │     ")#line:248
	print ("     │ # ============================================================     │     ")#line:249
	print ("     │ #                                                                  │     ")#line:250
	print ("     │ # Student Name (as it appears on cuLearn): ????? ?????             │     ")#line:251
	print ("     │ # Student ID (9 digits in angle brackets): <?????????>             │     ")#line:252
	print ("     │ # Course Code (for this current semester): COMP1405?               │     ")#line:253
	print ("     │ #                                                                  │     ")#line:254
	print ("     │ # ============================================================     │     ")#line:255
	print ("     │                                                                    │     ")#line:256
	print ("     │ Replace the questions marks in the sample with your name,          │     ")#line:257
	print ("     │ student ID, and the letter indicating the section of COMP1405      │     ")#line:258
	print ("     │ (i.e., A or B) in which you are enrolled. Please note that the     │     ")#line:259
	print ("     │ student number must be enclosed in the angle brackets. As a        │     ")#line:260
	print ("     │ clarifying example, if your name was Robert Collier, your          │     ")#line:261
	print ("     │ student ID was 123456789, and you were enrolled in section A,      │     ")#line:262
	print ("     │ then the first seven lines of your submission must be:             │     ")#line:263
	print ("     │                                                                    │     ")#line:264
	print ("     │ # ============================================================     │     ")#line:265
	print ("     │ #                                                                  │     ")#line:266
	print ("     │ # Student Name (as it appears on cuLearn): Robert Collier          │     ")#line:267
	print ("     │ # Student ID (9 digits in angle brackets): <123456789>             │     ")#line:268
	print ("     │ # Course Code (for this current semester): COMP1405A               │     ")#line:269
	print ("     │ #                                                                  │     ")#line:270
	print ("     │ # ============================================================     │     ")#line:271
	print ("     │                                                                    │     ")#line:272
	print ("     │ Your submission must also use a specific filename in order for it  │     ")#line:273
	print ("     │ to be located by the marking utility; your submission must have    │     ")#line:274
	print ("     │ filename 'comp1405_f17_#########_a1.py', with the number signs     │     ")#line:275
	print ("     │ replaced by your nine digit student number.                        │     ")#line:276
	print ("     │                                                                    │     ")#line:277
	print ("     │ There are also several additional restrictions on how you must     │     ")#line:278
	print ("     │ reproduce your assigned image. See the instructions listed below.  │     ")#line:279
	print ("     │                                                                    │     ")#line:280
	print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:281
	OOOOOO00O0OOO0OO0 =generate_assignment_instructions (O0OO0OO00OOOOOO0O )#line:285
	_O00OOOO00000O000O .print_with_a_frame (("INSTRUCTIONS",OOOOOO00O0OOO0OO0 ))#line:288
	print ()#line:290
	print ("     ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^     ")#line:291
	print ("     SCROLL UP TO THE OVERVIEW SECTION AND ENSURE YOU READ ALL INSTRUCTIONS     ")#line:292
	print ("     ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^     ")#line:293
	print ()#line:294
	O00OOOOO0000OOO00 =False #line:296
	while not O00OOOOO0000OOO00 :#line:297
		for O0000OO000O000O00 in O00000O0OO00OOO0O .event .get ():#line:298
			if O0000OO000O000O00 .type ==QUIT :#line:299
				O00OOOOO0000OOO00 =True #line:300
	exit_program ()#line:303
''' the (only) "top-level" code in the generator for calling main() '''#line:306
if __name__ =="__main__":#line:307
    main ()
