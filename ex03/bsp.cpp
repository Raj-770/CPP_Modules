#include "Point.cpp"

static Fixed triangleArea(const Point& a, const Point& b, const Point& c) {
	// Triangle area calculation: 0.5 * abs(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))
	return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())).toFloat() / 2.0f;
}

bool bsp(Point const a , Point const b, Point const c, Point const point) {
	Fixed totalArea = triangleArea(a, b, c);
	if (totalArea == 0)
		return (false);

	Fixed area1 = triangleArea(point, b, c);
	Fixed area2 = triangleArea(a, point, c);
	Fixed area3 = triangleArea(a, b, point);

	return (area1 > 0 && area2 > 0 && area3 > 0 && (area1 + area2 + area3 == totalArea));
}