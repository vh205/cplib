inline namespace geometry {
	template<typename T>
	struct point {
		T x, y;

		point() : x(0), y(0) {}

		point(T x0, T y0) : x(x0), y(y0) {}

		point& operator += (const point& p) {
			x += p.x;
			y += p.y;
			return *this;
		}

		point& operator -= (const point& p) {
			x -= p.x;
			y -= p.y;
			return *this;
		}

		point& operator *= (const point& p) {
			x *= p.x;
			y *= p.y;
			return *this;
		}

		point& operator /= (const point& p) {
			x /= p.x;
			y /= p.y;
			return *this;

		}

		point operator + (const point& p) const {
			return point(*this) += p;
		}

		point operator - (const point& p) const {
			return point(*this) -= p;
		}

		point operator * (const point& p) const {
			return point(*this) *= p;
		}

		point operator / (const point& p) const {
			return point(*this) /= p;

		}
	};

	template<typename T>
	point<T> operator + (T a, point<T> p) { return p + a; }

	template<typename T>
	point<T> operator * (T a, point<T> p) { return p * a; }

	template<typename T>
	T dot(point<T> p, point<T> q) { return p.x * q.x + p.y * q.y; }

	template<typename T>
	T norm(point<T> p) { return dot(p, p); }

	template<typename T>
	double abs(point<T> p) { return sqrt(norm(p)); }

	template<typename T>
	double proj(point<T> p, point<T> q) { return dot(p, q) / abs(q); }

	template<typename T>
	double angle(point<T> p, point<T> q) { return acos(dot(p, q) / abs(p) / abs(q)); }

	template<typename T>
	T cross(point<T> p, point<T> q) { return p.x * q.y - p.y * q.x; }

	template<typename T>
	point<T> intersect(point<T> a1, point<T> d1, point<T> a2, point<T> d2) {
		return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d2;
	}

	template<typename T>
	bool operator == (const point<T> &p, const point<T> &q) {
		return p.x == q.x && p.y == q.y;
	}

	template<typename T>
	bool operator != (const point<T> &p, const point<T> &q) {
        return !(p == q);
	}

	template<typename T>
	istream& operator >> (istream &is, point<T> &p) {
		return is >> p.x >> p.y;
	}

	template<typename T>
	ostream& operator << (ostream &os, const point<T> &p) {
		return os << '(' << p.x << ',' << p.y << ')';
	}
}
