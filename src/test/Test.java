package test;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Test {
    public static void main (String[] args) throws Exception {
        Socket socket = new Socket();
        socket.connect(new InetSocketAddress("localhost", 6789), 10000);

        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        out.writeBytes("I am Groot\n");

        Thread.sleep(10000);
    }
}
