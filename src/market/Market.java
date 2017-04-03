package market;

import java.util.HashMap;
import java.util.Queue;

public class Market {

    public static HashMap<String, Queue<Stock>> stocks;

    public static void setup() {
        stocks = new HashMap<>();
        Company loronar = new Company("loronar", "lnar");
        loronar.generateNewStock();
        stocks.put(loronar.abrv, loronar.getStocks());
    }
}
