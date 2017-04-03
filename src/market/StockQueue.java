package market;

public class StockQueue {
    private static final int STOCKS_TO_KEEP = 3;

    private Stock[] values;
    private int addIndex = 0;
    private int removeIndex = 0;
    private int len = 0;

    public StockQueue() {
        values = new Stock[STOCKS_TO_KEEP];
        len = 0;
    }

    public void push(Stock s) {
        if (!(len < STOCKS_TO_KEEP))
            return;

        values[addIndex] = s;
        addIndex = (addIndex + 1) % STOCKS_TO_KEEP;
        len++;
    }

    public Stock pop() {
        if (len < 0)
          return null;
        
        Stock s = values[removeIndex];
        values[removeIndex] = null;

        if (s == null) {
            return null;
        }

        removeIndex = (removeIndex + 1) % STOCKS_TO_KEEP;
        len--;
        return s;
    }

    public int size() {
        return len;
    }
}
