import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.collections.FXCollections;
import javafx.stage.Stage;
import javafx.scene.layout.Pane;
import java.lang.String;
import javafx.scene.control.*;
import javafx.scene.control.TextField;
import javafx.scene.control.ComboBox;
import javafx.collections.ObservableList;
import javafx.scene.control.Button;

public class AlarmApp extends Application {
    public void start(Stage primaryStage) {
        RadioButton ON,OFF;
        ToggleGroup operation;

        Pane apane = new Pane();
        apane.setStyle("-fx-background-color: white;" );

        Pane inner_pane1 = new Pane();
        inner_pane1.relocate(10,10);
        inner_pane1.setPrefSize(200,90);
        inner_pane1.setStyle("-fx-background-color: white; \n" +
                "-fx-border-color: gray; \n" +
                "-fx-padding: 45 100;");


        Pane inner_pane2 = new Pane();
        inner_pane2.relocate(215,10);
        inner_pane2.setPrefSize(190,25);
        inner_pane2.setStyle("-fx-background-color: white; \n" +
                "-fx-border-color: gray; \n" +
                "-fx-padding: 20 100;");


        Pane inner_pane3 = new Pane();
        inner_pane3.relocate(215,60);
        inner_pane3.setPrefSize(190,25);
        inner_pane3.setStyle("-fx-background-color: white; \n" +
                "-fx-border-color: gray; \n" +
                "-fx-padding: 20 100;");
        inner_pane3.relocate(220,60);

        Label label1 = new Label("Remaining Time");
        label1.relocate(20, 5);
        label1.setPrefSize(200, 10);
        label1.setStyle("-fx-background-color: white; -fx-translate-y: -8; - fx-translate-x: 10;");

        Label label1x = new Label(); // for remaining time watch
        label1x.relocate(22, 20);
        label1x.setPrefSize(190, 66);
        label1x.setStyle("-fx-font: 48 System;-fx-background-color: dark green; ");

        Label label2 = new Label("Current Time");
        label2.relocate(220, 5);
        label2.setPrefSize(200, 10);
        label2.setStyle("-fx-background-color: white; -fx-translate-y: -8; - fx-translate-x: 10;");

        Label label3 = new Label("Alarm Time");
        label3.relocate(220, 55);
        label3.setPrefSize(200, 10);
        label3.setStyle("-fx-background-color: white; -fx-translate-y: -8; - fx-translate-x: 10;");

        TextField current_time = new TextField();
        current_time.relocate(220, 25);
        current_time.setPrefSize(190, 25);
        current_time.setAlignment(Pos.CENTER_RIGHT);

        TextField Alarm_time = new TextField();
        Alarm_time.relocate(220, 75);
        Alarm_time.setPrefSize(190, 25);
        Alarm_time.setAlignment(Pos.CENTER_RIGHT);


        ObservableList<String> options = FXCollections.observableArrayList(
                "Weekday", "Saturday", "Sunday");
        ComboBox Select_alarm_box = new ComboBox(options);
        Select_alarm_box.setPromptText("Select Alarm");
        Select_alarm_box.relocate(10,110);
        Select_alarm_box.setPrefSize(410,30);
        //apane.getChildren().add(Select_alarm_box);

        Button new_alarm_button  = new Button("New Alarm");
        new_alarm_button.relocate(10, 150);
        new_alarm_button.setPrefSize(100,30);

        Button edit_button  = new Button("Edit");
        edit_button.relocate(120, 150);
        edit_button.setPrefSize(80,30);

        Button delete_button  = new Button("Delete");
        delete_button.relocate(210, 150);
        delete_button.setPrefSize(80,30);

        operation  = new ToggleGroup();
        ON = new RadioButton("ON");
        ON.setToggleGroup(operation);
        ON.relocate(310, 150);
        ON.setPrefSize(50,30);

        OFF = new RadioButton("OFF");
        OFF.setToggleGroup(operation);
        OFF.relocate(360, 150);
        OFF.setPrefSize(50,30);

        apane.getChildren().addAll(inner_pane1,inner_pane2,inner_pane3,label1,label2,label3,current_time,Alarm_time,Select_alarm_box,new_alarm_button,edit_button,delete_button,ON,OFF);

        primaryStage.setTitle("AlarmApp");
        Scene scene = new Scene(apane, 430, 190);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    public static void main(String[] args){
        launch(args);
    }
}
