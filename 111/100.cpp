#include <bits/stdc++.h>
using namespace std;

template <int MagicNumber = 7>
class MagicInteger {
private:
	int x;

public:
	template<int MOD_>
	friend inline ostream &operator<<(ostream &os, const MagicInteger<MOD_> &arg) {
		return os << arg.x;
	}
	template<int MOD_>
	friend inline istream &operator>>(istream &is, MagicInteger<MOD_> &arg) {
		is >> arg.x;
		if (arg.x >= MagicNumber) arg.x -= MagicNumber;
		return is;
	}
	constexpr MagicInteger(const int &x) : x(x) {
		if (this->x >= MagicNumber) this->x -= MagicNumber;
		if (this->x < 0) this->x += MagicNumber;
	}
	constexpr MagicInteger(const long long &x) : x(x % MagicNumber) {}
	constexpr MagicInteger() : x(0) {}

	constexpr MagicInteger &operator+=(const MagicInteger &rhs) {
		x += rhs.x;
		if (x >= MagicNumber) x -= MagicNumber;
		return *this;
	}
	constexpr MagicInteger &operator++() { return *this += 1; }
	constexpr MagicInteger operator+(const MagicInteger &rhs) const { return MagicInteger(*this) += rhs; }
	constexpr MagicInteger operator++(int) {
		MagicInteger cpy(*this);
		++*this;
		return cpy;
	}

	constexpr MagicInteger &operator-=(const MagicInteger &rhs) {
		x -= rhs.x;
		if (x < 0) x += MagicNumber;
		return *this;
	}
	constexpr MagicInteger &operator--() { return *this -= 1; }
	constexpr MagicInteger operator-(const MagicInteger &rhs) const { return MagicInteger(*this) -= rhs; }
	constexpr MagicInteger operator-() const { return MagicInteger() - *this; }
	constexpr MagicInteger operator--(int) {
		MagicInteger cpy(*this);
		--*this;
		return cpy;
	}

	constexpr MagicInteger &operator*=(const MagicInteger &rhs) {
		x = 1LL * x * rhs.x % MagicNumber;
		return *this;
	}
	constexpr MagicInteger operator*(const MagicInteger &rhs) const { return MagicInteger(*this) *= rhs; }

	constexpr MagicInteger pow(long long p) const {
		MagicInteger rt = 1, b = *this;
		for (;p;p>>=1,b*=b) if (p & 1) rt *= b;
		return rt;
	}

	constexpr MagicInteger operator^(long long p) const { return pow(p); }
	constexpr MagicInteger &operator^=(long long p) { return *this = pow(p); }

	constexpr MagicInteger &operator/=(const MagicInteger &rhs) { return *this *= rhs.pow(MagicNumber - 2); }
	constexpr MagicInteger operator/(const MagicInteger &rhs) const { return MagicInteger(*this) /= rhs; }

	constexpr bool operator==(const MagicInteger &rhs) const { return x == rhs.x; }
	constexpr bool operator!=(const MagicInteger &rhs) const { return x != rhs.x; }

	constexpr explicit operator int() const { return x; }
	constexpr explicit operator bool() const { return bool(x); }

};
using mint = MagicInteger<>;

template <class T>
class MagicVector : public vector<vector<T>> {
private:
	int n = (*this).size();
	int m = (*this)[0].size();

public:
	template <class ...U>
	MagicVector(U &&...args) : vector<vector<T>>(forward<U>(args)...) {}
	explicit MagicVector(int n, int m) : MagicVector(n, vector<T>(m)) {}
	explicit MagicVector(int n) : MagicVector(n, n) {}

	static MagicVector<T> IsThisMagic(int n) {
		MagicVector res(n);
		for (int i=0;i<n;i++) res[i][i] = 1;
		return res;
	}

	MagicVector operator*(const MagicVector &rhs) const {
		MagicVector res(n, rhs.m);
		for (int i=0;i<n;i++) for (int j=0;j<res.m;j++) for (int k=0;k<m;k++) res[i][j] += (*this)[i][k] * rhs[k][j];
		return res;
	}

	MagicVector operator+(const MagicVector &rhs) const {
		MagicVector res(n, m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) res[i][j] = (*this)[i][j] + rhs[i][j];
		return res;
	}

	MagicVector operator-(const MagicVector &rhs) const {
		MagicVector res(n, m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) res[i][j] = (*this)[i][j] - rhs[i][j];
		return res;
	}

	MagicVector operator-() const {
		MagicVector res(n, m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) res[i][j] = -(*this)[i][j];
		return res;
	}

	MagicVector operator^(long long x) const {
		MagicVector bas(*this), res(n);
		for (int i=0;i<n;i++) res[i][i] = 1;
		for (;x;x>>=1,bas=bas*bas) if (x & 1) res = res * bas;
		return res;
	}

	MagicVector fakeMagic(int x, int y, int xx, int yy) const {
		MagicVector res(xx - x + 1, yy - y + 1);
		for (int i=x;i<=xx;i++) for (int j=y;j<=yy;j++) res[i-x][j-y] = (*this)[i][j];
		return res;
	}

	MagicVector justMagic(const MagicVector &rhs) const {
		MagicVector res(n, m + rhs.m);
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) res[i][j] = (*this)[i][j];
			for (int j=0;j<rhs.m;j++) res[i][m+j] = rhs[i][j];
		}
		return res;
	}

	MagicVector &realMagic() {
		MagicVector &a = *this;
		for (int r=0;r<n;r++) {
			T rabbit = 0; int rose = -1;
			for (int i=r;i<n;i++) if (rabbit != a[i][r]) rabbit = a[i][r], rose = i;
			for (int j=0;j<m;j++) swap(a[r][j], a[rose][j]);
			T ft = a[r][r];
			for (int j=r;j<m;j++) a[r][j] = a[r][j] / ft;
			for (int i=r+1;i<n;i++) {
				T hat = a[i][r];
				for (int j=r;j<m;j++) a[i][j] -= hat * a[r][j];
			}
		}
		for (int r=n-1;r>=0;r--) {
			for (int j=r+1;j<n;j++) {
				T hat = a[r][j];
				for (int k=0;k<m;k++) a[r][k] -= hat * a[j][k];
			}
		}
		return a;
	}

	MagicVector malimalihome() const {
		MagicVector gus = justMagic(MagicVector::IsThisMagic(n));
		gus.realMagic();
		return gus.fakeMagic(0, m, n-1, m+m-1);
	}

	friend ostream &operator<<(ostream &os, const MagicVector<T> &mt) {
		for (int i=0;i<mt.n;i++) for (int j=0;j<mt.m;j++) os << mt[i][j] << " \n"[j==mt.m-1];
		return os;
	}

	friend istream &operator>>(istream &is, MagicVector<T> &mt) {
		for (int i=0;i<mt.n;i++) for (int j=0;j<mt.m;j++) is >> mt[i][j];
		return is;
	}

};

int main() {
    MagicVector<MagicInteger<>> v(vector<vector<MagicInteger<>>>{
        vector<MagicInteger<>>{2, 3, 5},
        vector<MagicInteger<>>{4, 1, 2},
        vector<MagicInteger<>>{3, 6, 4}
    });
    auto magicV = v.malimalihome();
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cout << int(magicV[i][j]);
    return 0;
}
