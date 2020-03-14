
#include <windows.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
// using namespace ;
struct Point {
    double x;
    double y;
};
inline bool Compx(const Point &p1, const Point &p2) { return p1.x < p2.x; }
/*
        函数：求点p在以p1和p2决定直线的上侧还是下侧
        返回值：上侧：>0    下侧：<0    在直线上：=0
*/
inline double Line(const Point &p1, const Point &p2, const Point &p) {
    return (p1.y - p2.y) * p.x + (p2.x - p1.x) * p.y +
           (p1.x * p2.y - p1.y * p2.x);
}
/*
        函数：求点p到以p1和p2决定直线的距离
*/
double Dist(const Point &p1, const Point &p2, const Point &p) {
    double A = p1.y - p2.y;
    double B = p2.x - p1.x;
    double C = p1.x * p2.y - p1.y * p2.x;
    return abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}
/*
        函数：求解直线p1p2上点集的上包
        参数：v：直线p1p2上的点集 vo：上包点集
*/
void UpHull(const vector<Point> &v, vector<Point> &vo, const Point &p1,
            const Point &p2) {
    if (v.size() == 0) return;
    if (v.size() == 1) {
        vo.push_back(v[0]);
        return;
    }

    double d = 0;
    int k;
    // 求最大距离的点
    for (int i = 0; i < v.size(); ++i) {
        double t = Dist(p1, p2, v[i]);
        if (t > d) {
            d = t;
            k = i;
        }
    }
    // 将最大距离的点加入vo中
    vo.push_back(v[k]);

    vector<Point> vl;
    vector<Point> vr;

    // 分别求p1v[k]和p2v[k]
    // 左侧和右侧
    for (int i = 0; i < v.size(); ++i) {
        if (Line(p1, v[k], v[i]) > 0)
            vl.push_back(v[i]);
        else if (Line(v[k], p2, v[i]) > 0)
            vr.push_back(v[i]);
    }

    UpHull(vl, vo, p1, v[k]);
    UpHull(vr, vo, v[k], p2);
}
/*
        函数：求解直线p1p2下点集的下包
        参数：v：直线p1p2下的点集 vo：下包点集
*/
void DownHull(const vector<Point> &v, vector<Point> &vo, const Point &p1,
              const Point &p2) {
    if (v.size() == 0) return;
    if (v.size() == 1) {
        vo.push_back(v[0]);
        return;
    }

    double d = 0;
    int k;
    for (int i = 0; i < v.size(); ++i) {
        double t = Dist(p1, p2, v[i]);
        if (t > d) {
            d = t;
            k = i;
        }
    }
    vo.push_back(v[k]);
    vector<Point> vl;
    vector<Point> vr;
    for (int i = 0; i < v.size(); ++i) {
        // p1 p2 连线的下侧
        if (Line(p1, v[k], v[i]) < 0)
            vl.push_back(v[i]);
        else if (Line(v[k], p2, v[i]) < 0)
            vr.push_back(v[i]);
    }

    DownHull(vl, vo, p1, v[k]);
    DownHull(vr, vo, v[k], p2);
}
/*
        函数：求解点集v的凸包
*/
void ConvexHull(vector<Point> &v, vector<Point> &vo) {
    sort(v.begin(), v.end(), Compx);  // 从小到大排序
    vo.push_back(v[0]);               // 第一点
    vo.push_back(v[v.size() - 1]);    // 最后一点
    vector<Point> vu;
    vector<Point> vd;
    for (int i = 1; i < v.size() - 1; ++i) {
        if (Line(v[0], v[v.size() - 1], v[i]) >
            0)  // 求点v[i]在以v[0] v[v.size() - 1]组成直线哪侧
            vu.push_back(v[i]);  // 在上侧 v up 插入
        else if (Line(v[0], v[v.size() - 1], v[i]) < 0)
            vd.push_back(v[i]);  // 在下侧 v down 插入
    }
    UpHull(vu, vo, v[0], v[v.size() - 1]);
    DownHull(vd, vo, v[0], v[v.size() - 1]);
}

int main() {
    vector<Point> v;
    ifstream setfs("Point.txt", ifstream::in);
    string line;
    Point p;
    while (getline(setfs, line)) {
        stringstream liness(line);
        liness >> p.x >> p.y;
        v.push_back(p);
    }
    vector<Point> vo;
    ConvexHull(v, vo);
    for (auto p : vo) cout << "<" << p.x << "," << p.y << ">" << endl;
    return 0;
}

