import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import java.util.ArrayList;

public class PointSET {
    private SET<Point2D> points;
    /*
    private class PointComparator implements Comparator<Point2D> {
        @Override
        public int compare(Point2D a, Point2D b) {
            return 
        }
    }
    */
    public PointSET() {
        points = new SET<Point2D>();

    }

    public boolean isEmpty() {
        return points.isEmpty();
    }

    public int size() {
        return points.size();
    }


    public void insert(Point2D p) {
        if (p == null) throw new NullPointerException();
        points.add(p);
    }

    public boolean contains(Point2D p) {
        if (p == null) throw new NullPointerException();
        return points.contains(p);
    }

    public void draw() {
        for (Point2D point : this.points) {
            point.draw();
        }
    }

    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null) throw new NullPointerException();
        ArrayList<Point2D> result = new ArrayList<Point2D>();
        for (Point2D p : this.points) {
            if (rect.contains(p)) {
                result.add(p);
            }
        }
        return result;

        
    }

    public Point2D nearest(Point2D p) {
        if (p == null) throw new NullPointerException();
        if (this.points.isEmpty()) return null;
        Point2D nearestPoint = this.points.max();
        double nearestDistance = nearestPoint.distanceSquaredTo(p);
        double currentDistance = 0.0;
        for (Point2D point : this.points) {
            currentDistance = point.distanceSquaredTo(p);
            if (currentDistance < nearestDistance) {
                nearestDistance = currentDistance;
                nearestPoint = point;
            }
        }

        return nearestPoint;
    }
}
