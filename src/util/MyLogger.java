package util;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Logger;

public class MyLogger {

    static private FileHandler file;
    private static final Logger LOGGER = Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);

    public static void log(String in) {
        LOGGER.info(in);
    }

    public static void setup() throws IOException {
        file = new FileHandler("log");
        LOGGER.addHandler(file);
    }

}
