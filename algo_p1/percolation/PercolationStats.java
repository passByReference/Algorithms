import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.Stopwatch;

public class PercolationStats {
    private double[] meanArr;
    private double meanVal = 0.0;
    private double stddevVal = 0.0;
    private double confidenceLoVal = 0.0;
    private double confidenceHiVal = 0.0;

    public PercolationStats(int n, int trials) {
        meanArr = new double[trials];
        int counter = 0;
        while (counter < trials) {
            Percolation perc = new Percolation(n);
            while (!perc.percolates()) {
                int randRow = StdRandom.uniform(1, n + 1);
                int randCol = StdRandom.uniform(1, n + 1);

                perc.open(randRow, randCol);
                
            }
            meanArr[counter] = (1.0 * perc.numberOfOpenSites()) / (n * n);
            ++counter;
        }
        meanVal         = StdStats.mean(meanArr);
        stddevVal       = StdStats.stddev(meanArr);
        confidenceLoVal = meanVal - 1.96 * stddevVal / Math.sqrt(trials);
        confidenceHiVal = meanVal + 1.96 * stddevVal / Math.sqrt(trials);
    }

    public double mean() {
        return meanVal;
    }

    public double stddev() {
        return stddevVal;
    }

    public double confidenceLo() {
        return confidenceLoVal;
    }

    public double confidenceHi() {
        return confidenceHiVal;
    }

    public static void main(String[] args) {
        int n = -1;
        int numOfTrials = -1;
        if (args.length > 0) {
            n = Integer.parseInt(args[0]);
            System.out.println("n = " + n);
            numOfTrials = Integer.parseInt(args[1]);
            System.out.println("numOfTrials = " + numOfTrials);
        }

        if (n > 0 && numOfTrials > 0) {
            Stopwatch stopwatch = new Stopwatch();
            PercolationStats pStats = new PercolationStats(n, numOfTrials);
            double elapsedTime = stopwatch.elapsedTime();
            System.out.println("mean                    = " + pStats.mean());
            System.out.println("stddev                  = " + pStats.stddev());
            System.out.println("95% confidence interval = " + "[" + pStats.confidenceLo() + ", " +
                               pStats.confidenceHi() + "]");
            System.out.println("elapsed time            = " + elapsedTime);
        }
        else {
            throw new java.lang.IllegalArgumentException("Invalid inputs");
        }


    }
}
