/**
 *  @direction: Convex hull
 *  @author: 143 liukai
 */
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class ConvexHull extends JFrame {

    Show show = null;

    public static void main(String[] args) {

        new ConvexHull();

    }

    ConvexHull() {
        show = new Show();
        this.add(show);
        this.setSize(500, 500);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static class Show extends JPanel {
        private static final long serialVersionUID = 1L;

        @Override
        public void paint(Graphics g) {
            super.paint(g);

            ArrayList<Point> points = get_points();
            ArrayListPrint(points);
            for (int i = 0; i <= points.size() - 1; i++) {
                g.fillOval(points.get(i).x, points.get(i).y, 6, 6);
                g.setColor(Color.black);
            }

            ArrayList<Point> endpoint = get_endpoint(points);

            for (int i = 0; i <= endpoint.size() - 1; i++) {
                for (int j = 0; j < endpoint.size() - i - 1; j++) {
                    if (getAngle(endpoint.get(j), get_center(endpoint)) > getAngle(endpoint.get(j + 1),
                            get_center(endpoint))) {
                        Point t = endpoint.get(j);
                        Point s = endpoint.get(j + 1);
                        endpoint.set(j, s);
                        endpoint.set(j + 1, t);
                    }
                }
            }
            for (int i = 0; i <= endpoint.size() - 1; i++) {
                if (i == endpoint.size() - 1) {
                    g.drawLine(endpoint.get(i).x, endpoint.get(i).y, endpoint.get(0).x, endpoint.get(0).y);
                } else {
                    g.drawLine(endpoint.get(i).x, endpoint.get(i).y, endpoint.get(i + 1).x, endpoint.get(i + 1).y);
                }
            }
            System.out.println("V:");
            ArrayListPrint(endpoint);
        }
    }

    // Center of gravity
    public static Point get_center(ArrayList<Point> endpoint) {
        double X = 0, Y = 0;
        for (int i = 0; i < endpoint.size(); i++) {
            X += endpoint.get(i).x;
            Y += endpoint.get(i).y;
        }
        Point center = new Point((int) X / endpoint.size(), (int) Y / endpoint.size());
        return center;
    }

    public static ArrayList<Point> get_points() {
        ArrayList<Point> points = new ArrayList<Point>(); //
        for (int i = 0; i < 1000; i++)
            points.add(new Point(new Random().nextInt(400), new Random().nextInt(400)));
        // debug infomation
        /*
         * points.add( new Point(230, 258)); points.add( new Point(240, 169));
         * points.add( new Point(387, 104));
         */
        /*
         * points.add( new Point(63, 251)); points.add( new Point(96, 202)); points.add(
         * new Point(118, 221)); points.add( new Point(134, 216)); points.add( new
         * Point(193, 26)); points.add( new Point(222, 113)); points.add( new Point(222,
         * 146)); points.add( new Point(256, 248)); points.add( new Point(286, 45));
         * points.add( new Point(346, 149));
         */
        Collections.sort(points, new Comparator<Point>() { //
            @Override
            public int compare(Point o1, Point o2) {
                if (o1.x < o2.x)
                    return -1;
                if (o1.x > o2.x)
                    return 1;
                return 0;
            }
        });
        return points;
    }

    //
    public static ArrayList<Point> get_endpoint(ArrayList<Point> points) {
        ArrayList<Point> endpoint = new ArrayList<Point>(); //
        int left = 0;
        int right = points.size() - 1;
        endpoint.add(points.get(left));
        endpoint.add(points.get(right)); //
        findUpPoint(left, right, points, endpoint); //
        findDownPoint(left, right, points, endpoint); //
        // ArrayListPrint(endpoint);
        return endpoint;

    }

    //Down
    private static void findUpPoint(int left, int right, ArrayList<Point> points, ArrayList<Point> endpoint) {
        int distance = Integer.MIN_VALUE;
        int biggest = 0;
        Point left_point = points.get(left);
        Point right_point = points.get(right);
        for (int i = left; i <= right; i++) {
            Point temp = points.get(i);
            int temp_distance = get_distance(left_point, right_point, temp);
            if (get_direction(left_point, right_point, temp) < 0) { 
                // ????Down????æ³?æ·»å??temp_directionçº???
                if (temp_distance >= distance) {
                    distance = temp_distance;
                    biggest = i;
                }
            }
        }
        if (distance > 0) {
            endpoint.add(points.get(biggest));
            findUpPoint(biggest, right, points, endpoint);
            findUpPoint(left, biggest, points, endpoint);
        } 
    }

    //Up
    private static void findDownPoint(int left, int right, ArrayList<Point> points, ArrayList<Point> endpoint) {
        int distance = Integer.MAX_VALUE;
        int biggest = 0;
        int direction = 0;
        Point left_point = points.get(left);
        Point right_point = points.get(right);
        for (int i = left; i <= right; i++) { //
            Point temp = points.get(i);
            int temp_direction = get_direction(left_point, right_point, temp);
            int temp_distance = get_distance(left_point, right_point, temp); //
            if (temp_direction > 0) { 
                distance = temp_direction;//Add a direction constraint to get_distance ()
                if (temp_distance <= distance) {
                    distance = temp_distance;
                    biggest = i;
                }
            }
        }
        if (direction > 0 || distance < 0) { //Add a direction constraint to get_distance ()
            endpoint.add(points.get(biggest));
            findDownPoint(left, biggest, points, endpoint);
            findDownPoint(biggest, right, points, endpoint);
        } 
    }

    // sort with angle
    public static double getAngle(Point a, Point center) {
        double angle = Math.atan2(a.x - center.x, a.y - center.y); // exchange x & y
        angle = Math.toDegrees(angle);
        /*
         * if (angle < 0) angle = angle + 360;
         */
        return angle;
    }

    //point to line distance
    private static int get_distance(Point left_point, Point right_point, Point temp) {
        return (left_point.x * right_point.y + temp.x * left_point.y + right_point.x * temp.y - temp.x * right_point.y
                - right_point.x * left_point.y + left_point.x * temp.y);
    }

    // point is Up or down
    private static int get_direction(Point left_point, Point right_point, Point temp) {
        int ret = (temp.x - left_point.x) * (right_point.y - left_point.y)
                - ((right_point.x - left_point.x) * (temp.y - left_point.y));
        return ret;// add =
    }

    private static void ArrayListPrint(ArrayList<Point> point) {
        for (int i = 0; i < point.size(); i++) {
            System.out.print("( " + point.get(i).x + "," + point.get(i).y + " ) ");
        }
        System.out.println();
    }

}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

}