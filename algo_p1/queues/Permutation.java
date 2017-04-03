import edu.princeton.cs.algs4.StdIn;

public class Permutation {
    public static void main(String[] args) {
        int k = Integer.parseInt(args[0]);
        String[] words = StdIn.readAllStrings();
        RandomizedQueue rq = new RandomizedQueue();
        String[] visited = new String[words.length];
        int n = 0;
        for (int i = 0; i < words.length; i++) {
            rq.enqueue(words[i]);
        }
        int size = words.length;
        for (int i = 0; i < k; i++) {
            String str = rq.sample().toString();
            boolean isVisited = true;
            int counter = 0;
            while (isVisited) {
                isVisited = false;
                for (int j = 0; j < n; ++j) {
                    if (visited[j].equals(str)) {
                        if (counter >= size) break;
                        ++counter;
                        str = rq.sample().toString();
                        isVisited = true;
                        j = -1;
                    }
                }
                isVisited = false;
            }
            System.out.println(str);
            visited[n++] = str;
        }
    }
}

