import java.util.HashMap;
import java.util.Map;

import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;

public class WordNet {

    private Digraph graph; // graph of synsets and hypernyms
    private Map<Integer, String[]> dict; // key: synset id, value, nouns
    private int V = 0;

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms) {
        if (synsets.isEmpty() || hypernyms.isEmpty()) {
            throw new IllegalArgumentException();
        }
        try {
            dict = new HashMap<Integer, String[]>();
            In synsetsReader = new In(synsets);
            while (synsetsReader.hasNextLine()) {
                String line = synsetsReader.readLine();
                String[] res = line.split(",");
                dict.put(Integer.parseInt(res[0]), res[1].split("\\s+"));
                ++V;
            }
            synsetsReader.close();

            graph = new Digraph(V);
            In hypernymsReader = new In(hypernyms);
            while (hypernymsReader.hasNextLine()) {
                String line = hypernymsReader.readLine();
                String[] res = line.split(",");

                for (int i = 1; i < res.length; ++i) {
                    graph.addEdge(Integer.parseInt(res[0]), Integer.parseInt(res[i]));
                }
            }
            hypernymsReader.close();
        } catch (Exception e) {

        }

    }

    // returns all WordNet nouns
    // public Iterable<String> nouns() {
    //
    // }
    //
    // is the word a WordNet noun?
    public boolean isNoun(String word) {

    }
    //
    // // distance between nounA and nounB (defined below)
    // public int distance(String nounA, String nounB) {
    //
    // }
    //
    // // a synset (second field of synsets.txt) that is the common ancestor of
    // nounA and nounB
    // // in a shortest ancestral path (defined below)
    // public String sap(String nounA, String nounB) {
    //
    // }

    // do unit testing of this class
    public static void main(String[] args) {
        String synsets_filename = "./test_data/synsets.txt";
        String hypernyms_filename = "./test_data/hypernyms.txt";
        WordNet wn = new WordNet(synsets_filename, hypernyms_filename);

    }
}