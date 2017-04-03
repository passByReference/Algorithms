import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private int[] grid;
    private int width = 0;
    private int size = 0;
    private int numOfOpenSites = 0;
    private WeightedQuickUnionUF uf;
    private WeightedQuickUnionUF ufNoBottom;

    public Percolation(int n) {
        width = n;
        size = n * n; // size - virtual top site, size + 1 - virtual bottom site
        grid = new int[size];
        uf = new WeightedQuickUnionUF(size + 2);
        ufNoBottom = new WeightedQuickUnionUF(size + 1);
        // 0 closed
        // 1 open
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[width * i + j] = 0;
            }
        }
    
    }
    public void open(int row, int col) {
        if (row > width || col > width) throw new java.lang.IndexOutOfBoundsException("Invalid input");
        if (row < 1 || col < 1) throw new java.lang.IllegalArgumentException("Invalid input");
        if (!isOpen(row, col)) {
            int p = width * (row - 1) + col - 1;
            grid[p] = 1;
            ++numOfOpenSites;
            if (col != width && grid[p + 1] == 1) {
                // site to the right
                uf.union(p, p + 1);
                ufNoBottom.union(p, p + 1);
            }
            
            if (col != 1 && grid[p - 1] == 1) {
                // site to the left
                uf.union(p, p - 1);
                ufNoBottom.union(p, p - 1);
            }
            
            if (row != width) {
                if (grid[p + width] == 1) {
                    // site below
                    uf.union(p, p + width);
                    ufNoBottom.union(p, p + width);
                }
            }
            else {
                // connect to virtual bottom site
                uf.union(p, size + 1);

            }

            if (row != 1) {
                if (grid[p - width] == 1) {
                    // site above
                    uf.union(p, p - width);
                    ufNoBottom.union(p, p - width);
                }
            }
            else {
                // connect to virtual top site
                uf.union(p, size);
                ufNoBottom.union(p, size);
            }
        }
    }

    public boolean isOpen(int row, int col) {
        if (row > width || col > width) throw new java.lang.IndexOutOfBoundsException("Invalid input");
        if (row < 1 || col < 1) throw new java.lang.IllegalArgumentException("Invalid input");
        return grid[width * (row - 1) + col - 1] == 1;
    }
    
    public boolean isFull(int row, int col) {
        if (row > width || col > width) throw new java.lang.IndexOutOfBoundsException("Invalid input");
        if (row < 1 || col < 1) throw new java.lang.IllegalArgumentException("Invalid input");
        int p = width * (row - 1) + col - 1;
        return grid[p] == 1 && ufNoBottom.connected(p, size);
    }

    public int numberOfOpenSites() {
        return numOfOpenSites;
    }

    public boolean percolates() {
        return uf.connected(size, size + 1);
    }
}

