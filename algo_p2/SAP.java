import java.util.Stack;

import edu.princeton.cs.algs4.BreadthFirstDirectedPaths;
import edu.princeton.cs.algs4.Digraph;

public class SAP {
    // constructor takes a digraph (not necessarily a DAG)
    private static final int ROOT = 38003;
    private Digraph graph;

    public SAP(Digraph G) {
        graph = new Digraph(G);
    }

    // length of shortest ancestral path between v and w; -1 if no such path
    public int length(int v, int w) {
        BreadthFirstDirectedPaths bfs_dp_v = new BreadthFirstDirectedPaths(graph, v);
        if (bfs_dp_v.hasPathTo(w)) {
            return bfs_dp_v.distTo(w);
        } else {
            return -1;
        }

    }

    // a common ancestor of v and w that participates in a shortest ancestral path;
    // -1 if no such path
    public int ancestor(int v, int w) {
        BreadthFirstDirectedPaths bfs_dp_v = new BreadthFirstDirectedPaths(graph, v);
        BreadthFirstDirectedPaths bfs_dp_w = new BreadthFirstDirectedPaths(graph, w);

        if (!bfs_dp_v.hasPathTo(w))
            return -1;
        Stack<Integer> v_to_w_path = (Stack<Integer>) bfs_dp_v.pathTo(w);
        Stack<Integer> w_to_v_path = (Stack<Integer>) bfs_dp_w.pathTo(v);
        while (!v_to_w_path.empty()) {
            int aVertex = v_to_w_path.pop();
            int res = w_to_v_path.search(aVertex);
            if (res != -1)
                return aVertex;
        }
        return -1;

    }

    // length of shortest ancestral path between any vertex in v and any vertex in
    // w; -1 if no such path
    public int length(Iterable<Integer> v, Iterable<Integer> w) {
        BreadthFirstDirectedPaths bfs_dp_v = new BreadthFirstDirectedPaths(graph, v);
        Integer min_val = Integer.MAX_VALUE;
        for (Integer wI : w) {
            if (bfs_dp_v.hasPathTo(wI)) {
                if (bfs_dp_v.distTo(wI) < min_val) {
                    min_val = bfs_dp_v.distTo(wI);
                }
            }
        }
        if (min_val == Integer.MAX_VALUE)
            return -1;
        return min_val;
    }

    // a common ancestor that participates in shortest ancestral path; -1 if no such
    // path
    public int ancestor(Iterable<Integer> v, Iterable<Integer> w) {
        BreadthFirstDirectedPaths bfs_dp_v = new BreadthFirstDirectedPaths(graph, v);
        BreadthFirstDirectedPaths bfs_dp_w = new BreadthFirstDirectedPaths(graph, w);
    }

    // do unit testing of this class
    public static void main(String[] args) {

    }
}