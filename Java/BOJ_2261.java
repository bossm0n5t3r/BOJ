/*
The nearest two points

https://www.acmicpc.net/problem/2261

https://courses.csail.mit.edu/6.006/spring11/lectures/lec24.pdf
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

class BOJ_2261 {
    private static List<Point> data = new ArrayList<Point>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] split = br.readLine().split(" ");
            data.add(new Point(Double.parseDouble(split[0]), Double.parseDouble(split[1])));
        }
        Collections.sort(data);
        int result = shortestDistance(0, data.size() - 1);
        if (result == Integer.MAX_VALUE) {
            result = 0;
        }
        System.out.println(result);
    }

    public static int shortestDistance(int start, int end) {
        // 분할로 접근하기 때문에 start, end가 같을 수 있음
        // 이런 경우 Integer.MAX_VALUE 를 return
        if (start - end == 0) {
            return Integer.MAX_VALUE;
        }
        // 점이 두 개
        if (start - end == 1) {
            return distance(data.get(start), data.get(end));
        }
        // 반씩 분할해서 접근
        int middle = (start + end) / 2;
        int min = Math.min(shortestDistance(start, middle), shortestDistance(middle + 1, end));
        // 중앙값
        double centerLine = (data.get(middle).x + data.get(middle + 1).x) / 2;
        // 거리가 min 보다 짧은 Point 들을 후보군으로 설정
        List<Point> candidate = new ArrayList<Point>();
        for (int i = middle + 1; i <= end; i++) {
            if ((centerLine - data.get(i).x) * (centerLine - data.get(i).x) >= min) {
                break;
            }
            candidate.add(data.get(i));
        }
        for (int i = middle; i >= start; i--) {
            if ((centerLine - data.get(i).x) * (centerLine - data.get(i).x) >= min) {
                break;
            }
            candidate.add(data.get(i));
        }
        // 후보군이 없으면 바로 min 을 return
        if (candidate.size() == 0) {
            return min;
        }
        // y 축 기준으로 오름차순 정렬
        Collections.sort(candidate, (p1, p2) -> (p1.y < p2.y) ? -1 : (p1.y == p2.y) ? 0 : 1);
        // min 보다 더 짧은 거리가 있으면 그 거리로 min 설정
        for (int i = 0; i < candidate.size(); i++) {
            Point p1 = candidate.get(i);
            for (int j = i + 1; j < candidate.size(); j++) {
                Point p2 = candidate.get(j);
                if ((p2.y - p1.y) * (p2.y - p1.y) >= min) {
                    break;
                }
                min = Math.min(min, distance(p1, p2));
            }
        }
        return min;
    }

    public static class Point implements Comparable<Point> {
        double x;
        double y;
    
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point p) {
            if (this.x < p.x) {
                return -1;
            } else if (this.x == p.x) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    public static int distance(Point p1, Point p2) {
        return (int) ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}
