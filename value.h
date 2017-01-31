#ifndef __TABOO_UNIT__VALUE_H__
#define __TABOO_UNIT__VALUE_H__


#include <iostream>
#include <sstream>
#include <string>


namespace Taboo {

template<class T> inline std::string as_str(T v) {
    std::stringstream buf;
    buf << v;
    return buf.str();
}


template<> inline std::string as_str<bool>(bool v) {
    return { v ? "true" : "false" };
}


template<class T> class Value {
private:
    T value;
    std::string label;
    bool valid;

    Value(T value);

    template<class U> friend Value<U> V(U v);
    template<class U, class V> friend Value<U> operator ==(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator ==(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator ==(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<U> operator !=(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator !=(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator !=(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<U> operator <(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator <(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator <(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<U> operator >(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator >(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator >(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<U> operator <=(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator <=(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator <=(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<U> operator >=(Value<U> x, V y);
    template<class U, class V> friend Value<U> operator >=(V y, Value<U> x);
    template<class U, class V> friend Value<V> operator >=(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<V> operator &&(Value<U> x, Value<V> y);
    template<class U, class V> friend Value<V> operator ||(Value<U> x, Value<V> y);

    template<class U> void rmark(U x, std::string exp, bool mark) {
        valid = valid && mark;
        label += std::string(mark ? "\e[32m " : "\e[41;37m ") + exp + " " + as_str(x) + "\e[0m";
    }

    template<class U> void lmark(U x, std::string exp, bool mark) {
        valid = valid && mark;
        label = std::string(mark ? "\e[32m" : "\e[41;37m") + as_str(x) + " " + exp + " \e[0m" + label;
    }

    template<class U> void lmark(Value<U> x, std::string exp, bool mark) {
        valid = valid && x.valid && mark;
        label = x.label + std::string(mark ? "\e[32m" : "\e[41;37m") + " " + exp + " \e[0m" + label;
    }

public:
    operator bool() const { return valid; }
    operator std::string() const { return label; }
};


template<class T> Value<T>::Value(T value) : value(value) {
    label = "\e[30;47m" + as_str(value) + "\e[0m";

    valid = true;
}


template<class T> Value<T> V(T v) {
    return Value<T>(v);
}


template<class T> std::ostream& operator <<(std::ostream& os, Value<T> v) {
    return os << (std::string)v;
}


template<class T, class U> Value<T> operator ==(Value<T> x, U y) {
    x.rmark(y, "==", x.value == y);
    return x;
}


template<class T, class U> Value<T> operator ==(U y, Value<T> x) {
    x.lmark(y, "==", y == x.value);
    return x;
}


template<class T, class U> Value<U> operator ==(Value<T> y, Value<U> x) {
    x.lmark(y, "==", y.value == x.value);
    return x;
}


template<class T, class U> Value<T> operator !=(Value<T> x, U y) {
    x.rmark(y, "!=", x.value != y);
    return x;
}


template<class T, class U> Value<T> operator !=(U y, Value<T> x) {
    x.lmark(y, "!=", y != x.value);
    return x;
}


template<class T, class U> Value<U> operator !=(Value<T> y, Value<U> x) {
    x.lmark(y, "!=", y.value != x.value);
    return x;
}


template<class T, class U> Value<T> operator <(Value<T> x, U y) {
    x.rmark(y, "<", x.value < y);
    return x;
}


template<class T, class U> Value<T> operator <(U y, Value<T> x) {
    x.lmark(y, "<", y < x.value);
    return x;
}


template<class T, class U> Value<U> operator <(Value<T> y, Value<U> x) {
    x.lmark(y, "<", y.value < x.value);
    return x;
}


template<class T, class U> Value<T> operator >(Value<T> x, U y) {
    x.rmark(y, ">", x.value > y);
    return x;
}


template<class T, class U> Value<T> operator >(U y, Value<T> x) {
    x.lmark(y, ">", y > x.value);
    return x;
}


template<class T, class U> Value<U> operator >(Value<T> y, Value<U> x) {
    x.lmark(y, ">", y.value > x.value);
    return x;
}


template<class T, class U> Value<T> operator <=(Value<T> x, U y) {
    x.rmark(y, "<=", x.value <= y);
    return x;
}


template<class T, class U> Value<T> operator <=(U y, Value<T> x) {
    x.lmark(y, "<=", y <= x.value);
    return x;
}


template<class T, class U> Value<U> operator <=(Value<T> y, Value<U> x) {
    x.lmark(y, "<=", y.value <= x.value);
    return x;
}


template<class T, class U> Value<T> operator >=(Value<T> x, U y) {
    x.rmark(y, ">=", x.value >= y);
    return x;
}


template<class T, class U> Value<T> operator >=(U y, Value<T> x) {
    x.lmark(y, ">=", y >= x.value);
    return x;
}


template<class T, class U> Value<U> operator >=(Value<T> y, Value<U> x) {
    x.lmark(y, ">=", y.value >= x.value);
    return x;
}


template<class T, class U> Value<U> operator &&(Value<T> x, Value<U> y) {
    y.valid = x.valid && y.valid;
    y.label = x.label + std::string(y.valid ? "\e[32m" : "\e[41;37m") + " && \e[0m" + y.label;
    return y;
}


template<class T, class U> Value<U> operator ||(Value<T> x, Value<U> y) {
    y.valid = x.valid || y.valid;
    y.label = x.label + std::string(y.valid ? "\e[32m" : "\e[41;37m") + " || \e[0m" + y.label;
    return y;
}

}

#endif
