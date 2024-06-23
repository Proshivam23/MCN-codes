import java.io.*;
import java.net.*;

public class client{
    public static void main(String [] args){
        String serverAddress = "";
        int portNumber = 12345;

        try{
            Socket socket = new Socket(serverAddress, portNumber);
            OutputStream outputStream = socket.getOutputStream();
            PrintWriter out = new PrintWriter(outputStream, true);

            out.println("Hello World!!");
            socket.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}