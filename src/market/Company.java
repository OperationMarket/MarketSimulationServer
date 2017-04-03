package market;

import java.util.PriorityQueue;
import java.util.Queue;

public class Company {
    public String name;
    public String abrv;

    private Queue<Stock> stocks;

    public Company(String name, String abrev) {
        this.name = name;
        this.abrv = abrev;
    }

    //TODO remove
    public void generateNewStock() {
        stocks = new PriorityQueue<>();
        stocks.add(new Stock(1.0f, this));
        stocks.add(new Stock(2.0f, this));
        stocks.add(new Stock(3.0f, this));
    }

    public Queue<Stock> getStocks() {
        return stocks;
    }
}
