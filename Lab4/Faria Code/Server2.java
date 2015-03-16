import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.File;
import java.net.Socket;
import java.net.ServerSocket;
import java.io.FileInputStream; 
import java.io.IOException;

public class Server2 {
    public static void main(String [] args) throws Exception {
        ServerSocket s = new ServerSocket(8080);
        Socket sock = null;
        while ( (sock = s.accept()) != null) {
            BufferedReader inputReader = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
            String filename;
            filename=inputReader.readLine();
            System.out.println(filename);
            if (filename!=null)
            {
                filename="."+filename;
                File file = new File(filename);
                FileInputStream fr = new FileInputStream(filename);
                writer.write(fr.available());
                byte [] b = new byte [fr.available()];
                int howmany;
                while ( (howmany = fr.read(b)) > 0) {
                 // do something with this data
                }
                fr.close();
                for (int i=0;i<fr.available();i++)
                {
                    writer.write(b[i]);
                }
                writer.close();
            }
            
            
        }
    }
}
