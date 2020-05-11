import java.util.Scanner;
import java.lang.Math;
public class QuizProgram
{
    public static void main(String[] args)
    {
        int answer, score = 0;
        for (int i=0; i<=10; i++) {
            int num = (int) (Math.random() * 10);
            int num1 = (int) (Math.random() *100);
            int num2 = (int) (Math.random() * (num1 + 1));
            if (num <= 5)   {  // probability of using addition operator to generate a question
                System.out.println("What is the answer to "+ num1 + "+" + num2 + " = ");
                answer = new Scanner(System.in).nextInt(); // asking for answer from the user
                if(answer == (num1 + num2)) { // condition for inputting correct answer
                    System.out.println("You are correct!");
                    score++; // counting the score if user gives the correct answer
                }
                else {
                    System.out.println("Sorry, the correct answer is " + (num1 + num2)); // condition for inputting wrong answer
                }
            }
            else { // probability of using subtraction operator to generate a question
                System.out.println("What is the answer to " + num1 + "-" + num2 + " = ");
                answer = new Scanner(System.in).nextInt(); // asking for answer from the user
                if(answer == (num1 - num2)) { // condition for inputting correct answer
                    System.out.println("You are correct!");
                    score++; // counting the score if user gives the correct answer
                }
                else {
                    System.out.println("Sorry, the correct answer is " + (num1 - num2)); // condition for inputting wrong answer
                }
            }
        }
        System.out.println("You scored " + (score*10) + " % on the quiz"); // calculating and displaying the score of a student
    }
}