public class PercolationStats {
    private double[] x;

    // perform T independent computational experiments on an N-by-N grid
    public PercolationStats(int N, int T)
    {
        if (N <= 0 || T <= 0) {
            throw new IllegalArgumentException();
        }

        x = new double[T];

        for (int t = 0; t < T; t++) {
            Percolation p = new Percolation(N);

            int count = 0;
            while (!p.percolates()) {
                int i, j;
                do {
                    i = StdRandom.uniform(1, N+1);
                    j = StdRandom.uniform(1, N+1);
                } while (p.isOpen(i, j));
                p.open(i, j);
                count++;
            }
            x[t] = Double.valueOf(count) / (N*N);
        }
    }
    // sample mean of percolation threshold
    public double mean()
    {
        return StdStats.mean(x);
    }
    // sample standard deviation of percolation threshold
    public double stddev()
    {
        return StdStats.stddev(x);
    }

    // returns lower bound of the 95% confidence interval
    public double confidenceLo()
    {
        double mu = mean();
        double sigma = stddev();
        return mu - 1.96*sigma / Math.sqrt(x.length);
    }
    // returns upper bound of the 95% confidence interval
    public double confidenceHi()
    {
        double mu = mean();
        double sigma = stddev();
        return mu + 1.96*sigma / Math.sqrt(x.length);
    }
    // test client, described below
    public static void main(String[] args)
    {
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);
        PercolationStats ps = new PercolationStats(N, T);
        StdOut.printf("mean\t\t\t\t= %f\n", ps.mean());
        StdOut.printf("stddev\t\t\t= %f\n", ps.stddev());
        StdOut.printf("95%% confidence interval\t= %f, %f\n",
                ps.confidenceLo(), ps.confidenceHi());
    }
}
