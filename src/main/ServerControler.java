package main;

import client.Client;
import util.MyLogger;

import java.net.ServerSocket;
import java.net.Socket;

public class ServerControler {
    public static void launch() throws Exception {
        ServerSocket serverSocket = new ServerSocket(Launcher.config.port);

        int connections = 0;

        MyLogger.log("Waiting for connection...");

        while (true) {
            Socket s = serverSocket.accept();
            connections++;
            new Client(s, connections).start();
        }
    }
}
