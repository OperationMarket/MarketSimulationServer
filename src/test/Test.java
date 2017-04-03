package test;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Arrays;

public class Test {
    public static void main (String[] args) throws Exception {
        Socket socket = new Socket();
        socket.connect(new InetSocketAddress("localhost", 6789), 10000);

        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        out.writeBytes("I am Groot\n");

        int size = in.read();
        System.out.println(size);

        float[] fl = new float[size];

        for (int i = 0; i < size; i++) {
            fl[i] = Float.parseFloat(in.readLine());
        }

        System.out.println(Arrays.toString(fl));

        //Thread.sleep(10000);
    }
}
