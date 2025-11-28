#include <iostream>
#include <cmath>
#include <optional>

class Vector3D {
public:
    double X, Y, Z;
    Vector3D() : X(0), Y(0), Z(0) {}
    Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

    Vector3D operator-(const Vector3D& B) const { return {X - B.X, Y - B.Y, Z - B.Z}; }

    Vector3D operator+(const Vector3D& B) const { return {X + B.X, Y + B.Y, Z + B.Z}; }

    Vector3D operator*(double scalar) const { return {X * scalar, Y * scalar, Z * scalar}; }

    Vector3D cross(const Vector3D& B) const {
        return {Y * B.Z - Z * B.Y, Z * B.X - X * B.Z, X * B.Y - Y * B.X};
    }

    double length() const {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }
};

class Segment3D {
public:
    Vector3D start, end;
    Segment3D() = default;
    Segment3D(Vector3D s, Vector3D e) : start(s), end(e) {}

    Vector3D direction() const { return end - start; }
};

bool solve2x2(double a11, double a12, double a21, double a22,
              double b1, double b2, double& t, double& r) {
    double det = a11 * a22 - a21 * a12;
    if (std::fabs(det) < 1e-10) return false;
    t = (b1 * a22 - b2 * a12) / det;
    r = (a11 * b2 - a21 * b1) / det;
    return true;
}

std::optional<Vector3D> Intersect(const Segment3D& seg1, const Segment3D& seg2) {
    const double EPS = 1e-6;
    Vector3D A1 = seg1.start, A2 = seg2.start;
    Vector3D D1 = seg1.direction(), D2 = seg2.direction();
    Vector3D P = A2 - A1;

    if (D1.cross(D2).length() < EPS) {
        return std::nullopt;
    }

    double t, r;

    // 1. X,Y → Z
    if (std::fabs(D1.X*D2.Y - D1.Y*D2.X) >= 1e-10) {
        if (solve2x2(D1.X, -D2.X, D1.Y, -D2.Y, P.X, P.Y, t, r)) {
            if (std::fabs(D1.Z*t - D2.Z*r - P.Z) < EPS && 
                t >= -EPS && t <= 1+EPS && r >= -EPS && r <= 1+EPS) {
                return A1 + D1*t;
            }
        }
    }

    // 2. X,Z → Y
    if (std::fabs(D1.X*D2.Z - D1.Z*D2.X) >= 1e-10) {
        if (solve2x2(D1.X, -D2.X, D1.Z, -D2.Z, P.X, P.Z, t, r)) {
            if (std::fabs(D1.Y*t - D2.Y*r - P.Y) < EPS && 
                t >= -EPS && t <= 1+EPS && r >= -EPS && r <= 1+EPS) {
                return A1 + D1*t;
            }
        }
    }

    // 3. Y,Z → X
    if (std::fabs(D1.Y*D2.Z - D1.Z*D2.Y) >= 1e-10) {
        if (solve2x2(D1.Y, -D2.Y, D1.Z, -D2.Z, P.Y, P.Z, t, r)) {
            if (std::fabs(D1.X*t - D2.X*r - P.X) < EPS && 
                t >= -EPS && t <= 1+EPS && r >= -EPS && r <= 1+EPS) {
                return A1 + D1*t;
            }
        }
    }

    return std::nullopt;
}

int main() {
    Segment3D seg1(Vector3D(0,0,0), Vector3D(2,2,2));
    Segment3D seg2(Vector3D(0,2,0), Vector3D(2,0,2));
    
    auto res = Intersect(seg1, seg2);
    if (res) {
        std::cout << "Пересечение: (" << res->X << "," << res->Y << "," << res->Z << ")\n";
    } else {
        std::cout << "Пересечения нет\n";
    }
    return 0;
}