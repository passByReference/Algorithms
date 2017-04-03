import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.StdDraw;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
public class KdTree {
    private class TreeNode {
        private Point2D point;
        private int height;
        private double maxX; // stores max x coordinate in the subtree (including current node) 
        private double maxY; // stores max y coordinate in the subtree (including current node)
        private double minX; // stores min x ...
        private double minY; // stores min y ...
        private TreeNode left;
        private TreeNode right;

        public TreeNode(Point2D p) {
            point = p;
            height = 0;
            maxX = p.x();
            maxY = p.y();
            minX = maxX;
            minY = maxY;
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
        double pX = p.x();
        double pY = p.y();
        TreeNode currNode = root;
        TreeNode parentNode = null;
        while (currNode != null) {
            parentNode = currNode;
            // updates maxes and mins in each node along the insertion path
            // running time is log(n)
            if (pX > currNode.maxX) currNode.maxX = pX;
            else if (pX < currNode.minX) currNode.minX = pX;
            if (pY > currNode.maxY) currNode.maxY = pY;
            else if (pY < currNode.minY) currNode.minY = pY;

            if (currNode.height % 2 == 0) {
                if (pX < currNode.point.x()) currNode = currNode.left;
                else currNode = currNode.right;
            }
            else {
                if (pY < currNode.point.y()) currNode = currNode.left;
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
        if (p == null) throw new NullPointerException();
        if (isEmpty()) return false;
        TreeNode currNode = root;
        double pX = p.x();
        double pY = p.y();
        while (currNode != null) {
            if (currNode.point.equals(p)) {
                return true;
            }
            else if (currNode.height % 2 == 0) {
                if (pX < currNode.point.x()) currNode = currNode.left;
                else currNode = currNode.right;
            }
            else {
                if (pY < currNode.point.y()) currNode = currNode.left;
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
        if (this.isEmpty()) return result;
        TreeNode currNode = root;
        LinkedList<TreeNode> potentialArea = new LinkedList<TreeNode>(); // used as a queue with O(1) deletion from the head
        potentialArea.add(currNode);

        while (!potentialArea.isEmpty()) {
            currNode = potentialArea.remove();
            if (rect.contains(currNode.point)) result.add(currNode.point);
            // if left rectangle or right rectangle intersects with rect, it is added to the queue
            if (currNode.left != null) {
                RectHV leftRect = new RectHV(currNode.left.minX, currNode.left.minY, 
                                             currNode.left.maxX, currNode.left.maxY);
                if (leftRect.intersects(rect)) potentialArea.add(currNode.left);
            }
            if (currNode.right != null) {
                RectHV rightRect = new RectHV(currNode.right.minX, currNode.right.minY,
                                             currNode.right.maxX, currNode.right.maxY);
                if (rightRect.intersects(rect)) potentialArea.add(currNode.right);
            }
        }

        return result;

    }

    public Point2D nearest(Point2D p) {
        if (p == null) throw new NullPointerException();
        if (root == null) return null;
        TreeNode currNode = root;
        Point2D nearestPoint = root.point; // initialize it to root.point not null. If it is null and the root is the 
                                           // closest point, then it is an insidious bug
        double minDistance = p.distanceTo(currNode.point);
        Stack<TreeNode> potentialArea = new Stack<TreeNode>(); // use stack to make sure the subtree on the same side 
                                                               // of splitting line as the query point
        potentialArea.push(currNode);

        while (!potentialArea.isEmpty()) {
            currNode = potentialArea.pop();
            double currDistance = currNode.point.distanceTo(p);
            if (currDistance < minDistance) {
                minDistance = currDistance;
                nearestPoint = currNode.point;
            }
            
            // Case 1: both subtree exist
            if (currNode.left != null && currNode.right != null) {
                /*
                 * In this case, we first determine if p is to the left of currNode or not,
                 * then we check both subtrees to see if the distance of p to their rectangle
                 * is less than minDistance so far, if it is then it is labeled as promising.
                 * If both subtrees are promising, we push leftNode and rightNodet to the stack
                 * based on if p is to the left of currNode or not
                 * 
                 */
                RectHV leftRect = new RectHV(currNode.left.minX, currNode.left.minY, 
                                             currNode.left.maxX, currNode.left.maxY);
                
                RectHV rightRect = new RectHV(currNode.right.minX, currNode.right.minY,
                                              currNode.right.maxX, currNode.right.maxY);
                boolean isLeft = false; // stores whether p is to the left of currNode or not
                if (currNode.height % 2 == 0) {
                    if (p.x() < currNode.point.x()) isLeft = true;
                } else {
                    if (p.y() < currNode.point.y()) isLeft = true;
                }
                boolean isLeftPromising = false;
                isLeftPromising = leftRect.distanceTo(p) < minDistance;
                boolean isRightPromising = false;
                isRightPromising = rightRect.distanceTo(p) < minDistance;
                
                if (isLeftPromising && isRightPromising) {
                    if (isLeft) {
                        potentialArea.push(currNode.right);
                        potentialArea.push(currNode.left);
                    } else {
                        potentialArea.push(currNode.left);
                        potentialArea.push(currNode.right);
                    }
                } else if (isLeftPromising) {
                    potentialArea.push(currNode.left);
                } else if (isRightPromising) {
                    potentialArea.push(currNode.right);
                }
                
            }
            else if (currNode.left != null) { // case 2: only left subtree exists
                RectHV leftRect = new RectHV(currNode.left.minX, currNode.left.minY, 
                                             currNode.left.maxX, currNode.left.maxY);
                if (leftRect.distanceTo(p) < minDistance) {
                    potentialArea.push(currNode.left);
                }
            }
            else if (currNode.right != null) { // case 3: only right subtree exists
                RectHV rightRect = new RectHV(currNode.right.minX, currNode.right.minY,
                                             currNode.right.maxX, currNode.right.maxY);

                if (rightRect.distanceTo(p) < minDistance) {
                    potentialArea.push(currNode.right);
                }
            }   
        }

        return nearestPoint;
    }
}
