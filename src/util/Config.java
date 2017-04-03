package util;

import java.io.File;
import java.util.Scanner;

public class Config {
    public int port;

    private Config() throws Exception {
        Scanner in = new Scanner(new File("config"));
        port = in.nextInt();
        MyLogger.log("Port: " + port);
    }

    public static Config getConfig() throws Exception {
        return new Config();
    }
}
