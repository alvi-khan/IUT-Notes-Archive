import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

/**
 * FXML Controller class
 */
public class JavaFX_Controller implements Initializable
{
    @FXML
    private Label nameOutput;       // default blank label where user input will be shown
    @FXML
    private TextField userInput;    // text field for user input
    @FXML
    private Button exitButton;
    
    /**
     * Function to display the user input from the text field in the blank label.
     */
    @FXML
    public void displayName()
    {
        nameOutput.setText(userInput.getText() + "!");
    }
    
    /**
     * Function to close the window when user clicks the exit button.
     */
    @FXML
    public void exitProgram()
    {
        Stage stage = (Stage) exitButton.getScene().getWindow();
        // get the window in which the button is placed
        stage.close();              // close the window
    }

    /**
     * Initializes the controller class.
     * 
     * @param url
     * @param rb 
     */
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        
    }
}
