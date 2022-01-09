import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import javafx.stage.WindowEvent;

/**
 * Main class for program.
 */
public class JavaFX extends Application
{
    
    /**
     * Starts FXML application window.
     * @param stage
     * @throws Exception 
     */
    @Override
    public void start(Stage stage) throws Exception
    {
        
        Parent root = FXMLLoader.load(getClass().getResource("JavaFXHome.fxml")); // get fxml for Page 1 scene
        
        Scene scene = new Scene(root);      // create scene from fxml
        scene.setFill(Color.TRANSPARENT);   // set scene background to transparent to allow curved border
        
        stage.initStyle(StageStyle.UNDECORATED);    // remove title bar
        stage.initStyle(StageStyle.TRANSPARENT);    // allow transparent scenes
        stage.setScene(scene);                      // set scene to stage
        stage.show();                               // display stage
        
        stage.setOnCloseRequest((WindowEvent e) ->  // ensures that all windows opened by the program are closed if the main window is closed
        {
            Platform.exit();
            System.exit(0);
        });
    }

    
    public static void main(String[] args)
    {
        launch(args);
    }
    
}
