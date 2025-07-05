module io.github.kawazaki42.task01arith {
    requires javafx.controls;
    requires javafx.fxml;


    opens io.github.kawazaki42.task01arith to javafx.fxml;
    exports io.github.kawazaki42.task01arith;
}