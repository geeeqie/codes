public class Percolation {
    private boolean[] grid;
    private WeightedQuickUnionUF uf; /* with VTOP and VBOTTOM */
    private WeightedQuickUnionUF uftop; /* only add VTOP */
    private int n;
    private int VTOP, VBOTTOM;

    // create N-by-N grid, with all sites blocked
    public Percolation(int N)
    {
        n = N;
        grid = new boolean[N*N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i*N + j] = false;
            }
        }
        uf = new WeightedQuickUnionUF(N*N+2);
        uftop = new WeightedQuickUnionUF(N*N+1);
        VTOP = N*N;
        VBOTTOM = N*N + 1;
    }

    // open site (row i, column j) if it is not already
    public void open(int i, int j)
    {
        int r = i - 1;
        int c = j - 1;

        validate(r, c);
        grid[r*n + c] = true;
        // connect up
        if (r > 0 && grid[(r-1)*n + c]) {
            uf.union(r*n+c, (r-1)*n + c);
            uftop.union(r*n+c, (r-1)*n + c);
        }
        /* connect down */
        if (r < n-1 && grid[(r+1)*n + c]) {
            uf.union(r*n+c, (r+1)*n + c);
            uftop.union(r*n+c, (r+1)*n + c);
        }
        /* connect left */
        if (c > 0 && grid[r*n + (c-1)]) {
            uf.union(r*n+c, r*n+(c-1));
            uftop.union(r*n+c, r*n+(c-1));
        }
        /* connect right */
        if (c < n-1 && grid[r*n + (c+1)]) {
            uf.union(r*n+c, r*n+(c+1));
            uftop.union(r*n+c, r*n+(c+1));
        }

        /* connect virtual top */
        if (r == 0) {
            uf.union(r*n+c, VTOP);
            uftop.union(r*n+c, VTOP);
        }
        /* connect virtual bottom */
        if (r == n-1) {
            uf.union(r*n+c, VBOTTOM);
        }
    }

    // is site (row i, column j) open?
    public boolean isOpen(int i, int j)
    {
        int r = i - 1;
        int c = j - 1;
        validate(r, c);
        return grid[r*n + c];
    }

    // is site (row i, column j) full?
    public boolean isFull(int i, int j)
    {
        int r = i - 1;
        int c = j - 1;
        validate(r, c);
        return uftop.connected(r*n+c, VTOP);
    }

    // does the system percolate?
    public boolean percolates()
    {
        return uf.connected(VTOP, VBOTTOM);
    }

    private void validate(int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n) {
            throw new IndexOutOfBoundsException();
        }
    }
}
