public class Brute {
    private static int n;
    private static Point[] chosenPoints;
    private static Point[] points;

    private static boolean check() {
        for (int i = 0; i < 2; i++) {
            double slope1 = chosenPoints[i].slopeTo(chosenPoints[i+1]);
            double slope2 = chosenPoints[i+1].slopeTo(chosenPoints[i+2]);
            if (slope1 != slope2) {
                return false;
            }
        }
        return true;
    }
    private static void bruteforce() {
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n - 2; j++) {
                for (int k = j+1; k < n - 1; k++) {
                    for (int l = k+1; l < n; l++) {
                        chosenPoints[0] = points[i];
                        chosenPoints[1] = points[j];
                        chosenPoints[2] = points[k];
                        chosenPoints[3] = points[l];
                        Quick3way.sort(chosenPoints);
                        if (check()) {
                            for (int a = 0; a < 4; a++) {
                                if (a < 3) {
                                    StdOut.printf("%s -> ", chosenPoints[a].toString());
                                } else {
                                    StdOut.printf("%s\n", chosenPoints[a].toString());
                                }
                            }
                            chosenPoints[0].drawTo(chosenPoints[3]);
                        }

                    }
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
        chosenPoints = new Point[4];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
            points[i].draw();
        }
        bruteforce();
        StdDraw.show(0);
    }
}
