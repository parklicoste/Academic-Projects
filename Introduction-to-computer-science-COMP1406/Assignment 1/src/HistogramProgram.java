public class HistogramProgram {
    public static void main(String[] args)
    {
        byte [] Val = new byte[100]; // defining an byte type array with 100 capacity
        for(int i=0; i<100; i++) {
            Val[i] = (byte)(Math.random() * 10); // inputting 100 random values ranging from 0 to 9
        }
        for(int j=0; j<10;j++) { // loop for building the histogram
            System.out.print(j+" |");
            for(int k=0; k<100;k++) {
                if (Val[k] == j) {
                    System.out.print("*"); // printing the histogram
                }
            }
            System.out.println();
        }
    }
}
