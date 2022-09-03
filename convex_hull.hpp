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

        bool operator < (const point& p) const {
            return tie(x, y) < tie(p.x, p.y);
        }
	};

	template<typename T>
	point<T> operator + (T a, point<T> p) { return p + a; }

	template<typename T>
	point<T> operator * (T a, point<T> p) { return p * a; }

	template<typename T>
	T cross(point<T> p, point<T> q) { return p.x * q.y - p.y * q.x; }
}

const int maxN = 1e5 + 5;
int N;
point<int64_t> A[maxN];

vector<point<int64_t>> convex_hull() {
    vector<point<int64_t>> hull;
    sort(A + 1, A + 1 + N);
    for (int i = 1; i <= N; ++i) {
        while ((int)hull.size() > 1 && cross(hull.back() - hull[(int)hull.size() - 2], A[i] - hull[(int)hull.size() - 2]) <= 0) {
            hull.pop_back();
        }
        hull.emplace_back(A[i]);
    }
    int low_length = (int)hull.size();
    for (int i = N - 1; i > 0; --i) {
        while ((int)hull.size() > low_length && cross(hull.back() - hull[(int)hull.size() - 2], A[i] - hull[(int)hull.size() - 2]) <= 0) {
            hull.pop_back();
        }
        hull.emplace_back(A[i]);
    }
    hull.pop_back();

    return hull;
}
