# ============================================================
#                                                             
# Student Name (as it appears on cuLearn): Khushal Kumar     
# Student ID (9 digits in angle brackets): <101094697>      
# Course Code (for this current semester): COMP1405A          
#                                                             
# ============================================================

# calling pygame from library
import pygame 
# initialising the pygame                         
pygame.init()  
# assigning the window and giving its dimensions                        
a1=pygame.display.set_mode((48,56))    
# Giving the window white color
a1.fill((255,255,255))     
# Drawing the first polygon             
pygame.draw.polygon(a1,(68,80,140),((7,20),(7,27),(15,27),(21,33),(21,26),(15,20))) 
# Drawing the second polygon        
pygame.draw.polygon(a1,(166,65,77),((7,28),(7,35),(13,41),(13,35),(20,34),(14,28))) 
# Drawing the third polygon     
pygame.draw.polygon(a1,(94,102,96),((39,4),(39,27),(45,33),(45,4))) 
# Drawing the fourth polygon      
pygame.draw.polygon(a1,(42,52,67),((39,29),(39,43),(45,49),(45,35)))   
# Updating the display    
pygame.display.update() 
# Saving the image as student ID number              
pygame.image.save(a1,"101094697.png")  
               
