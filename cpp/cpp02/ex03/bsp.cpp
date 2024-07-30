#include "Point.hpp"

static bool valid_triangle(const Point& a, const Point& b, const Point& c);
static float resolve_l(const Point& vec_b, const Point& vec_c, const Point& vec_p);

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Point vec_ab = b - a;
    Point vec_ac = c - a;
    Point vec_ap = point - a;
    /*  Definition of k and l to show vec_pc = k * vec_ab + l * vec_ac.
        If 0 < k + l < 1 && k > 0 && l > 0, the point is inside of the triangle
    */
    float k, l;

    if (valid_triangle(a, b, c) == false)
        return (false);
    if (vec_ab.getx() == Fixed(0.0f)) {
        l = vec_ap.getx().toFloat() / vec_ac.getx().toFloat();
        k = (vec_ap.gety().toFloat() - l * vec_ac.gety().toFloat()) / vec_ab.gety().toFloat();
    }
    else
    {
        l = resolve_l(vec_ab, vec_ac, vec_ap);
        k = (vec_ap.getx().toFloat() - l * vec_ac.getx().toFloat()) / vec_ab.getx().toFloat();
    }
    return (0 < k + l && k + l < 1 && k > 0 && l > 0);
}

static bool valid_triangle(const Point& a, const Point& b, const Point& c) {
    /* same point */
    if (a == b || b == c || c == a)
        return (false);
    /* all points in one line */
    else if ((a.getx() == b.getx() && b.getx() == c.getx()) || (a.gety() == b.gety() && b.gety() == c.gety()))
        return (false);
    return (true);
}

static float resolve_l(const Point& vec_b, const Point& vec_c, const Point& vec_p) {
    float numerator = (vec_b.getx() * vec_p.gety() - vec_p.getx() * vec_b.gety()).toFloat();
    float denominator = (vec_b.getx() * vec_c.gety() - vec_c.getx() * vec_b.gety()).toFloat();
    return (numerator / denominator);
}
