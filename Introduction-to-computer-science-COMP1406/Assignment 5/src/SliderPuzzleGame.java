import com.sun.corba.se.impl.orbutil.closure.Constant;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Point2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.util.Duration;
import java.util.Random;


public class SliderPuzzleGame extends Application {
    Integer sec = 0, min = 0;
    Button[][] buttons= new Button[4][4];
    Image[][] image = new Image[4][4];
    Image blank_img = new  Image(getClass().getResourceAsStream("BLANK.png"));
    Image saved_img;
    Point2D[][] co_ordinates = new Point2D[4][4];

    public void shuffle(){
        for(int i=0; i<5000 ;i++){//shuffles 5000 times
            Image temp ;
            Point2D local;
            Random x = new Random();
            int p = x.nextInt(4);
            Random y = new Random();
            int q = y.nextInt(4);
            Random a = new Random();
            int r = a.nextInt(4);
            Random b = new Random();
            int s = b.nextInt(4);
            temp = image[p][q];// swapping the images
            image[p][q] = image[r][s];
            image[r][s] = temp;
            buttons[p][q].setGraphic(new ImageView(image[p][q]));
            buttons[r][s].setGraphic(new ImageView(image[r][s]));
        }
    }

    //function for tile button pressed for swap
    public void tile_button_pressed(ActionEvent event){
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (buttons[row][col]== event.getSource()){
                    swap(row,col);// calls swap method
                }
            }
        }
    }
   public void swap(int x,int y) {
        if (image[x][y+1] == blank_img  &&(y+1<4 && y+1 >=0 && x>=0 && x<4) ){
            image[x][y+1] = image[x][y];
            image[x][y] = blank_img;
            buttons[x][y].setGraphic(new ImageView(image[x][y]));
            buttons[x][y+1].setGraphic(new ImageView(image[x][y+1]));
        }
        else if(image[x+1][y] == blank_img &&(x+1<4 && x+1>=0 && y>=0 && y<4)){
            image[x+1][y] = image[x][y];
            image[x][y] = blank_img;

            buttons[x][y].setGraphic(new ImageView(image[x][y]));
            buttons[x+1][y].setGraphic(new ImageView(image[x+1][y]));

        }
        else if(image[x][y-1]==blank_img&&(y-1>=0 && y-1<4 && x>=0 && x<4)){
            image[x][y-1]=image[x][y];
            image[x][y] = blank_img;
            buttons[x][y].setGraphic(new ImageView(image[x][y]));
            buttons[x][y-1].setGraphic(new ImageView(image[x][y-1]));

        }
        else if(image[x-1][y]==blank_img&&(x-1>=0 && x-1<4 && y>=0 && y<4)){
            image[x-1][y] = image[x][y];
            image[x][y] = blank_img;
            buttons[x][y].setGraphic(new ImageView(image[x][y]));
            buttons[x][y+1].setGraphic(new ImageView(image[x-1][y]));

        }
        else {
            buttons[x][y].setGraphic(new ImageView(image[x][y]));
            buttons[x][y+1].setGraphic(new ImageView(image[x-1][y]));

        }// don't Swap*/
   }


    public void start(Stage primaryStage) {
        Pane aPane = new Pane();

        //Text Field for Timer
        TextField timer = new TextField("0:00");
        timer.relocate(205*4, 370);
        timer.setPrefSize(132, 25);

        //Timer
        Timeline updateTimer = new Timeline(new KeyFrame(Duration.millis(1000),
                new EventHandler<ActionEvent>()
                {
                    public void handle(ActionEvent event) {
                        sec++;// FILL IN YOUR CODE HERE THAT WILL GET CALLED ONCE PER SEC. } }));
                        if(sec>59){
                            min++;
                            sec = 0;
                        }
                        timer.setText(String.format("%d:%02d",min,sec));
                    }
                }));
        updateTimer.setCycleCount(Timeline.INDEFINITE);


        for(int i=0; i<4 ;i++){
            for(int j=0; j<4; j++){
                buttons[i][j] = new Button();
                buttons[i][j].relocate(10+187*i,10+187*j);
                buttons[i][j].setPadding(new Insets(1,1,1,1));

                image[i][j] = blank_img;
                buttons[i][j].setGraphic(new ImageView(image[i][j]));
                aPane.getChildren().addAll(buttons[i][j]);
                buttons[i][j].setOnAction(new EventHandler<ActionEvent>() {  // event handling handling for each and every button
                    @Override
                    public void handle(ActionEvent actionevent) {
                        tile_button_pressed(actionevent);
                    }
                });
            }
        }




        //Thumbnail Image
        Label thumbnail = new Label();
        Image thumbnailImage = new Image(getClass().getResourceAsStream("Lego_Thumbnail.png"));
        thumbnail.setGraphic(new ImageView(thumbnailImage));
        thumbnail.relocate(191*4,10);

        //list view
        ListView<String> puzzleList = new ListView<String>();
        String[] Puzzles = {"Pets","Scenery","Lego","Numbers"};
        puzzleList.setItems(FXCollections.observableArrayList(Puzzles));
        puzzleList.relocate(191*4, 200);
        puzzleList.setPrefSize(187, 130);

        //Stop Button
        Button stopButton = new Button("Stop");
        stopButton.relocate(191 * 4, 340);
        stopButton.setPrefSize(187, 25);
        stopButton.setStyle("-fx-base: rgb(139,0,0);");


       // Start Button
        Button startButton = new Button("Start");
        startButton.relocate(191*4 ,340);
        startButton.setPrefSize(187, 25);
        startButton.setStyle("-fx-base: rgb(0,100,0);");

        //Event Handler for Stop button
        stopButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                updateTimer.stop();
                stopButton.setDisable(true);
                stopButton.setVisible(false);
                startButton.setDisable(false);
                startButton.setVisible(true);
                thumbnail.setDisable(false);
                puzzleList.setDisable(false);

                for(int i=0; i<4 ;i++){
                    for(int j=0; j<4; j++){
                        buttons[i][j] = new Button();
                        buttons[i][j].relocate(10+187*i,10+187*j);
                        buttons[i][j].setPadding(new Insets(1,1,1,1));

                        image[i][j] = blank_img;
                        buttons[i][j].setGraphic(new ImageView(image[i][j]));
                        aPane.getChildren().addAll(buttons[i][j]);
                    }
                }

            }});


        // Event handler for start button
        startButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                updateTimer.play();
                startButton.setDisable(true);
                startButton.setVisible(false);
                stopButton.setVisible(true);
                stopButton.setDisable(false);
                thumbnail.setDisable(true);
                puzzleList.setDisable(true);
                sec = 0;

                for(int i=0; i<4 ;i++){
                    for(int j=0; j<4; j++){
                        buttons[i][j] = new Button();
                        buttons[i][j].relocate(10+187*i,10+187*j);
                        buttons[i][j].setPadding(new Insets(1,1,1,1));
                        image[i][j] = new  Image(getClass().getResourceAsStream(puzzleList.getSelectionModel().getSelectedItem()+"_"+j+i+".png"));
                        buttons[i][j].setGraphic(new ImageView(image[i][j]));
                        buttons[i][j].setOnAction(new EventHandler<ActionEvent>() {  // event handling handling for each and every button
                            @Override
                            public void handle(ActionEvent actionevent) {
                                tile_button_pressed(actionevent);
                            }
                        });

                        aPane.getChildren().addAll(buttons[i][j]);
                    }
                }
                shuffle();// for shuffling Images

                Random m = new Random();
                int p = m.nextInt(4);
                Random n = new Random();
                int q = n.nextInt(4);
                saved_img = image[p][q];
                image[p][q] = blank_img;
                buttons[p][q].setGraphic(new ImageView(image[p][q]));
            }});

        // Label of Timer
        Label time = new Label("Time");
        time.relocate(191*4, 370);
        time.setPrefSize(80, 30);



        // EventHandler for  list mouse
        puzzleList.setOnMouseClicked(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {
                Image thumbnailImage = new Image(getClass().getResourceAsStream(puzzleList.getSelectionModel().getSelectedItem()+"_Thumbnail.png"));
                thumbnail.setGraphic(new ImageView(thumbnailImage));

            }});


    aPane.getChildren().addAll(stopButton,startButton,thumbnail,time,timer,puzzleList);

    Scene display = new Scene(aPane, 190*5 , 189*4);
        primaryStage.setTitle("Slider Puzzle Game"); // Set window title
        primaryStage.setScene(display);
        primaryStage.setResizable(false);
        primaryStage.show(); // Show window
    }
    public static void main(String[] args) {
        launch(args);
    }

}
