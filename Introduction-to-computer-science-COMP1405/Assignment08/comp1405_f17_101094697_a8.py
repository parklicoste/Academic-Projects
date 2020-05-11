# ============================================================
#                                                             
# Student Name (as it appears on cuLearn): Khushal Singh     
# Student ID (9 digits in angle brackets): <101094697>        
# Course Code (for this current semester): COMP1405A          
#                                                             
# ============================================================
''' 
@params           two_D_list, takes and empty list
@return		  two_D_list, returns a two dimensional list
'''
def current_state(two_D_list):
	for i in range(8):
		r_1 = input('ENTER THE '+str(i+1)+' ROW OF THE CHESS\t')
		if len(r_1) != 8:
			r_1 = check_length(r_1,str(i+1)) #calling function for checking length of string and storing into r_1
		else:		
			r_1 = check_letters(r_1,str(i+1))#calling function for checking pieces in a row and storing into r_1
		two_D_list.append(r_1)
	return two_D_list
''' 
@params           string, takes a string argument for checking the length of a row
		  row_number, takes a character number or row number to tell user the row number
@return		  boom, returns  True or False if letter is present or not
'''
def check_length(string,row_number):
	while len(string) != 8:
		print("INVALID NUMBER OF BLOCKS PLEASE TYPE AGAIN")
		string = input('ENTER THE '+row_number+' ROW OF THE CHESS\t')
	boom = check_letters(string,row_number) # calling the function for checking coorect pieces and storing into boom
	return boom

''' 
@params           string_1, takes a string argument for checking each letter in it
		  row_number, takes a character number or row number to tell user the row number
@return		  empty_list, returns a list of correct letters
		  returning_list, returns a list of correct letters after inputting correct letters from the user
'''
def check_letters(string_1,row_number_1):
	empty_list = []
	for i in range(8):
		if string_1[i] == 'K':
			empty_list.append(string_1[i])
		elif string_1[i] == 'Q':
			empty_list.append(string_1[i])
		elif string_1[i] == 'P':
			empty_list.append(string_1[i])
		elif string_1[i] == 'R':
			empty_list.append(string_1[i])
		elif string_1[i] == 'B':
			empty_list.append(string_1[i])
		elif string_1[i] == 'N':
			empty_list.append(string_1[i])
		elif string_1[i] == 'k':
			empty_list.append(string_1[i])
		elif string_1[i] == 'q':
			empty_list.append(string_1[i])
		elif string_1[i] == 'n':
			empty_list.append(string_1[i])
		elif string_1[i] == 'r':
			empty_list.append(string_1[i])
		elif string_1[i] == 'p':
			empty_list.append(string_1[i])
		elif string_1[i] == 'b':
			empty_list.append(string_1[i])
		elif string_1[i] == '-':
			empty_list.append(string_1[i])
	if len(empty_list) == 8:
		return empty_list
		
	else: 
		print("INVALID LETTER PLEASE TYPE AGAIN")
		string_1 = input('ENTER THE '+row_number_1+' ROW OF THE CHESS\t')
		returning_list = list(check_length(string_1,row_number_1))  #calling a function for checking length 
		return returning_list
''' 
@params           two_D_list, takes the two dimensional list and prints it
@return		  none
'''
def printing(two_dimensional_list):
	black = 0
	white = 0
	for i in range(8):
		print("")
		for j in range(8):
			print(two_dimensional_list[i][j], end ="")
			if two_dimensional_list[i][j] == 'q':
				white += 10
			elif two_dimensional_list[i][j] == 'b':
				white += 3
			elif two_dimensional_list[i][j] == 'n':
				white += 3.5
			elif two_dimensional_list[i][j] == 'r':
				white += 5
			elif two_dimensional_list[i][j] == 'p':
				white += 1
			elif two_dimensional_list[i][j] == 'Q':
				black += 10
			elif two_dimensional_list[i][j] == 'B':
				black += 3
			elif two_dimensional_list[i][j] == 'N':
				black += 3.5
			elif two_dimensional_list[i][j] == 'R':
				black += 5
			elif two_dimensional_list[i][j] == 'P':
				black += 1
	winner(white,black) #calling winner function which prints score and winner
''' 
@params           safed, takes the white's score and prints if white is winner
		  kala, take the black's score and prints if black is winner 
@return		  none
'''
def winner(safed,kala):
	print("\nTHE VALUE OF BLACK IS: ",kala)
	print("THE VALUE OF WHITE IS: ",safed)
	if safed > kala:
		print("CURRENTLY WHITE IS WINNING")
	elif safed == kala:
		print("DRAW GAME: NO ONE IS WINNING")
	else:
		print("CURRENTLY BLACK IS WINNING")
''' 
@params           two_dimensional_list, take the two dimensional list for editing
@return		  two_dimensional_list, return the updated two dimensional list or chess board
'''
def pieces(two_dimensional_list):
	x1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP X "))# x co-ordinate to pick up a piece
	while x1 < 1 or x1 > 8 :
		print("INVALID VALUE OF X, PLEASE TYPE AGAIN")
		x1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP X "))
	y1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP Y "))# y co-ordinate to pick up a piece
	while y1 < 1 or y1 > 8 :
		print("INVALID VALUE OF Y, PLEASE TYPE AGAIN")
		y1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP Y "))
	while two_dimensional_list[x1-1][y1-1] == '-':
		print("THERE IS NO PIECE ON THIS POSITION, PLEASE GIVE COODINATES AGAIN")
		x1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP X "))
		while x1 < 1 or x1 > 8 :
			print("INVALID VALUE OF X, PLEASE TYPE AGAIN")
			x1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP X "))
		y1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP Y "))
		while y1 < 1 or y1 > 8 :
			print("INVALID VALUE OF Y, PLEASE TYPE AGAIN")
			y1 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO PICK UP Y "))
		
	x2 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO MAKE A MOVE X "))# x co-ordinate to drop a piece on this place
	while x2 < 1 or x2 > 8 :
		print("INVALID VALUE OF X, PLEASE TYPE AGAIN")
		x2 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO MAKE A MOVE X "))
	y2 = int(input("ENTER THE COORDINATES AT WHICH YOU WANT TO MAKE A MOVE Y "))# y co-ordinate to drop a piece on this place
	while y2 < 1 or y2 > 8 :
		print("INVALID VALUE OF Y, PLEASE TYPE AGAIN")
		y2 = int(input("ENTER THE COORDINATE AT WHICH YOU WANT TO MAKE A MOVE Y "))
	if x1 == x2 and y1 == y2:
		return two_dimensional_list
	else:
		two_dimensional_list[x2-1][y2-1] = two_dimensional_list[x1-1][y1-1]
		two_dimensional_list[x1-1][y1-1] = '-'
		return two_dimensional_list
''' 
@params          none
@return		 none
'''
def main():
	board = [] # creating an empty chess board or list
	print("\t\tPLEASE READ THE INSTRUCTIONS CAREFULLY")
	print("FOR BLACK PIECES NAME, YOU WILL ENTER LOWERCASE LETTERS AND UPPERCASE LETTERS FOR WHITE PIECES")
	print("(K)ING - K OR k HAS VALUE 0\n(Q)UEEN - Q OR q  HAS VALUE 10\n(B)ISHOP - B OR b HAS VALUE 3\nK(N)IGHT - N OR n HAS VALUE 3.5\n(R)OOK - R OR r HAS VALUE 5\n(P)AWN - P OR p HAS VALUE 1\n - FOR EMPTY SPACES") 
	print("PLEASE ENTER THE CURRENT STATE OF THE BOARD ")
	current_state(board)   #calling the function for building board and giving empty board or list as argument
	printing(board)        # calling the function to print board and the score
	while True:
		print("\tMAKE SURE WHEN YOU MOVE THE PIECES GIVE THE CORRECT POSITION OF PIECE \t i.e IF IT'S 4TH ROW THEN 4 AND 5TH COLUMN THEN 5")
		print("\tPRESS A  TO TYPE ANOTHER CHESSBOARD FROM THE SCRATCH ")
		print("\tPRESS B  TO MOVE THE PIECES ")
		print("\tPRESS C TO QUIT THE PROGRAM")
		choice = input("ENTER YOUR CHOICE ").upper()
		if choice == 'A' :  #scratch the current state of chess board
			board = [] # making existing chess board or list empty
			current_state(board)    #calling the function for building board again 
			printing(board)	    # calling the function to print board and the score
		elif choice == 'B': # function to move pieces
			pieces(board)	    #calling the function to move pieces
			printing(board)     # calling the function to print board and the score
		elif choice == 'C': # quitting the function
			printing(board) # calling the function to print board and the score and quitting
			break		
		else:
			print("INVALID CHOICE PLEASE ENTER C IF YOU REALLY WANT TO QUIT") # statement for wrong input
main()









			
