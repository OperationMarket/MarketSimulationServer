package main;

import market.Market;
import util.Config;
import util.MyLogger;

public class Launcher {
    public static Config config;

    public static void main(String[] args) throws Exception {
        MyLogger.setup();
        MyLogger.log("Starting the Server...");

        MyLogger.log("Setting up market...");
        Market.setup();

        MyLogger.log("Loading Config...");
        config = Config.getConfig();

        ServerControler.launch();
    }
}
