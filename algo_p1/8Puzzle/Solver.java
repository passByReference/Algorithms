import edu.princeton.cs.algs4.MinPQ;
import java.util.LinkedList;
public class Solver {
    private class SearchNode implements Comparable<SearchNode> {
        private Board aBoard = null;
        private SearchNode prevNode = null;
        private int numOfMoves = 0;
        
        public SearchNode(Board aBoard, SearchNode prevNode, int numOfMoves) {
            this.aBoard = aBoard;
            this.prevNode = prevNode;
            this.numOfMoves = numOfMoves;
        }

        @Override
        public int compareTo(SearchNode aNode) {
            return this.aBoard.manhattan() + this.numOfMoves - aNode.aBoard.manhattan() - aNode.numOfMoves;
        }

    }

    private LinkedList<Board> steps;
    private boolean isSolved = false;
    public Solver(Board initial) {
        if (initial == null) throw new NullPointerException();
        steps = new LinkedList<Board>();
        MinPQ<SearchNode> pq = new MinPQ<SearchNode>();
        MinPQ<SearchNode> pqTwin = new MinPQ<SearchNode>();
        pq.insert(new SearchNode(initial, null, 0));
        pqTwin.insert(new SearchNode(initial.twin(), null, 0));
        isSolved = search(pq, pqTwin);
    }
    private boolean search(MinPQ<SearchNode> pq, MinPQ<SearchNode> pqTwin) {
        while (!pq.isEmpty() || !pqTwin.isEmpty()) {
            SearchNode node = null;
            SearchNode nodeTwin = null;
            if (!pq.isEmpty()) node = pq.delMin();
            if (!pqTwin.isEmpty()) nodeTwin = pqTwin.delMin();
            if (node != null) {
                System.out.println(node.aBoard.toString());
                steps.add(node.aBoard);
                if (node.aBoard.isGoal()) {
                    return true;
                }
                int moveCounter = node.numOfMoves;
                moveCounter++;
                for (Board b : node.aBoard.neighbors()) {
                    if (node.prevNode == null || !b.equals(node.prevNode.aBoard)) {
                        pq.insert(new SearchNode(b, node, moveCounter));
                    }
                }
            }
            if (nodeTwin != null) {
                if (nodeTwin.aBoard.isGoal()) {
                    return false;
                }
                int moveCounter = nodeTwin.numOfMoves;
                moveCounter++;
                for (Board b : nodeTwin.aBoard.neighbors()) {
                    if (nodeTwin.prevNode == null || !b.equals(nodeTwin.prevNode.aBoard)) {
                        pqTwin.insert(new SearchNode(b, nodeTwin, moveCounter));
                    }
                }
            }
        }
        return false;

    }

    public boolean isSolvable() {
        return isSolved;
    }

    public int moves() {
        if (this.isSolvable()) return this.steps.size() - 1; 
        else return -1;

    }

    public Iterable<Board> solution() {
        if (this.isSolvable()) return this.steps;
        else return null;
    }

    public static void main(String[] args) {

    }
}
