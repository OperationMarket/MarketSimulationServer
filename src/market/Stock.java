package market;

public class Stock {
    public Company company;
    public float value;

    public Stock(float value, Company company) {
        this.value = value;
        this.company = company;
    }
}
