import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

/**
 * Controller for Page 2 scene.
 */
public class JavaFXSecond_Controller implements Initializable
{

    @FXML
    private Button prevButton;
    
    /**
     * Loads scene for Page 1.
     * @throws Exception 
     */
    @FXML
    public void previousPage() throws Exception
    {
        Parent root = FXMLLoader.load(getClass().getResource("JavaFXHome_.fxml")); // get fxml for Page 1 scene
        Scene scene = new Scene(root);      // create scene from fxml
        scene.setFill(Color.TRANSPARENT);   // set scene background to transparent to allow curved borders
        Stage stage = (Stage) prevButton.getScene().getWindow();    // get stage for this button
        stage.setScene(scene);              // set scene to stage
    }

    
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        // TODO
    }    
    
}
