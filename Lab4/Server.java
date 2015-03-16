import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.ServerSocket;
import java.io.IOException;
import java.io.File;
import java.io.FileNotFoundException;

public class Server
{
	public static void main(String [] args) throws Exception
	{
		ServerSocket s = new ServerSocket(8080);
		Socket sock = null;

		while((sock=s.accept())!=null)
		{
			int lineNum=0,sum=0;
			BufferedReader reader = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
			String line=null,filename=null;
			filename= reader.readLine();
			if(filename!=null)
			{
				try{
					FileReader fr= new FileReader(filename);
					BufferedReader br= new BufferedReader(fr);	
					long len = new File(filename).length();
			
					br.mark(100);
					// finding out number of lines of the file
					while((line = br.readLine()) != null)
					{
						sum=sum+line.length();
					}

					writer.write(Integer.toString(sum));
					System.out.println("Size sent: "+sum);

					// now sending the content to client
					br.reset();
					while((line = br.readLine()) != null)
					{
						System.out.println(line);
						line=line+"\n";
						writer.write(line);
					}

					br.close();	
					writer.close();	
				}
				catch(FileNotFoundException err)
				{
					System.out.println("Exception caught: "+err+". File not found!");
					break;
				}
			}
			else
			{
				System.out.println("No such file found!");
				writer.close();
			}	
			
		}
		
	}
}