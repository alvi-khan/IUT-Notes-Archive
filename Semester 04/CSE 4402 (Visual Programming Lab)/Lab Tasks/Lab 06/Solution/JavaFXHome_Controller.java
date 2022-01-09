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
import javafx.stage.StageStyle;

/**
 * Controller for Page 1 scene.
 */
public class JavaFXHome_Controller implements Initializable
{

    @FXML
    private Button nextButton;
    
    /**
     * Loads scene for Page 2.
     * @throws Exception 
     */
    @FXML
    public void nextPage() throws Exception
    {
        Parent root = FXMLLoader.load(getClass().getResource("JavaFXSecond.fxml"));   // get fxml for Page 2 scene
        Scene scene = new Scene(root);      // create scene from FXML
        scene.setFill(Color.TRANSPARENT);   // set scene background to transparent to allow borders to be curved.
        Stage stage = (Stage) nextButton.getScene().getWindow();    // get the stage this button is on
        stage.setScene(scene);              // set scene to stage
    }
    
    /**
     * Loads scene for exit confirmation.
     * @throws Exception 
     */
    @FXML
    public void loadExitConfirm() throws Exception
    {
        Parent root = FXMLLoader.load(getClass().getResource("JavaFXExit.fxml")); // get fxml for exit confirmation scene
        Scene scene = new Scene(root);      // create scene from FXML
        scene.setFill(Color.TRANSPARENT);   // set scene background to transparent to allow borders to be curved
        
        Stage stage = (Stage) nextButton.getScene().getWindow();    // get stage this button is on
        Stage popup = new Stage();                  // create a new stage
        popup.setHeight(stage.getHeight() * 0.8);   // make new stage a little smaller than old stage
        popup.setWidth(stage.getWidth() * 0.8);     
        popup.initStyle(StageStyle.UNDECORATED);    // remove title bar
        popup.initStyle(StageStyle.TRANSPARENT);    // allow transparent scenes
        popup.setScene(scene);                      // set scene to stage
        popup.show();                               // open new window
    }

    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        // TODO
    }    
    
}
