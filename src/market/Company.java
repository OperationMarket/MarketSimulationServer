package market;

public class Company {
    public String name;
    public String abrv;

    private StockQueue stocks;

    public Company(String name, String abrev) {
        this.name = name;
        this.abrv = abrev;
    }

    //TODO remove
    public void generateNewStock() {
        stocks = new StockQueue();
        stocks.push(new Stock(1.0f, this));
        stocks.push(new Stock(2.0f, this));
        stocks.push(new Stock(3.0f, this));
    }

    public StockQueue getStocks() {
        return stocks;
    }
}
