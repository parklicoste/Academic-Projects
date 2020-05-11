import ast as O0OO00O0O0O000000 #line:11
import datetime as OOOOO00O0000OO0OO #line:12
import pygame as O0OO0OO0OO0O0O00O #line:13
from subprocess import call as OO000O00OOO0OOO00 #line:14
from os import getcwd as OOOO00O0OOO00OO0O ,listdir as O00000OOO0O00O0OO ,path as O000000OOO0OOO0OO ,remove as OO0O000O00O0O000O ,devnull as O0OOOO00O00OO00O0 ,rename as O000O0OO00O0O0O0O #line:15
from sys import argv as OO00OOOOOOOOO000O ,exc_info as OO0O0OO0000000O0O #line:16
from zipfile import ZipFile as O00OOOOO00OO00O00 #line:17
from re import match as OOO00000OO0000OO0 ,sub as OO000O00000O0O0O0 #line:18
from time import sleep as O000O0O000O0O00OO #line:19
CURRENT_CLASS_LIST_FILE ="current_class_list.dat"#line:22
LIST_OF_REQUISITE_FILES =[CURRENT_CLASS_LIST_FILE ]#line:23
LIST_OF_LIBRARY_MODULES =["_liberr.py","_libtui.py","_libprg.py",]#line:28

def clean_current_working_directory ():#line:37
	O0OO0O0O0O0O0O000 =O00000OOO0O00O0OO (OOOO00O0OOO00OO0O ())#line:39
	for OOOOO00O0O0000OO0 in O0OO0O0O0O0O0O000 :#line:42
		O0O00OO00000000OO =O000000OOO0OOO0OO .join (OOOO00O0OOO00OO0O (),OOOOO00O0O0000OO0 )#line:45
		if not O000000OOO0OOO0OO .isdir (O0O00OO00000000OO )and (OOOOO00O0O0000OO0 in LIST_OF_REQUISITE_FILES or OOOOO00O0O0000OO0 in LIST_OF_LIBRARY_MODULES ):#line:48
			OO0O000O00O0O000O (OOOOO00O0O0000OO0 )#line:50

def exit_program ():#line:60
	clean_current_working_directory ()#line:61
	exit ()#line:62

def validate_submission_header (OO000O00OOO000OO0 ,O0O0OO0O00OOO00O0 ):#line:72
	OO0000OOOO00OOOOO =open (OO000O00OOO000OO0 ,"r")#line:75
	OOOOOO0OOOO0OOO00 =[]#line:78
	OO0000O0OO0O0OOOO =False #line:81
	while True :#line:84
		O0O00OO0O000O0000 =OO0000OOOO00OOOOO .readline ()#line:87
		if not O0O00OO0O000O0000 :#line:90
			break #line:91
		if O0O00OO0O000O0000 .strip ()[:12 ]=="# ==========":#line:94
			if not OO0000O0OO0O0OOOO :#line:95
				OO0000O0OO0O0OOOO =True #line:96
			else :#line:97
				break #line:98
		if OO0000O0OO0O0OOOO :#line:101
			OOOOOO0OOOO0OOO00 .append (O0O00OO0O000O0000 .strip ())#line:102
	OO0000OOOO00OOOOO .close ()#line:105
	OO0000O0OO0000000 =None #line:108
	OOO00OO0O0O0O0OO0 =None #line:109
	OOO00O0O000O0OOOO =""#line:110
	OOO00OOO0OO0OOOOO =""#line:111
	for O0O0O000O0O00O00O in OOOOOO0OOOO0OOO00 :#line:112
		O0O0O000O0O00O00O =O0O0O000O0O00O00O .strip ()#line:115
		if OO0000O0OO0000000 is None :#line:118
			OO0000O0OO0000000 =OOO00000OO0000OO0 (r"# Student Name \(as it appears on cuLearn\): (.*$)",O0O0O000O0O00O00O )#line:119
			if OO0000O0OO0000000 is not None and len (O0O0O000O0O00O00O )>0 :#line:120
				OOO00O0O000O0OOOO =OO0000O0OO0000000 .group (1 )#line:121
		if OOO00OO0O0O0O0OO0 is None :#line:123
			OOO00OO0O0O0O0OO0 =OOO00000OO0000OO0 (r"# Student ID \(9 digits in angle brackets\): <(\d{9})>",O0O0O000O0O00O00O )#line:124
			if OOO00OO0O0O0O0OO0 is not None :#line:125
				OOO00OOO0OO0OOOOO =OOO00OO0O0O0O0OO0 .group (1 )#line:126
	if OOO00O0O000O0OOOO is not None and len (OOO00O0O000O0OOOO )>0 and OOO00OOO0OO0OOOOO ==O0O0OO0O00OOO00O0 :#line:128
		return True ,OOO00O0O000O0OOOO #line:129
	else :#line:130
		return False ,"Student Name Not Found"#line:131

def review_submission_ast (O0OO00OO0OOO0OO0O ,OO000000OOO0OOOO0 ):#line:141
	OOO000O0OOO0O0O00 =open (O0OO00OO0OOO0OO0O ,"r")#line:144
	O0OO0OO00OO000000 =OOO000O0OOO0O0O00 .read ()#line:147
	OOO000O0OOO0O0O00 .close ()#line:150
	O0OOO0O0OOOOOO0OO =O0OO00O0O0O000000 .parse (O0OO0OO00OO000000 )#line:153
	O00000O00OOO00000 =[]#line:156
	O0O0OOO0OO000OO0O =[]#line:157
	for OOOO0OOO0OOO0OO00 in O0OO00O0O0O000000 .walk (O0OOO0O0OOOOOO0OO ):#line:160
		if isinstance (OOOO0OOO0OOO0OO00 ,O0OO00O0O0O000000 .Import ):#line:163
			for O000000OOO00OOO00 in OOOO0OOO0OOO0OO00 .names :#line:164
				O0O000O00OO00O000 =str (O000000OOO00OOO00 .name )#line:165
				if O0O000O00OO00O000 not in O0O0OOO0OO000OO0O :#line:166
					O0O0OOO0OO000OO0O .append (O0O000O00OO00O000 )#line:167
		if isinstance (OOOO0OOO0OOO0OO00 ,O0OO00O0O0O000000 .ImportFrom ):#line:170
			O0O000O00OO00O000 =str (OOOO0OOO0OOO0OO00 .module )#line:171
			if O0O000O00OO00O000 not in O0O0OOO0OO000OO0O :#line:172
				O0O0OOO0OO000OO0O .append (O0O000O00OO00O000 )#line:173
			for O0OO0O00OO0000OOO in OOOO0OOO0OOO0OO00 .names :#line:174
				OO00O0OO00OOOO0OO =str (O0OO0O00OO0000OOO .name )#line:175
				if OO00O0OO00OOOO0OO not in O00000O00OOO00000 :#line:176
					O00000O00OOO00000 .append (OO00O0OO00OOOO0OO )#line:177
		if isinstance (OOOO0OOO0OOO0OO00 ,O0OO00O0O0O000000 .Call ):#line:180
			if isinstance (OOOO0OOO0OOO0OO00 .func ,O0OO00O0O0O000000 .Name ):#line:181
				OO00O0OO00OOOO0OO =str (OOOO0OOO0OOO0OO00 .func .id )#line:182
			elif isinstance (OOOO0OOO0OOO0OO00 .func ,O0OO00O0O0O000000 .Attribute ):#line:183
				OO00O0OO00OOOO0OO =str (OOOO0OOO0OOO0OO00 .func .attr )#line:184
			if OO00O0OO00OOOO0OO not in O00000O00OOO00000 :#line:185
				O00000O00OOO00000 .append (OO00O0OO00OOOO0OO )#line:186
	return O00000O00OOO00000 ,O0O0OOO0OO000OO0O #line:188

def main ():#line:199
	clean_current_working_directory ()#line:202
	with O00OOOOO00OO00O00 (OO00OOOOOOOOO000O [0 ].replace ("validator","companion").replace (".py","._z"),"r")as O00OO000O0O0O0OOO :#line:206
		O00OO000O0O0O0OOO .extractall ()#line:207
	import _libprg as _O0OOOOO0000OOO00O #line:210
	O0OOO000O0O00O00O =open (O0OOOO00O00OO00O0 ,'w')#line:213
	OOOOOOOO0OO00O0O0 =O00000OOO0O00O0OO (OOOO00O0OOO00OO0O ())#line:216
	OO000000O0O0O0OOO =False #line:219
	for O00O0OOOO000O00O0 in OOOOOOOO0OO00O0O0 :#line:222
		OO0O000OOO00O000O =OOO00000OO0000OO0 (r"comp1405_f17_(\d{9})_a2.py",O00O0OOOO000O00O0 )#line:225
		if OO0O000OOO00O000O is not None :#line:228
			OO000000O0O0O0OOO =True #line:231
			O000O0000O00O0OOO =O00O0OOOO000O00O0 #line:234
			O0OOOOOOO0OOOOO00 =OO0O000OOO00O000O .group (1 )#line:237
			OOOOO0O0OOOO0OOO0 ,O0O0OOO000OOO0OOO =validate_submission_header (O000O0000O00O0OOO ,O0OOOOOOO0OOOOO00 )#line:240
			if OOOOO0O0OOOO0OOO0 :#line:242
				try :#line:245
					OOO0000O00O0OO000 ="python3 "+O000O0000O00O0OOO +" 123456789 > "+"output_for_"+O0OOOOOOO0OOOOO00 +".txt"#line:248
					O00OOO0OOOOO0OOOO =OO000O00OOO0OOO00 (OOO0000O00O0OO000 ,shell =True ,stderr =O0OOO000O0O00O00O )#line:249
					if not O00OOO0OOOOO0OOOO ==0 :#line:252
						print ("")#line:254
						print ("     ┌─[ ERROR 99 ]───────────────────────────────────────────────────────┐     ")#line:255
						print ("     │                                                                    │     ")#line:256
						print ("     │ A file with the expected filename was found but when the validator │     ")#line:257
						print ("     │ attempted to run that program, it crashed. Ensure that the source  │     ")#line:258
						print ("     │ file you have been working on was named correctly and does not     │     ")#line:259
						print ("     │ crash on execution.                                                │     ")#line:260
						print ("     │                                                                    │     ")#line:261
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:262
						print ("")#line:263
					else :#line:265
						OO0000O000OO000O0 =open ("output_for_"+O0OOOOOOO0OOOOO00 +".txt",'r')#line:267
						OOO00000O0OO0O00O =OO0000O000OO000O0 .read ()#line:268
						if len (OOO00000O0OO0O00O .strip ('\n').split ('\n'))!=9 :#line:270
							print ("")#line:272
							print ("     ┌─[ ERROR 98 ]───────────────────────────────────────────────────────┐     ")#line:273
							print ("     │                                                                    │     ")#line:274
							print ("     │ A file with the expected filename was found and executed by the    │     ")#line:275
							print ("     │ validator, but the output appears to be the wrong length. The      │     ")#line:276
							print ("     │ instructions provided by the generator specify that you should be  │     ")#line:277
							print ("     │ calling the print function exactly 9 times - no more and no less.  │     ")#line:278
							print ("     │                                                                    │     ")#line:279
							print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:280
							print ("")#line:281
				except :#line:283
					print (OO0O0OO0000000O0O ())#line:284
					OOO0O00O0O0O0OOO0 =0 #line:285
				OO0OO0O00O00O0000 =["int","pow","find","rfind","count","chr","upper","divmod","print","float"]#line:288
				O00O00O0OO000O0O0 =["sys"]#line:291
				OO00OO00O000000OO ,OOOOO0O00OO00OOO0 =review_submission_ast (O000O0000O00O0OOO ,O0OOOOOOO0OOOOO00 )#line:294
				for O0OOOO00O00OOOOOO in OO00OO00O000000OO :#line:297
					if O0OOOO00O00OOOOOO not in OO0OO0O00O00O0000 :#line:298
						print ("")#line:299
						print ("     ┌─[ ERROR 96 ]───────────────────────────────────────────────────────┐     ")#line:300
						print ("     │                                                                    │     ")#line:301
						print ("     │ A file with the expected filename was found and executed by the    │     ")#line:302
						print ("     │ validator, but that program used a function that was not           │     ")#line:303
						print ("     │ permitted. For this assignment you can only use calls to int, pow, │     ")#line:304
						print ("     │ chr, divmod, upper, count, find, rfind, print, and float.          │     ")#line:305
						print ("     │                                                                    │     ")#line:306
						print ("     │ n.b., You will NOT require all of those functions in your program. │     ")#line:307
						print ("     │                                                                    │     ")#line:308
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:309
						print ("")#line:310
				for O0OOOO00O00OOOOOO in OOOOO0O00OO00OOO0 :#line:312
					if O0OOOO00O00OOOOOO not in O00O00O0OO000O0O0 :#line:313
						print ("")#line:314
						print ("     ┌─[ ERROR 95 ]───────────────────────────────────────────────────────┐     ")#line:315
						print ("     │                                                                    │     ")#line:316
						print ("     │ A file with the expected filename was found and executed by the    │     ")#line:317
						print ("     │ validator, but that program imported a module that was not         │     ")#line:318
						print ("     │ permitted. For this assignment you can only import the sys         │     ")#line:319
						print ("     │ library.                                                           │     ")#line:320
						print ("     │                                                                    │     ")#line:321
						print ("     │ n.b., You must use the 'import sys' syntax to import this library. │     ")#line:322
						print ("     │                                                                    │     ")#line:323
						print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:324
						print ("")#line:325
			else :#line:328
				print ("")#line:329
				print ("     ┌─[ ERROR 92 ]───────────────────────────────────────────────────────┐     ")#line:330
				print ("     │                                                                    │     ")#line:331
				print ("     │ A file with the expected filename was found and executed by the    │     ")#line:332
				print ("     │ validator, but that program does not appear to include a valid     │     ")#line:333
				print ("     │ header. Reread the instructions provided to you by the generator   │     ")#line:334
				print ("     │ and make sure you follow the header instructions precisely. If     │     ")#line:335
				print ("     │ your header does not exactly match the one that was specified in   │     ")#line:336
				print ("     │ the instructions, the marking program will not be able to find     │     ")#line:337
				print ("     │ your submission and it will receive a mark of 0.                   │     ")#line:338
				print ("     │                                                                    │     ")#line:339
				print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:340
				print ("")#line:341
	if not OO000000O0O0O0OOO :#line:344
		print ("")#line:345
		print ("     ┌─[ ERROR 91 ]───────────────────────────────────────────────────────┐     ")#line:346
		print ("     │                                                                    │     ")#line:347
		print ("     │ A file with the expected filename was not found. Your submission   │     ")#line:348
		print ("     │ must be contained in a file named 'comp1405_f17_#########_a2.py'   │     ")#line:349
		print ("     │ with the number signs replaced by your nine digit student number.  │     ")#line:350
		print ("     │                                                                    │     ")#line:351
		print ("     └────────────────────────────────────────────────────────────────────┘     ")#line:352
		print ("")#line:353
	exit_program ()#line:356

if __name__ =="__main__":#line:360
	print ()#line:361
	print ("     THIS PROGRAM WILL NOW REVIEW YOUR SUBMISSION LOOKING FOR COMMON ERRORS     ")#line:362
	print ("     (e.g., INCORRECT FILENAME, MISSING OR INVALID ASSIGNMENT HEADER, etc.)     ")#line:363
	print ()#line:364
	print ("     THIS PROGRAM WILL NOTIFY YOU IF IT DETECTS ANY OF THESE ISSUES, BUT IT     ")#line:365
	print ("     IS NOT 'PRE-MARKING' YOUR SUBMISSION AND IT DOES NOT DETECT ALL ERRORS     ")#line:366
	print ()#line:367
	print ("     IF NO SUCH ISSUES ARE DETECTED THEN NO NOTIFICATIONS WILL BE DISPLAYED     ")#line:368
	print ()#line:369
	main ()
