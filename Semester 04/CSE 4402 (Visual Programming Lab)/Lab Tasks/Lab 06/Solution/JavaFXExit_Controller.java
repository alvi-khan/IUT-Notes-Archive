import java.net.URL;
import java.util.ResourceBundle;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;

/**
 * Controller for exit confirmation scene.
 */
public class JavaFXExit_Controller implements Initializable
{

    @FXML
    private Button noButton;
    
    /**
     * Function called to exit program.
     */
    @FXML
    public void exitProgram()
    {
        Platform.exit();
    }
    
    /**
     * Function called to hide exit confirmation scene.
     */
    @FXML
    public void exitStage()
    {
        noButton.getScene().getWindow().hide();
    }

    
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        // TODO
    }    
    
}
