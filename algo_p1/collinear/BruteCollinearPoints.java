import java.util.HashMap;
import java.util.Map;
public class BruteCollinearPoints {
    LineSegment[] lineSegments;
    int numberOfLineSegments;
    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new NullPointerException(); 
        numberOfLineSegments = 0;
        lineSegments = new LineSegment[points.length];
        for (int i = 0; i < points.length; i++) {
            double[] slopes = new double[points.length];
            Map<Double, Integer> slopeCounter = new HashMap<Double, Integer>();
            for (int j = 0; j < points.length; j++) {
                slopes[j] = points[i].slopeTo(points[j]);
                if (slopeCounter.containsKey(slopes[j])) {
                    slopeCounter.replace(slopes[j], slopeCounter.get(slopes[j]) + 1);
                }
                else slopeCounter.put(slopes[j], 0);
            }
            Double slopeKey = 0.0;
            boolean slopeKeyFound = false;
            for (HashMap.Entry<Double, Integer> entry : slopeCounter.entrySet()) {
                if (entry.getValue() == 3) {
                    slopeKey = entry.getKey();
                    slopeKeyFound = true;
                    break;
                }
            }
            if (slopeKeyFound) {
                for (int j = points.length - 1; j >= 0; --j) {
                    if (slopes[j] == slopeKey) {
                        LineSegment l = new LineSegment(points[i], points[j]);
                        lineSegments[numberOfLineSegments++] = l;
                        break;
                    }
                }
            }
            
        }

        
    }   // finds all line segments containing 4 points
    public           int numberOfSegments() {
        return numberOfLineSegments;
    }        // the number of line segments
    public LineSegment[] segments() {
        return lineSegments;
    }                // the line segments

}
