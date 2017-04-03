package client;

import util.MyLogger;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client implements Runnable {
    private Thread t;
    private String tName;
    private Socket socket;
    private String playerName;

    public Client(Socket s, int id) throws Exception{
        this.socket = s;
        this.tName = "" + id;
    }

    public void run() {
        MyLogger.log("Accepted a connection!");
        try {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            playerName = in.readLine();
            MyLogger.log("Name: " + playerName);

        } catch (Exception e) {
            MyLogger.log("Unexpected transmision failure for: " + socket.getInetAddress());
            e.printStackTrace();
        }
    }

    public void start() {
        t = new Thread(this, tName);
        t.start();
    }
}
