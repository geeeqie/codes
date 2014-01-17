import java.util.Arrays;


public class Fast {
    private static int n;
    private static Point[] points;
    private static SET<Point> set = new SET<Point>();

    private static boolean isdup(Point[] a) {
        boolean ret = true;

        for (int i = 0; i < a.length; i++) {
            if (!set.contains(a[i])) {
                ret = false;
                set.add(a[i]);
            }
        }
        return ret;
    }

    private static void output(Point[] a, int p, int start, int end) {
        Point[] b = new Point[end-start+2];
        b[0] = a[p];

        for (int i = start, j = 1; i <= end; i++, j++) {
            b[j] = a[i];
        }

        if (isdup(b)) return;

        Arrays.sort(b);

        b[0].drawTo(b[b.length-1]);

        for (int i = 0; i < b.length; i++) {
            if (i < b.length-1) {
                StdOut.printf("%s -> ", b[i].toString());
            } else {
                StdOut.println(b[i].toString());
            }
        }
    }

    private static void fast() {

        for (int i = 0; i < n; i++) {
            Point[] a = points.clone();
            Arrays.sort(a, i+1, n, a[i].SLOPE_ORDER);

            for (int j = i+1, count = 1; j < n-1; j++) {
                if (a[i].slopeTo(a[j]) == a[i].slopeTo(a[j+1])) {
                    count++;

                    if (j == n-2 && count >= 3) {
                        output(a, i, j-count+2, j+1);
                    }
                } else {
                    if (count >= 3) {
                        output(a, i, j-count+1, j);
                    }
                    count = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        StdDraw.show(0);

        In in = new In(args[0]);
        n = in.readInt();
        points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
            points[i].draw();
        }
        fast();
        StdDraw.show(0);
    }
}
