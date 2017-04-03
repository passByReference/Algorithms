import java.util.ArrayList;
import edu.princeton.cs.algs4.StdRandom;
public class Board {
    private int [][] board;
    private int dimension = 0;
    public Board(int[][] blocks) {
        dimension = blocks.length;
        board = new int[dimension][dimension];
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                board[i][j] = blocks[i][j];
            }
        }
    }

    public int dimension() {
        return dimension;
    }

    public int hamming() {
        int hammingCounter = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (board[i][j] != 0 && board[i][j] != dimension * i + j + 1) hammingCounter++;
            }
        }
        return hammingCounter;
    }

    public int manhattan() {
        int manhattanDistance = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (board[i][j] == 0) continue;
                for (int x = 0; x < dimension; x++) {
                    for (int y = 0; y < dimension; y++) {
                        if ((dimension * x + y + 1) == board[i][j]) {
                            manhattanDistance += Math.abs(i - x) + Math.abs(j - y);
                            break;
                        }
                    }
                }
            }
        }
        return manhattanDistance;
    }

    public boolean isGoal() {
        if (board != null) {
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    if (board[i][j] != 0 && board[i][j] != (dimension * i + j + 1)) return false;
                }
            }
            return true;
        }
        return false;
    }

    public Board twin() {
        int i1 = StdRandom.uniform(0, dimension);
        int j1 = StdRandom.uniform(0, dimension);
        int i2 = StdRandom.uniform(0, dimension);
        int j2 = StdRandom.uniform(0, dimension);

        while (((i1 == i2) && (j1 == j2)) || this.board[i1][j1] == 0 || this.board[i2][j2] == 0) {
            i1 = StdRandom.uniform(0, dimension);
            j1 = StdRandom.uniform(0, dimension);
            i2 = StdRandom.uniform(0, dimension);
            j2 = StdRandom.uniform(0, dimension);
        }
        Board aBoard = new Board(swapBlocks(i1, j1, i2, j2));
        return aBoard;
    }

    public boolean equals(Object y) {
        if (y == null) return false;
        if (y.getClass().equals(this.getClass())) {
            // check if y is of type Board
            if (((Board) y).dimension != dimension) return false;
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    if (board[i][j] != ((Board) y).board[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }

    public Iterable<Board> neighbors() {
        ArrayList<Board> neighbors = new ArrayList<Board>();
        int emptyRow = 0;
        int emptyCol = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (board[i][j] == 0) {
                    emptyRow = i;
                    emptyCol = j;
                    break;
                }
            }
        }

        // four possible moves
        // move left
        try {
            Board aBoardLeft = new Board(swapBlocks(emptyRow - 1, emptyCol, emptyRow, emptyCol));
            if (aBoardLeft.board != null) {
                neighbors.add(aBoardLeft);
            }
        } catch (NullPointerException e) {
        }
        // move right
        try {
            Board aBoardRight = new Board(swapBlocks(emptyRow + 1, emptyCol, emptyRow, emptyCol));
            if (aBoardRight.board != null) {
                neighbors.add(aBoardRight);
            }
        } catch (NullPointerException e) {
        }
        // move down
        try {
            Board aBoardDown = new Board(swapBlocks(emptyRow, emptyCol + 1, emptyRow, emptyCol));
            if (aBoardDown.board != null) {
                neighbors.add(aBoardDown);
            }
        } catch (NullPointerException e) {
        }
        // move up
        try {
            Board aBoardUp = new Board(swapBlocks(emptyRow, emptyCol - 1, emptyRow, emptyCol));
            if (aBoardUp.board != null) {
                neighbors.add(aBoardUp);
            }
        } catch (NullPointerException e) {
        }
        
        return neighbors;
       
    }

    private int[][] swapBlocks(int row, int col, int emptyRow, int emptyCol) {
        if (this.board != null && row >= 0 && row < dimension && col >= 0 && col < dimension) {
            int [][] newBoard = new int[dimension][dimension];
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    newBoard[i][j] = this.board[i][j];
                }
            }
            int temp = newBoard[emptyRow][emptyCol];
            newBoard[emptyRow][emptyCol] = newBoard[row][col];
            newBoard[row][col] = temp;
            return newBoard;
        }
        return null;
    }

    public String toString() {
        StringBuilder theBoard = new StringBuilder();
        theBoard.append(Integer.toString(dimension) + "\n");
        if (this.board != null) {
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    theBoard.append(Integer.toString(this.board[i][j]) + " ");
                }
                theBoard.append("\n");
            }
        }
        return theBoard.toString();
    }
}
