import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.StdDraw;
import java.util.ArrayList;
import java.util.Stack;
import java.util.LinkedList;
/*
 *  Contains findMin() and findMax() point in subtrees
 */
public class KdTree {
    private class TreeNode {
        private Point2D point;
        private int height;
        private TreeNode left;
        private TreeNode right;

        public TreeNode(Point2D p) {
            point = p;
            height = 0;
            left = null;
            right = null;
        }
    }
    private TreeNode root;
    private int treeSize;

//////////// Constructor //////////////
    public KdTree() {
        root = null;
        treeSize = 0;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public int size() {
       return treeSize; 
    }

    public void insert(Point2D p) {
        if (p == null) throw new NullPointerException();
        if (this.contains(p)) return;

        TreeNode currNode = root;
        TreeNode parentNode = null;
        while (currNode != null) {
            parentNode = currNode;
            if (currNode.height % 2 == 0) {
                if (p.x() < currNode.point.x()) currNode = currNode.left;
                else currNode = currNode.right;
            }
            else {
                if (p.y() < currNode.point.y()) currNode = currNode.left;
                else currNode = currNode.right;
            }

        }
        TreeNode newNode = new TreeNode(p);
        ++treeSize;
        if (parentNode != null) newNode.height = parentNode.height + 1;
        else { // empty tree, newNode becomes root
            root = newNode;
            return;
        }
        
        if (parentNode.height % 2 == 0) {
            if (newNode.point.x() < parentNode.point.x()) parentNode.left = newNode;
            else parentNode.right = newNode;
        }
        else {
            if (newNode.point.y() < parentNode.point.y()) parentNode.left = newNode;
            else parentNode.right = newNode;
        }

    }

    public boolean contains(Point2D p) {
        if (isEmpty()) return false;
        TreeNode currNode = root;
        while (currNode != null) {
            if (currNode.point.equals(p)) {
                return true;
            }
            else if (currNode.height % 2 == 0) {
                if (p.x() < currNode.point.x()) currNode = currNode.left;
                else currNode = currNode.right;
            }
            else {
                if (p.y() < currNode.point.y()) currNode = currNode.left;
                else currNode = currNode.right;
            }
        }
        return false;
    }

    public void draw() {
        TreeNode currNode = root;
        LinkedList<TreeNode> toVisit = new LinkedList<TreeNode>();
        toVisit.add(currNode);

        while (!toVisit.isEmpty()) {
            currNode = toVisit.remove();
            if (currNode.height % 2 == 0) {
                StdDraw.setPenColor(StdDraw.RED);
                StdDraw.line(currNode.point.x(), 0.0, currNode.point.x(), 1.0);
                StdDraw.setPenColor(StdDraw.BLACK);
                currNode.point.draw();
            }
            else {
                StdDraw.setPenColor(StdDraw.BLUE);
                StdDraw.line(0.0, currNode.point.y(), 1.0, currNode.point.y());
                StdDraw.setPenColor(StdDraw.BLACK);
                currNode.point.draw();
            }
            if (currNode.left != null) toVisit.add(currNode.left);
            if (currNode.right != null) toVisit.add(currNode.right);
        }
    }

    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null) throw new NullPointerException();
        
        ArrayList<Point2D> result = new ArrayList<Point2D>();
        TreeNode currNode = root;
        LinkedList<TreeNode> potentialArea = new LinkedList<TreeNode>();
        potentialArea.add(currNode);

        while (!potentialArea.isEmpty()) {
            currNode = potentialArea.remove();
            if (rect.contains(currNode.point)) result.add(currNode.point);
            if (currNode.left != null) {
                Point2D minPoint = findMin(currNode.left);
                Point2D maxPoint = findMax(currNode.left);
                RectHV nodeRect = new RectHV(minPoint.x(), minPoint.y(), maxPoint.x(), maxPoint.y());
                if (nodeRect.intersects(rect)) potentialArea.add(currNode.left);
            }
            if (currNode.right != null) {
                Point2D minPoint = findMin(currNode.right);
                Point2D maxPoint = findMax(currNode.right);
                RectHV nodeRect = new RectHV(minPoint.x(), minPoint.y(), maxPoint.x(), maxPoint.y());
                if (nodeRect.intersects(rect)) potentialArea.add(currNode.right);
            }
        }

        return result;

    }

    public Point2D nearest(Point2D p) {
        if (p == null || root == null) throw new NullPointerException();

        TreeNode currNode = root;
        Point2D nearestPoint = null;
        double minDistance = p.distanceTo(currNode.point);
        LinkedList<TreeNode> potentialArea = new LinkedList<TreeNode>();
        potentialArea.add(currNode);

        while (!potentialArea.isEmpty()) {
            currNode = potentialArea.remove();
            double currDistance = currNode.point.distanceTo(p);
            if (currDistance < minDistance) {
                minDistance = currDistance;
                nearestPoint = currNode.point;
            }
            
            if (currNode.left != null) {
                Point2D minPoint = findMin(currNode.left);
                Point2D maxPoint = findMax(currNode.left);
                RectHV nodeRect = new RectHV(minPoint.x(), minPoint.y(), maxPoint.x(), maxPoint.y());
                if (nodeRect.distanceTo(p) < minDistance) potentialArea.add(currNode.left);
            }
            if (currNode.right != null) {
                Point2D minPoint = findMin(currNode.right);
                Point2D maxPoint = findMax(currNode.right);
                RectHV nodeRect = new RectHV(minPoint.x(), minPoint.y(), maxPoint.x(), maxPoint.y());
                if (nodeRect.distanceTo(p) < minDistance) potentialArea.add(currNode.right);
            }
            
        }

        return nearestPoint;
    }
    // Private methods
    private Point2D findMin(TreeNode node) {
        if (node == null) throw new NullPointerException();
        double minX = node.point.x();
        double minY = node.point.y();
        Stack<TreeNode> toVisit = new Stack<TreeNode>();
        toVisit.push(node);
        while (!toVisit.isEmpty()) {
            node = toVisit.pop();
            if (node.point.x() < minX) minX = node.point.x();
            if (node.point.y() < minY) minY = node.point.y();
            if (node.right != null) toVisit.push(node.right);
            if (node.left != null) toVisit.push(node.left);
        }
        Point2D minPoint = new Point2D(minX, minY);
        return minPoint;
    }
    
    private Point2D findMax(TreeNode node) {
        if (node == null) throw new NullPointerException();
        double maxX = node.point.x();
        double maxY = node.point.y();
        Stack<TreeNode> toVisit = new Stack<TreeNode>();
        toVisit.push(node);
        while (!toVisit.isEmpty()) {
            node = toVisit.pop();
            if (node.point.x() > maxX) maxX = node.point.x();
            if (node.point.y() > maxY) maxY = node.point.y();
            if (node.right != null) toVisit.push(node.right);
            if (node.left != null) toVisit.push(node.left);
        }
        Point2D maxPoint = new Point2D(maxX, maxY);
        return maxPoint;
    }
}
