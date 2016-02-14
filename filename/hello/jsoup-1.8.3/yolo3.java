import java.io.File; 
import java.io.IOException; 
import org.jsoup.Jsoup; 
import org.jsoup.nodes.Document; 
import org.jsoup.nodes.Element; 
import org.jsoup.select.Elements;

import java.util.Scanner;
import java.net.*;
import java.io.*;

/** * Java Program to parse/read HTML documents from File using Jsoup library. * Jsoup is an open source library which allows Java developer to parse HTML * files and extract elements, manipulate data, change style using DOM, CSS and * JQuery like method. * * @author Javin Paul */ 

public class yolo3 { 

    private static Scanner input;

    public static void main(String args[]) { 
    // Parse HTML String using JSoup library 

        System.out.print("Enter a topic: ");
        
        input = new Scanner(System.in);
        String topic = input.nextLine();
        System.out.println(topic);
    
        try { 

            Document doc = Jsoup.connect("https://en.wikipedia.org/wiki/" + topic).get();

            org.jsoup.select.Elements references = doc.select("span.reference-text");

            for (Element e: references) {

                System.out.println(e.ownText());

            } 

        } catch (IOException e) { 

            e.printStackTrace(); 

        } 
    } 
}
