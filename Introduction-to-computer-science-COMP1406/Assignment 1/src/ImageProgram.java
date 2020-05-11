
public class ImageProgram {
    public static void main(String[] args) {
        boolean [][] Arr = new boolean[10][10]; // creating a two dimensional array which contains boolean values
        int num, horizontal = 0, vertical = 0, count_horiziontal, count_vertical;
        for (int i = 0; i < 10; i++) { // running a loop to inputting random boolean values in 2_D array
            for (int j = 0; j < 10; j++) {
                num = (int) (Math.random() * 2);// generating 2 values for true and false 1-true and 0 false
                if (num != 0) {
                    Arr[i][j] = true;
                }
                else {
                    Arr[i][j] = false;
                }
            }
        }
        for (int i = 0; i < 10; i++) { // loop for printing image O for true and . for false
            for (int j = 0; j < 10; j++){
                if(Arr[i][j]==true){
                    System.out.print("O ");
                }
                else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
        for (int i = 0; i < 10; i++) {  // program for counting longest horizontal and vertical sequence
            count_vertical = 0;
            count_horiziontal = 0;
            for (int j = 0; j < 10; j++) { // statements for counting longest horizontal sequence starts here
                if (Arr[i][j]) {
                    count_horiziontal++;
                }
                else {
                    if (horizontal < count_horiziontal) { horizontal = count_horiziontal; }
                    count_horiziontal = 0;
                    }
                if (Arr[j][i] == true) { // statements for counting longest vertical sequence starts here
                    count_vertical++; }
                else {
                    if (vertical < count_vertical) {
                        vertical = count_vertical;
                    }
                    count_vertical = 0;
                }
            }

            if (horizontal < count_horiziontal) { horizontal = count_horiziontal; } // overwriting if there it is larger horizontal sequence
            if (vertical < count_vertical) { vertical = count_vertical; } // overwriting if there it is larger vertical sequence
        }
        System.out.println("The longest horizontal sequence is " + horizontal);
        System.out.println("The longest vertical sequence is " + vertical);
    }
}
