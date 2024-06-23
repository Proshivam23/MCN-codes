import java.io.*;
import java.net.*;

public class server {

    public static void main(String [] args){
        int portNumber = 12345;

        try{
            
            ServerSocket serverSocket = new ServerSocket(portNumber);
            System.out.println("Server is running and waiting for client connection");

            Socket clientSocket = serverSocket.accept();
            System.out.println("Client Connected: " + clientSocket.getInetAddress());

            InputStream inputStream = clientSocket.getInputStream();
            BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
            
            String message = in.readLine();
            System.out.println(message);

            clientSocket.close();
            serverSocket.close();
            
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}