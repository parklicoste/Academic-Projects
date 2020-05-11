# ============================================================
#                                                             
# Student Name (as it appears on cuLearn): Khushal Singh    
# Student ID (9 digits in angle brackets): <101094697>        
# Course Code (for this current semester): COMP1405A          
#                                                             
# ============================================================
import pygame
pygame.init()   #initiating the pygame
inst = input('do you want to read instructions ').upper()
if inst == 'YES' :   #printing the instructions for the user
	print('First you need to type the name of background image and ghost image and if you do not give the correct names the program will terminate')
	print('Then you have to give the co-ordinates to center the ghost image on background image, but the co-ordinates should not be less than 0 and and greater than the width and height of background image')
background_img = input('Enter the name of background image ')  #taking the name of background image from user
if   background_img == 'abandoned_circus.bmp' : # checking if the name is correct or not
	print() 
elif background_img == 'abandoned_homestead.bmp':
	print() 
elif background_img == 'abandoned_plant.bmp':
	print() 
else:   # if the name isn't correct then printing instructions and terminating the program
	print('Invalid name of Background Image ')
	print('First you need to type the name of background image and ghost image and if you do not give the correct names the program will terminate')
	print('Then you have to give the co-ordinates to center the ghost image on background image, but the co-ordinates should not be less than 0 and and greater than the width and height of background image')
	exit()  #command for termination
ghost_img = input('Enter the name of ghost image ')  #taking the name of ghost image from the user
if ghost_img == 'ghost_with_broom.bmp':  # checking if the name is correct or not
	print() 
elif ghost_img == 'ghost_with_crutches.bmp' :
	print() 
elif ghost_img == 'ghost_with_frame.bmp' :
	print()
else:   # if the name isn't correct then printing instructions and terminating the program
	print( 'invalid name of Ghost Image ')
	print('first you need to type the name of background image and ghost image')
	print('second you need to give the coordinates to center the ghost ')
	print('then you have to give the co-ordinates of ghost to center it, but the co-ordinates should not be less than 0 and and greater than the width and height of background image')
	exit()  #command for termination
background_dimensions = pygame.image.load(background_img) # loading the background image into variable 
(a,b) = background_dimensions.get_rect().size  #taking the dimensions (width and height) of background image into a and b variable
window = pygame.display.set_mode((a,b))  # creating a window using dimensions of background image
window.blit(background_dimensions,(0,0))  #  copying the background image into the main window
pygame.display.update()  #  updating the display
ghost_dimensions = pygame.image.load(ghost_img)  # loading the background image into variable
(ghost_width,ghost_height) = ghost_dimensions.get_rect().size  #taking the dimensions (width and height) of ghost image into ghost_width and ghost_height variable
mid_ghost_width=int(ghost_width/2)  #dividing the ghost width by 2 to find centre x of ghost image
mid_ghost_height=int(ghost_height/2)  #dividing the ghost width by 2 to find centre y of ghost image
x = int(input('Enter the center x co-ordinate where you want to put ghost in background image ')) # taking the centre co-ordinate for x to print the ghost image
flag = True
while flag:  # checking if the user provided wrong value for co-ordinate
	if (x<0 or x>a) :
		print('invalid value of x please enter again')
		x = int(input('Enter the center x co-ordinate where you want to put ghost in background image ')) #  asking for x co-ordinate again  
	else:
		flag = False
flag = True
y = int(input('Enter the center y co-ordinate where you want to put ghost in background image ')) # taking the centre co-ordinate for y to print the ghost image
while flag:  # checking if the user provided wrong value for co-ordinate
	if y<0 or y>b :
		print('invalid value of y please enter again ')
		y = int(input('Enter the center y co-ordinate where you want to put ghost in background image '))  #  asking for x co-ordinate again  
	else:
		flag = False
for i in range(0,ghost_width,1): #  initiating first loop for x values in ghost image
	for j in range(0,ghost_height,1):  #  initiating second loop for y values in ghost image
		if    (x-mid_ghost_width+i)>a : # checking if the x co-ordinate goes out of range (exceeds a value)
			print()
		elif  (y-mid_ghost_height+j)>b:  # checking if the y co-ordinate goes out of range (exceeds b value)
			print()
		elif  (x-mid_ghost_width+i)<0:  # checking if the x co-ordinate goes out of range (less than 0)
			print()
		elif  (y-mid_ghost_height+j)<0:  # checking if the y co-ordinate goes out of range (less than 0)
			print()
		else :
			(p,q,r,_) = ghost_dimensions.get_at((i,j))  # storing the values of color of a pixel in variables from ghost image
			(d,e,f,_) = background_dimensions.get_at((x-mid_ghost_width+i,y-mid_ghost_height+j))  #  storing the values of color of a pixel in variables from background image
			if ghost_dimensions.get_at((i,j)) != (0,255,0,_): # checking if the pixel color isn't green 

				gavg = int((p+d)/2)  # making the average of red color values obtained from both images at the same co-ordinates
				havg = int((q+e)/2)  # making the average of green color values obtained from both images at the same co-ordinates
				iavg = int((r+f)/2)  # making the average of blue color values obtained from both images at the same co-ordinates
				window.set_at((i+x-mid_ghost_width,j+y-mid_ghost_height),(gavg,havg,iavg)) # setting the average colors into the window at the same co-ordinates
pygame.display.update()  # updating the display

flag = True		
while flag:  # this loop to force the pygame window to stay open until the user tries to close the window
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			flag = False
	
















