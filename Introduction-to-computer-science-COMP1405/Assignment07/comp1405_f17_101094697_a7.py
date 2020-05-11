# ============================================================
#                                                             
# Student Name (as it appears on cuLearn): Khushal Singh     
# Student ID (9 digits in angle brackets): <101094697>        
# Course Code (for this current semester): COMP1405A          
#                                                             
# ============================================================
''' 
@params           file_name, the name of the file to be loaded
@return		  an uppercase string contsining the data read from the file
'''
def load_text(file_name) :
	file_hndl = open (file_name,"r")
	file_data = file_hndl.read()
	file_hndl.close()
	return file_data.upper()

''' 
@params           file_name, the name of the file to be saved
		  file_data, the data to be written to the file
@return		  none
'''
def save_text(file_name,file_data) :
	file_hndl = open(file_name,"w")
	file_hndl.write(file_data)
	file_hndl.close()
''' 
@params           name, the name or keyword to be used for producing cipher alphabet
@return		  name, the data to be used in encoding, decoding
'''
def keyword_cipher_alphabet(name):
	a = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	keyword = list(name)
	empty = []
	for j in range(len(keyword)):
		if not keyword[j] in empty:
			empty += keyword[j]
	for i in range(len(a)):
		if not a[i] in empty:
			empty.append(a[i])
	name = ""
	for k in range(len(empty)):
		name+=empty[k]
	return name
		
				
						
''' 
@params           none
@return		  string, the data to be used for encoding, decoding 
'''
def cryptogram_alphabet():
	k=0
	n = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	string = input('ENTER ALL THE ALPHABETS IN ANY ORDER BUT THEY SHOULD NOT BE SAME: ').upper()
	list_1 = list(string)
	if len(list_1) != 26 :
		print(' ERROR: WRONG NUMBER OF LETTERS')
		return n
	else :
		for i in range(26):
			for j in range(1+i,26,1):
				if list_1[i] == list_1[j]:
					k = 1	
	if k==1:
		print('ERROR: DUPLICATE VALUES')
		return n
					
	else:
		return string
	
''' 
@params           shift, interger value used for shfting the alphabets in a string
@return		  shifted_string, an upper case shifted string use for encoding, decoding
'''		
def caesar_cipher_alphabet(shift):
	a = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	shifted_string = ""
	for i in range(shift):
		a.append(a[i])
	for j in range(shift):
		a.pop(0)
	for k in range(len(a)):
		shifted_string += a[k]
	return shifted_string
''' 
@params           init_txt, string used for encoding
		  cur_alpha, the current string of alphabets used for encoding
@return		  encoded_text, returns the encoded string
'''		
def encode(init_txt,cur_alpha):
	m = 0
	n = 0
	encoded_text = ""
	while m < len(init_txt):
		if init_txt[m] == " ":
			encoded_text += " "
		elif init_txt[m] == "," :
			encoded_text += ","
		elif init_txt[m] == ".":
			encoded_text += "."
		else:
			while n < len(cur_alpha):
				if init_txt[m] == cur_alpha[n]:
					encoded_text += cur_alpha[ord(init_txt[m])-65]
				n+=1
		m += 1
		n = 0
	return encoded_text
''' 
@params           encoded_text, taking the encoded text to decode it 
		  curt_alpha, the current string to be used for decoding alphabet
@return		  decoded_text, returns the decoded text
'''		
def decode(encoded_text,curt_alpha):
	m = 0
	n = 0
	decoded_text = ""
	while m < len(encoded_text) :
		if encoded_text[m] == " ":
			decoded_text += " "
		elif encoded_text[m] == "," :
			decoded_text += ","
		elif encoded_text[m] == ".":
			decoded_text += "."
		else:
			while n < len(curt_alpha):
				if encoded_text[m] == curt_alpha[n]:
					decoded_text += chr(n+65)
				n+=1
		m += 1
		n = 0
	return decoded_text
''' 
@params           none
@return		  none
'''
def main() :
	initial_text = input('ENTER YOUR TEXT ').upper() # inputting the initial text from user
	current_text = "" #stores the current text being modified by user
	current_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" # current alphabets of string used in encoding, decoding
	print(initial_text,"\n",current_text) #printing the initial text and current text on screen
	print("A) PRESS A FOR ENCODER FUNCTION: ") # printing menu to user for choosing functions
	print("B) PRESS B FOR DECODER FUNCTION: ")
	print("C) PRESS C FOR CAESAR FUNCTION: ")
	print("D) PRESS D FOR CRYPTOGRAM FUNCTION: ")
	print("E) PRESS E FOR KEYWORD FUNCTION: ")
	print("F) PRESS F FOR LOAD THE FILE: ")
	print("G) PRESS G TO SAVE THE FILE: ")
	print("H) PRESS Q TO QUIT THE PROGRAM: ") # for quitting the program
	while True:
		choice = input("NOW, PLEASE ENTER YOUR CHOICE: ").upper()
		if choice == 'A' : # choice for ENCODE function
			current_text = encode(initial_text,current_alphabet)  # caliing the ENCODE function and storing the modified value
			
		elif choice.upper() == 'B' : # choice for DECODE function
			current_text = decode(current_text,current_alphabet) # caliing the DECODE function and storing the modified value
			
		elif choice == 'C' : # choice for CAESAR CIPHER ALPHABET function
			shifting_value = int(input('ENTER THE VALUE BY WHICH CHARACTERS SHOULD BE SHIFTED: ')) # asking the user for integer SHIFTING value, to be used for shifting string
			current_alphabet = caesar_cipher_alphabet(shifting_value)# caliing the CAESAR CIPHER ALPHABET function and storing the new value
		elif choice == 'D' : # choice for CRYPTOGRAM ALPHABET function
			current_alphabet = cryptogram_alphabet() # caliing the CRYPTOGRAM ALPHABET function and storing the new value
			
		elif choice == 'E' : # choice for KEYWORD CIPHER ALPHABET function
			key_word = input('ENTER THE ARGUMENT OR KEYWORD YOU WANT TO ENCRYPT FROM ALPHABETS: ').upper()
			current_alphabet = keyword_cipher_alphabet(key_word) # caliing the CIPHER ALPHABET function and storing the new value
		
		elif choice == 'F' : # choice for LOADING FILE function
			file_name = input('ENTER THE FILE NAME: ') #inputting the file name from user
			load_text(file_name) # caliing the LOAD function and giving the filename to read it
			print(initial_text,"\n",current_text) #printing the initial text and current text on screen
		elif choice == 'G' : # choice for SAVING function
			save_text(file_name,current_text) #caliing the SAVE function and giving the filename and current text to save them
			print(initial_text,"\n",current_text) #printing the initial text and current text on screen
		elif choice == 'Q' : # choice for QUITTING the function
			break # using break to STOP using program
		else:
			print("ENTER THE VALID INPUT") #if the user enters the invalid alphabet for choosing function, it prints error
	
main()


				
				
		
	



















