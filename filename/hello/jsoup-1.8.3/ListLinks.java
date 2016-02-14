import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.IOException;

/**
 * Example program to list links from a URL.
 */
public class yolo {
    public static void main(String[] args) throws IOException {

        try {
            Document doc = Jsoup.connect("http://en.wikipedia.org/").get();
            Elements newsHeadlines = doc.select("#mp-itn b a");
        } catch (IOException ex) {
            System.out.println(ex);    
        }
    }
}