import ast as O0OOOO000000OOOOO #line:11
import datetime as O0OO0O0O0OOO0000O #line:12
import pygame as O00OO00OOOOO0OOOO #line:13
from subprocess import call as O0OOO0O0000O00OO0 #line:14
from os import getcwd as OOOOO0O0OOOOOOOO0 ,listdir as OOO00OO0OOOO0O00O ,path as OO000000OO0OOO00O ,remove as O00OOOO0O0O00O000 ,devnull as OOO00O0OO00O0O0O0 ,rename as O000O0OOO0OOO000O #line:15
from sys import argv as O0O0O0OO0OO00OOO0 ,exc_info as O0000OO00O000OO00 #line:16
from zipfile import ZipFile as OO00O0OOOOO00OO00 #line:17
from re import match as OOOO0O0O000O000O0 ,sub as O00O0O0000OO00O0O #line:18
from time import sleep as O0OO0OO0O0000O0O0 #line:19
CURRENT_CLASS_LIST_FILE ="initial_class_list.dat"#line:22
LIST_OF_TEMPORARY_FILES =["student_output.dat"]#line:23
LIST_OF_REQUISITE_FILES =[CURRENT_CLASS_LIST_FILE ]+["supplementary_data.dat"]#line:24
LIST_OF_LIBRARY_MODULES =["_liberr.py","_libtui.py","_libprg.py",]#line:29
'''
This will remove all the files that were extracted from the companion

@params                      none
@return                      none
'''#line:37
def clean_current_working_directory ():#line:38
	O0000O00O0O0OOOO0 =OOO00OO0OOOO0O00O (OOOOO0O0OOOOOOOO0 ())#line:40
	for O0OOO000OOOOO00O0 in O0000O00O0O0OOOO0 :#line:43
		OO0OO0O000OOOO00O =OO000000OO0OOO00O .join (OOOOO0O0OOOOOOOO0 (),O0OOO000OOOOO00O0 )#line:46
		if not OO000000OO0OOO00O .isdir (OO0OO0O000OOOO00O )and (O0OOO000OOOOO00O0 in LIST_OF_REQUISITE_FILES or O0OOO000OOOOO00O0 in LIST_OF_LIBRARY_MODULES or O0OOO000OOOOO00O0 in LIST_OF_TEMPORARY_FILES ):#line:49
			O00OOOO0O0O00O000 (O0OOO000OOOOO00O0 )#line:50
'''
This is end the program after cleaning the current working directory

@params                      none
@return                      none
'''#line:58
def exit_program ():#line:59
	clean_current_working_directory ()#line:60
	exit ()#line:61
'''
This will verify that the header is present and contains the required information

@params  submission_path     the path to the submission being evaluated
@params  id_in_filename      the id that appears in the filename, for comparison with the header
@return                      a boolean indicating whether the header is acceptable or not
'''#line:70
def validate_submission_header (OO0O0OO000O000O0O ,O000O00OOOOOOOO0O ):#line:71
	OO00OOO00O00OOOO0 =open (OO0O0OO000O000O0O ,"r")#line:74
	OO0O00OO00OOOOO00 =[]#line:77
	OO0OO00000O0OOOO0 =False #line:80
	while True :#line:83
		O0O00OO0O0O00O0OO =OO00OOO00O00OOOO0 .readline ()#line:86
		if not O0O00OO0O0O00O0OO :#line:89
			break #line:90
		if O0O00OO0O0O00O0OO .strip ()[:12 ]=="# ==========":#line:93
			if not OO0OO00000O0OOOO0 :#line:94
				OO0OO00000O0OOOO0 =True #line:95
			else :#line:96
				break #line:97
		if OO0OO00000O0OOOO0 :#line:100
			OO0O00OO00OOOOO00 .append (O0O00OO0O0O00O0OO .strip ())#line:101
	OO00OOO00O00OOOO0 .close ()#line:104
	OO00O0OO000OOO0O0 =None #line:107
	OO00O0OO0O0000OO0 =None #line:108
	O00OOO000OOOO0OO0 =""#line:109
	OOOOOOOOO0O00O0O0 =""#line:110
	for O0OOOOOOO0O00000O in OO0O00OO00OOOOO00 :#line:111
		O0OOOOOOO0O00000O =O0OOOOOOO0O00000O .strip ()#line:114
		if OO00O0OO000OOO0O0 is None :#line:117
			OO00O0OO000OOO0O0 =OOOO0O0O000O000O0 (r"# Student Name \(as it appears on cuLearn\): (.*$)",O0OOOOOOO0O00000O )#line:118
			if OO00O0OO000OOO0O0 is not None and len (O0OOOOOOO0O00000O )>0 :#line:119
				O00OOO000OOOO0OO0 =OO00O0OO000OOO0O0 .group (1 )#line:120
		if OO00O0OO0O0000OO0 is None :#line:122
			OO00O0OO0O0000OO0 =OOOO0O0O000O000O0 (r"# Student ID \(9 digits in angle brackets\): <(\d{9})>",O0OOOOOOO0O00000O )#line:123
			if OO00O0OO0O0000OO0 is not None :#line:124
				OOOOOOOOO0O00O0O0 =OO00O0OO0O0000OO0 .group (1 )#line:125
	if O00OOO000OOOO0OO0 is not None and len (O00OOO000OOOO0OO0 )>0 and OOOOOOOOO0O00O0O0 ==O000O00OOOOOOOO0O :#line:127
		return True ,O00OOO000OOOO0OO0 #line:128
	else :#line:129
		return False ,"Student Name Not Found"#line:130
'''
This will create the abstract syntax tree and process it into lists of features

@params  submission_path     the path to the submission being evaluated
@params  id_in_filename      the id that appears in the filename, for comparison with the header
@return                      the list of functions and modules used in the submission
'''#line:139
def review_submission_ast (OO0OO000000OOOO00 ,O000OOOOO00OO0OO0 ):#line:140
	O0000OO0O0000OO0O =open (OO0OO000000OOOO00 ,"r")#line:143
	OO00O00O00O0OOOO0 =O0000OO0O0000OO0O .read ()#line:146
	O0000OO0O0000OO0O .close ()#line:149
	O0O0O00OOOOO0000O =O0OOOO000000OOOOO .parse (OO00O00O00O0OOOO0 )#line:152
	OOOOOOO00OOOO0OOO =[]#line:155
	OOO00OOO00O0O00OO =[]#line:156
	for OO0OOO0OO0OOOO0O0 in O0OOOO000000OOOOO .walk (O0O0O00OOOOO0000O ):#line:159
		if isinstance (OO0OOO0OO0OOOO0O0 ,O0OOOO000000OOOOO .Import ):#line:162
			for OOOO00O0O00O0OOO0 in OO0OOO0OO0OOOO0O0 .names :#line:163
				O0O0O0OOO00O0O00O =str (OOOO00O0O00O0OOO0 .name )#line:164
				if O0O0O0OOO00O0O00O not in OOO00OOO00O0O00OO :#line:165
					OOO00OOO00O0O00OO .append (O0O0O0OOO00O0O00O )#line:166
		if isinstance (OO0OOO0OO0OOOO0O0 ,O0OOOO000000OOOOO .ImportFrom ):#line:169
			O0O0O0OOO00O0O00O =str (OO0OOO0OO0OOOO0O0 .module )#line:170
			if O0O0O0OOO00O0O00O not in OOO00OOO00O0O00OO :#line:171
				OOO00OOO00O0O00OO .append (O0O0O0OOO00O0O00O )#line:172
			for OOO00OO000OOO0OOO in OO0OOO0OO0OOOO0O0 .names :#line:173
				O00OO00OO00OO0O00 =str (OOO00OO000OOO0OOO .name )#line:174
				if O00OO00OO00OO0O00 not in OOOOOOO00OOOO0OOO :#line:175
					OOOOOOO00OOOO0OOO .append (O00OO00OO00OO0O00 )#line:176
		if isinstance (OO0OOO0OO0OOOO0O0 ,O0OOOO000000OOOOO .Call ):#line:179
			if isinstance (OO0OOO0OO0OOOO0O0 .func ,O0OOOO000000OOOOO .Name ):#line:180
				O00OO00OO00OO0O00 =str (OO0OOO0OO0OOOO0O0 .func .id )#line:181
			elif isinstance (OO0OOO0OO0OOOO0O0 .func ,O0OOOO000000OOOOO .Attribute ):#line:182
				O00OO00OO00OO0O00 =str (OO0OOO0OO0OOOO0O0 .func .attr )#line:183
			if O00OO00OO00OO0O00 not in OOOOOOO00OOOO0OOO :#line:184
				OOOOOOO00OOOO0OOO .append (O00OO00OO00OO0O00 )#line:185
	return OOOOOOO00OOOO0OOO ,OOO00OOO00O0O00OO #line:187
'''
This is the main function, primarily responsible for extracting files from the
companion archive and ensuring that the generator will actually able be able
to function with the arguments that have been provided

@params                      none
@return                      none
'''#line:197
def main ():#line:198
	clean_current_working_directory ()#line:201
	with OO00O0OOOOO00OO00 (O0O0O0OO0OO00OOO0 [0 ].replace ("validator","companion").replace (".py","._z"),"r")as OOO00OOOOOO0OOO0O :#line:205
		OOO00OOOOOO0OOO0O .extractall ()#line:206
	import _libprg as _O00000000OO0O0O0O #line:209
	OOO0O00O0O0OOOO0O =open (OOO00O0OO00O0O0O0 ,'w')#line:212
	OO0O0OO00OOOO0OOO =OOO00OO0OOOO0O00O (OOOOO0O0OOOOOOOO0 ())#line:215
	OO000O0OO0O0OO00O =False #line:218
	for O0O000O00OO0O0O00 in OO0O0OO00OOOO0OOO :#line:221
		OOO0O0O0000000O0O =OOOO0O0O000O000O0 (r"comp1405_f17_(\d{9})_a1.py",O0O000O00OO0O0O00 )#line:224
		if OOO0O0O0000000O0O is not None :#line:227
			OO000O0OO0O0OO00O =True #line:230
			OO00OOO000OOOO0OO =O0O000O00OO0O0O00 #line:233
			O0O0OOO000O0OO000 =OOO0O0O0000000O0O .group (1 )#line:236
			OOO0000OO0O0OO00O ,O0O0OO0000O0OO0OO =validate_submission_header (OO00OOO000OOOO0OO ,O0O0OOO000O0OO000 )#line:239
			if OOO0000OO0O0OO00O :#line:241
				try :#line:244
					try :#line:247
						O000O0OOO0OOO000O (O0O0OOO000O0OO000 +".png",O0O0OOO000O0OO000 +".png."+O0OO0O0O0OOO0000O .datetime .now ().strftime ("%m%d%Y%H%M%S"))#line:248
					except :#line:250
						pass #line:251
					O0O00OO00O0O0OOOO ="python3 "+OO00OOO000OOOO0OO #line:254
					OOOOO0O000O0OO000 =O0OOO0O0000O00OO0 (O0O00OO00O0O0OOOO ,shell =True ,stderr =OOO0O00O0O0OOOO0O )#line:255
					if not OOOOO0O000O0OO000 ==0 :#line:258
						print ("")#line:259
						print ("     ┌─[ ERROR 99 ]───────────────────────────────────────────────────────┐     ")#line:260
						print ("     │                                                                    │     ")#line:261
						print ("     │ A file with the expected filename was found but when the validator │     ")#line:262
						print ("     │ attempted to run that program, it crashed. Ensure that the source  │     ")#line:263
						print ("     │ file you have been working on was named correctly and does not     │     ")#line:264
						print ("     │ crash on execution.                                                │     ")#line:265
						print ("     │                                                                    │     ")#line:266
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:267
						print ("")#line:268
					else :#line:269
						O000O00OOOOOO00O0 =None #line:271
						try :#line:272
							O000O00OOOOOO00O0 =O00OO00OOOOO0OOOO .image .load (O0O0OOO000O0OO000 +".png")#line:273
						except :#line:274
							pass #line:275
						if O000O00OOOOOO00O0 is not None :#line:278
							O0OOOOOOO0O0O000O =O000O00OOOOOO00O0 .get_size ()#line:280
							if not O0OOOOOOO0O0O000O ==(48 ,56 ):#line:282
								print ("")#line:283
								print ("     ┌─[ ERROR 98 ]───────────────────────────────────────────────────────┐     ")#line:284
								print ("     │                                                                    │     ")#line:285
								print ("     │ A file with the expected filename was found and executed by the    │     ")#line:286
								print ("     │ validator, but the image created by that program was not 48 x 56.  │     ")#line:287
								print ("     │ Examine your source code and ensure you are calling the set_mode   │     ")#line:288
								print ("     │ function correctly.                                                │     ")#line:289
								print ("     │                                                                    │     ")#line:290
								print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:291
								print ("")#line:292
						else :#line:293
							print ("")#line:294
							print ("     ┌─[ ERROR 97 ]───────────────────────────────────────────────────────┐     ")#line:295
							print ("     │                                                                    │     ")#line:296
							print ("     │ A file with the expected filename was found and executed by the    │     ")#line:297
							print ("     │ validator, but that program did not save a png image with the      │     ")#line:298
							print ("     │ expected filename.                                                 │     ")#line:299
							print ("     │                                                                    │     ")#line:300
							print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:301
							print ("")#line:302
				except :#line:304
					print (O0000OO00O000OO00 ())#line:305
					O0O0O0OOO0OO00000 =0 #line:306
				O000O00O0O00O0O00 =["init","set_mode","fill","polygon","save","update"]#line:309
				O0O000OO0O0O0OO0O =["pygame"]#line:312
				OO000OOOO0O00O0OO ,O00OOOOOO0OO0O0OO =review_submission_ast (OO00OOO000OOOO0OO ,O0O0OOO000O0OO000 )#line:315
				for OO000OO000O0OO00O in OO000OOOO0O00O0OO :#line:318
					if OO000OO000O0OO00O not in O000O00O0O00O0O00 :#line:319
						print ("")#line:320
						print ("     ┌─[ ERROR 96 ]───────────────────────────────────────────────────────┐     ")#line:321
						print ("     │                                                                    │     ")#line:322
						print ("     │ A file with the expected filename was found and executed by the    │     ")#line:323
						print ("     │ validator, but that program used a function that was not           │     ")#line:324
						print ("     │ permitted. For this assignment you can only use the init, fill,    │     ")#line:325
						print ("     │ polygon, save, set_mode, and update functions.                     │     ")#line:326
						print ("     │                                                                    │     ")#line:327
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:328
						print ("")#line:329
				for OO000OO000O0OO00O in O00OOOOOO0OO0O0OO :#line:331
					if OO000OO000O0OO00O not in O0O000OO0O0O0OO0O :#line:332
						print ("")#line:333
						print ("     ┌─[ ERROR 95 ]───────────────────────────────────────────────────────┐     ")#line:334
						print ("     │                                                                    │     ")#line:335
						print ("     │ A file with the expected filename was found and executed by the    │     ")#line:336
						print ("     │ validator, but that program imported a module that was not         │     ")#line:337
						print ("     │ permitted. For this assignment you can only import the pygame      │     ")#line:338
						print ("     │ library.                                                           │     ")#line:339
						print ("     │                                                                    │     ")#line:340
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:341
						print ("")#line:342
				if "polygon"not in OO000OOOO0O00O0OO :#line:344
					print ("")#line:345
					print ("     ┌─[ ERROR 94 ]───────────────────────────────────────────────────────┐     ")#line:346
					print ("     │                                                                    │     ")#line:347
					print ("     │ A file with the expected filename was found and executed by the    │     ")#line:348
					print ("     │ validator, but that program does not appear to use the polygon     │     ")#line:349
					print ("     │ function and this function is required to complete the assignment. │     ")#line:350
					print ("     │                                                                    │     ")#line:351
					print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:352
					print ("")#line:353
				if "save"not in OO000OOOO0O00O0OO :#line:354
					print ("")#line:355
					print ("     ┌─[ ERROR 93 ]───────────────────────────────────────────────────────┐     ")#line:356
					print ("     │                                                                    │     ")#line:357
					print ("     │ A file with the expected filename was found and executed by the    │     ")#line:358
					print ("     │ validator, but that program does not appear to use the save        │     ")#line:359
					print ("     │ function and this function is required to complete the assignment. │     ")#line:360
					print ("     │                                                                    │     ")#line:361
					print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:362
					print ("")#line:363
			else :#line:365
				print ("")#line:366
				print ("     ┌─[ ERROR 92 ]───────────────────────────────────────────────────────┐     ")#line:367
				print ("     │                                                                    │     ")#line:368
				print ("     │ A file with the expected filename was found and executed by the    │     ")#line:369
				print ("     │ validator, but that program does not appear to include a valid     │     ")#line:370
				print ("     │ header. Reread the instructions provided to you by the generator   │     ")#line:371
				print ("     │ and make sure you follow the header instructions precisely. If     │     ")#line:372
				print ("     │ your header does not exactly match the one that was specified in   │     ")#line:373
				print ("     │ the instructions, the marking program will not be able to find     │     ")#line:374
				print ("     │ your submission and it will receive a mark of 0.                   │     ")#line:375
				print ("     │                                                                    │     ")#line:376
				print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:377
				print ("")#line:378
	if not OO000O0OO0O0OO00O :#line:381
		print ("")#line:382
		print ("     ┌─[ ERROR 91 ]───────────────────────────────────────────────────────┐     ")#line:383
		print ("     │                                                                    │     ")#line:384
		print ("     │ A file with the expected filename was not found. Your submission   │     ")#line:385
		print ("     │ must be contained in a file named 'comp1405_f17_#########_a1.py'   │     ")#line:386
		print ("     │ with the number signs replaced by your nine digit student number.  │     ")#line:387
		print ("     │                                                                    │     ")#line:388
		print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:389
		print ("")#line:390
	exit_program ()#line:393
''' the (only) "top-level" code in the generator for calling main() '''#line:396
if __name__ =="__main__":#line:397
	print ()#line:398
	print ("     THIS PROGRAM WILL NOW REVIEW YOUR SUBMISSION LOOKING FOR COMMON ERRORS     ")#line:399
	print ("     (e.g., INCORRECT FILENAME, MISSING OR INVALID ASSIGNMENT HEADER, etc.)     ")#line:400
	print ()#line:401
	print ("     THIS PROGRAM WILL NOTIFY YOU IF IT DETECTS ANY OF THESE ISSUES, BUT IT     ")#line:402
	print ("     IS NOT 'PRE-MARKING' YOUR SUBMISSION AND IT DOES NOT DETECT ALL ERRORS     ")#line:403
	print ()#line:404
	print ("     IF NO SUCH ISSUES ARE DETECTED THEN NO NOTIFICATIONS WILL BE DISPLAYED     ")#line:405
	print ()#line:406
	main ()