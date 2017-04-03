public class FastCollinearPoints {
        LineSegment[] lineSegments;
        int numberOfLineSegments;
    public FastCollinearPoints(Point[] points){
        if (points == null) throw new NullPointerException();
        numberOfLineSegments = 0;
        lineSegments = new LineSegment[points.length];
        Collections.sort(points, slopeOrder());
        double first = 0.0;
        double second = 0.0;
        double third = 0.0;
        for (int i = 0; i < points.length; i++) {
            first = second;
            second = third;
            third = points[i].slopeTo
        }
        
    }     // finds all line segments containing 4 or more points
    public           int numberOfSegments(){
        return numberOfLineSegments;
    }        // the number of line segments
    public LineSegment[] segments(){
        return lineSegments;
    }               // the line segments

}
