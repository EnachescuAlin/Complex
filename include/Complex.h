#ifndef PHILIB_COMPLEX
#define PHILIB_COMPLEX

template<typename T>
class Complex
{
    public:
        virtual~ Complex() {};
        Complex() {};
        Complex(const T& real, const T& imaginary)
        {
            re = real;
            im = imaginary;
        }

        const T& GetReal(void) const
        {
            return re;
        }

        const T& GetImaginary(void) const
        {
            return im;
        }

        void SetReal(const T& real)
        {
            re = real;
        }

        void SetImaginary(const T& imaginary)
        {
            im = imaginary;
        }

        template<typename T2>
        inline void operator=(const Complex<T2>& c)
        {
            re = c.GetReal();
            im = c.GetImaginary();
        }

        inline T abs(void) const
        {
            return (sqrt(re * re + im * im));
        }

    private:
        T im, re;
};





template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const Complex<T>& c)
{
    stream << c.GetReal();
    if (c.GetImaginary() >= 0)
        stream << '+';
    stream << c.GetImaginary() << 'i';

    return stream;
}

template<typename T>
inline std::istream& operator>>(std::istream& stream, Complex<T>& c)
{
    T re, im;
    char sign, i;
    stream >> re >> sign >> im >> i;

    if ((sign != '-' && sign != '+') || i != 'i')
    {
        c.SetReal(0);
        c.SetImaginary(0);

        return stream;
    }

    c.SetReal(re);
    if (sign == '-')
        c.SetImaginary(-im);
    else
        c.SetImaginary(im);

    return stream;
}





template<typename T1, typename T2>
inline auto operator+(const Complex<T1>& c1, const Complex<T2>& c2)
{
    auto r = c1.GetReal() + c2.GetReal();
    auto i = c1.GetImaginary() + c2.GetImaginary();
    Complex<decltype(r)> c(r, i);

    return c;
}

template<typename T1, typename T2>
inline auto operator-(const Complex<T1>& c1, const Complex<T2>& c2)
{
    auto r = c1.GetReal() + c2.GetReal();
    auto i = c1.GetImaginary() + c2.GetImaginary();
    Complex<decltype(r)> c(r, i);

    return c;
}

template<typename T1, typename T2>
inline auto operator*(const Complex<T1>& c1, const Complex<T2>& c2)
{
    auto r = c1.GetReal() * c2.GetReal() - c1.GetImaginary() * c2.GetImaginary();
    auto i = c1.GetReal() * c2.GetImaginary() + c1.GetImaginary() * c2.GetReal();
    Complex<decltype(r)> c(r, i);

    return c;
}

template<typename T1, typename T2>
inline auto operator/(const Complex<T1>& c1, const Complex<T2>& c2)
{
    Complex<T2> conjugate = !c2;
    auto x = c1 * conjugate;
    auto y = c2 * conjugate;
    
    return (x / y.GetReal());
}





template<typename T1, typename T2>
inline void operator+=(Complex<T1>& c1, const Complex<T2>& c2)
{
    c1.SetReal(c1.GetReal() + c2.GetReal());
    c1.SetImaginary(c1.GetImaginary() + c2.GetImaginary());
}

template<typename T1, typename T2>
inline void operator-=(Complex<T1>& c1, const Complex<T2>& c2)
{
    c1.SetReal(c1.GetReal() - c2.GetReal());
    c1.SetImaginary(c1.GetImaginary() - c2.GetImaginary());
}

template<typename T1, typename T2>
inline void operator*=(Complex<T1>& c1, const Complex<T2>& c2)
{
    c1 = c1 * c2;
}

template<typename T1, typename T2>
inline void operator/=(Complex<T1>& c1, const Complex<T2>& c2)
{
    c1 = c1 / c2;
}





template<typename T1, typename T2>
inline auto operator+(const Complex<T1>& c, const T2& n)
{
    auto r = c.GetReal() + n;
    Complex<decltype(r)> res(r, c.GetImaginary());

    return res;
}

template<typename T1, typename T2>
inline auto operator-(const Complex<T1>& c, const T2& n)
{
    auto r = c.GetReal() - n;
    Complex<decltype(r)> res(r, c.GetImaginary());

    return res;
}

template<typename T1, typename T2>
inline auto operator*(const Complex<T1>& c, const T2& n)
{
    auto r = c.GetReal() * n;
    auto i = c.GetImaginary() * n;
    Complex<decltype(r)> res(r, i);

    return res;
}

template<typename T1, typename T2>
inline auto operator/(const Complex<T1>& c, const T2& n)
{
    auto r = c.GetReal() / n;
    auto i = c.GetImaginary() / n;
    Complex<decltype(r)> res(r, i);

    return res;
}

template<typename T1, typename T2>
inline void operator+=(Complex<T1>& c, const T2& n)
{
    c = c + n;
}

template<typename T1, typename T2>
inline void operator-=(Complex<T1>& c, const T2& n)
{
    c = c - n;
}

template<typename T1, typename T2>
inline void operator*=(Complex<T1>& c, const T2& n)
{
    c = c * n;
}

template<typename T1, typename T2>
inline void operator/=(Complex<T1>& c, const T2& n)
{
    c = c / n;
}





template<typename T1, typename T2>
inline auto operator+(const T1& n, const Complex<T2>& c)
{
    auto r = c.GetReal() + n;
    Complex<decltype(r)> res(r, c.GetImaginary());

    return res;
}

template<typename T1, typename T2>
inline auto operator-(const T1& n, const Complex<T2>& c)
{
    auto r = c.GetReal() - n;
    Complex<decltype(r)> res(r, c.GetImaginary());

    return res;
}

template<typename T1, typename T2>
inline auto operator*(const T1& n, const Complex<T2>& c)
{
    auto r = c.GetReal() * n;
    auto i = c.GetImaginary() * n;
    Complex<decltype(r)> res(r, i);

    return res;
}

template<typename T1, typename T2>
inline auto operator/(const T1& n, const Complex<T2>& c)
{
    auto r = c.GetReal() / n;
    auto i = c.GetImaginary() / n;
    Complex<decltype(r)> res(r, i);

    return res;
}

template<typename T>
inline Complex<T> operator!(const Complex<T>& c)
{
    Complex<T> res = c;
    res.SetImaginary(-c.GetImaginary());

    return res;
}





template<typename T1, typename T2>
inline bool operator==(const Complex<T1>& c1, const Complex<T2>& c2)
{
    return (c1.GetReal() == c2.GetReal() && c1.GetImaginary() == c1.GetImaginary());
}

template<typename T1, typename T2>
inline bool operator!=(const Complex<T1>& c1, const Complex<T2>& c2)
{
    return (!(c1 == c2));
}





template<typename T>
inline Complex<T>& operator++(Complex<T>& c)
{
    c.SetReal(c.GetReal() + 1);
    c.SetImaginary(c.GetImaginary() + 1);
    return c;
}

template<typename T>
inline Complex<T>& operator--(Complex<T>& c)
{
    c.SetReal(c.GetReal() - 1);
    c.SetImaginary(c.GetImaginary() - 1);
}

template<typename T>
inline Complex<T> operator++(Complex<T>& c, int)
{
    Complex<T> tmp(c);
    ++c;
    return tmp;
}

template<typename T>
inline Complex<T> operator--(Complex<T>& c, int)
{
    Complex<T> tmp(c);
    --c;
    return tmp;
}

template<typename T>
inline Complex<T> operator-(const Complex<T>& c)
{
    Complex<T> res;
    res.SetReal(-c.GetReal());
    res.SetImaginary(-c.GetImaginary());

    return res;
}

template<typename T>
inline Complex<T> operator+(const Complex<T>& c)
{
    Complex<T> res(c);

    return res;
}





#endif

