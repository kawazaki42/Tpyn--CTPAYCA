package io.github.kawazaki42.task01arith;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import io.github.kawazaki42.task01arith.Model;

public class Controller {
//    @FXML
//    private Label welcomeText;

    @FXML
    private Label labelAnswerA;

    @FXML
    private Label labelAnswerB;

    private TextField textInputX;
    private TextField textInputY;
    private TextField textInputZ;

    @FXML
    protected void onCalcButtonClick() {
        double x, y, z;
        x = textInputX.getText();
        y = textInputY.getText();
        z = textInputZ.getText();
        Double()
//        welcomeText.setText("Welcome to JavaFX Application!");
        labelAnswerA.setText("a = " + Model.calcA(x, y));
        labelAnswerB.setText("b = " + Model.calcB(z));
    }
}