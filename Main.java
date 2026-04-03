public class Main {
    public static void main(String[] args) {
        int[][] x = {{1,0,0,1},{0,1,1,0}};
        boolean ok = true;

        int nRobos = 0;
        for (int v : x[0]) if (v == 1) nRobos++;

        outer:
        for (int i = 0; i < x.length; i++) {
            int count = 0;
            for (int v : x[i]) if (v == 1) count++;

            if (count != nRobos) { ok = false; break; }
            if (i == 0) continue;

            int[] prev = new int[nRobos];
            int[] curr = new int[nRobos];
            int pi = 0, ci = 0;

            for (int j = 0; j < x[i].length; j++) {
                if (x[i-1][j] == 1) prev[pi++] = j;
                if (x[i][j]   == 1) curr[ci++] = j;
            }
            for (int h = 0; h < ci; h++) {
                if (Math.abs(prev[h] - curr[h]) > 1) {
                    ok = false;
                    break outer;
                }
            }
        }
        System.out.println(ok);
    }
}