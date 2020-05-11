# ============================================================
#
# Student Name (as it appears on cuLearn): Khushal Kumar
# Student ID (9 digits in angle brackets): <101094697>
# Course Code (for this current semester): COMP1405A
#
# ============================================================

from comp1405_f17_assistant_a3 import *

def decision_making_function(e):  # 'e' IS THE SHAPE ARGUMENT YOU MUST PASS TO YOUR PERMITTED FUNCTIONS

	condition_for_sending_down = is_shaped_like_a_pentagon(e) and color_is_blue(e) or color_is_orange(e) and is_shaped_like_a_square(e) 
	condition_for_sending_left = is_shaped_like_a_circle(e) and color_is_black(e) and divides_evenly_by(e, 5) or color_is_red(e) and divides_evenly_by(e, 5) or is_shaped_like_a_cross(e)
	condition_for_sending_right = is_shaped_like_a_pentagon(e) and color_is_red(e) or is_shaped_like_a_square(e) and color_is_black(e)
	
	return (condition_for_sending_down, condition_for_sending_left, condition_for_sending_right)


	
run_the_program(decision_making_function)
