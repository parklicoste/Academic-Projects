import javafx.geometry.Point2D;
public class PartImage {
    private boolean[][] pixels;
    private boolean[][] visited;
    private int rows;
    private int cols;
    int perimeter = 0;
    public PartImage(int r, int c) {
        rows = r;
        cols = c;
        visited = new boolean[r][c];
        pixels = new boolean[r][c];
    }
    public PartImage(int rw, int cl, byte[][] data) {
        this(rw,cl);
        for (int r=0; r<10; r++) {
            for (int c=0; c<10; c++) {
                if (data[r][c] == 1)
                    pixels[r][c] = true;
                else
                    pixels[r][c]= false;
            }
        }
    }
    public int getRows() { return rows; }
    public int getCols() { return cols; }
    public boolean getPixel(int r, int c) { return pixels[r][c]; }


    // You will re-write the 5 methods below
    public void print() {
        for(int i=0; i<getRows();i++){
            System.out.println();
            for(int j=0;j<getCols();j++){
                if(pixels[i][j] == false){ System.out.print("-"); }
                else{System.out.print("*");}
            }
        }


    }
    public Point2D findStart() {
        for(int i=0; i<getRows();i++){
            for(int j=0;j<getCols();j++){
                if(pixels[i][j] ){
                    return new Point2D(i,j);
                }
            }
        }
        return null;
    }


    public int partSize() {
        int countBlack = 0;
        for(int i=0; i<getRows();i++){
            for(int j=0;j<getCols();j++){
                if(pixels[i][j] != false){ countBlack++; }
            }
        }
        return countBlack; }


    private void expandFrom(int r, int c) {


        if (!(r < getRows()) || r < 0 || !(c < getCols()) || c < 0) {
            return;
        }
        if (!getPixel(r, c)) {
            return;
        } else {
            pixels[r][c] = false;
            expandFrom(r - 1, c);
            expandFrom(r + 1, c);
            expandFrom(r, c - 1);
            expandFrom(r, c + 1);
        }
    }


    private int perimeterOf(int r, int c) {

        if (!(r < getRows()) || r < 0 || !(c < getCols()) || c < 0) { //Checking for the corner parameter
            perimeter++;
            return perimeter;
        }
        if (!getPixel(r, c)) { //checking for the other parameter
            if(!visited[r][c]){
            perimeter++;
            }
            return perimeter;
        }
        else {
            pixels[r][c] = false;
            if(!visited[r][c]) {
                visited[r][c] = true;
                perimeterOf(r - 1, c);
                perimeterOf(r + 1, c);
                perimeterOf(r, c - 1);
                perimeterOf(r, c + 1);

            }
        }
        return perimeter; }
    public boolean isBroken(){
        Point2D p = findStart();
        expandFrom((int)p.getX(), (int)p.getY());
        return (partSize() != 0);
    }
    public int perimeter() {
        Point2D p = findStart();
        return perimeterOf((int)p.getX(), (int)p.getY());
    }

    public static PartImage exampleA() {
        byte[][] pix = {{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,0,0,0,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,0,0,0}};
        return new PartImage(10,10, pix);
    }
    public static PartImage exampleB() {
        byte[][] pix = {{1,0,1,0,1,0,1,0,0,0},
                {1,0,1,0,1,0,1,1,1,1},
                {1,0,1,0,1,0,1,0,0,0},
                {1,0,1,0,1,0,1,1,1,1},
                {1,0,1,0,1,0,1,0,0,0},
                {1,0,1,0,1,0,1,1,1,1},
                {1,1,1,1,1,1,1,0,0,0},
                {0,1,0,1,0,0,1,1,1,1},
                {0,1,0,1,0,0,1,0,0,0},
                {0,1,0,1,0,0,1,0,0,0}};
        return new PartImage(10,10, pix);
    }
    public static PartImage exampleC() {
        byte[][] pix = {{1,1,1,0,0,0,1,0,0,0},
                {1,1,1,1,0,0,1,1,1,0},
                {1,1,1,1,1,1,1,1,1,1},
                {0,1,1,1,0,0,1,0,0,0},
                {0,0,1,0,0,0,0,0,0,0},
                {1,0,0,0,1,1,0,1,1,1},
                {1,1,0,1,1,1,1,1,1,1},
                {1,1,1,1,1,1,1,1,1,1},
                {0,0,1,1,0,1,1,1,1,1},
                {0,0,1,0,0,0,1,1,0,0}};
        return new PartImage(10,10, pix);
    }
    public static PartImage exampleD() {
        byte[][] pix = {{1, 0, 1, 0, 1, 0, 1, 1, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                {1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                {1, 1, 0, 0, 0, 1, 1, 0, 0, 1},
                {0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
                {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 1, 0, 0, 0}};
        return new PartImage(10, 10, pix);
    }
}