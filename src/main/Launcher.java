package main;

import market.Market;
import util.Config;
import util.MyLogger;

import java.util.Timer;
import java.util.TimerTask;

public class Launcher {
    public static Config config;

    public static void main(String[] args) throws Exception {
        MyLogger.setup();
        MyLogger.log("Starting the Server...");

        MyLogger.log("Setting up market...");
        Market.setup();

        MyLogger.log("Loading Config...");
        config = Config.getConfig();

        MyLogger.log("Starting update service...");
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {

            @Override
            public void run() {
                MyLogger.log("Updating the market @ " + System.currentTimeMillis());
                //TODO market update code here
            }

        }, 0, 5000);

        ServerControler.launch();
    }
}
