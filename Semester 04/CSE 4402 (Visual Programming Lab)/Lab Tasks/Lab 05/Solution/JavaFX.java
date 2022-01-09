import javafx.application.Application;
import javafx.stage.Stage;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;

/**
 * Main class for program.
 */
public class JavaFX extends Application
{
    /**
     * Main function for JavaFX window.
     * 
     * @param stage
     * @throws Exception 
     */
    @Override
    public void start(Stage stage) throws Exception
    {
        Parent root = FXMLLoader.load(getClass().getResource("JavaFX.fxml"));
        Scene scene = new Scene(root);
        stage.setTitle("JavaFX");
        stage.setScene(scene);
        stage.show();
    }

    /**
     * Main function for program.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        launch(args);
    }
}
