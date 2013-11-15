#include <iostream>
#include <string>

template <typename T,typename S>
struct bar;

template <typename T>
struct bar<T,std::string> {
  static std::string to_xstring(T num) {
    return std::to_string(num);
  }
};

template <typename T>
struct bar<T,std::wstring> {
  static std::wstring to_xstring(T num) {
    return std::to_wstring(num);
  }
};

template <typename C>
std::basic_string<C> space();

template <>
std::basic_string<char> space<char>() { return std::basic_string<char>(" ");}

template <>
std::basic_string<wchar_t> space<wchar_t>() { return std::basic_string<wchar_t>(L" ");}

template <typename T,typename C>
class foo {
    std::basic_ostream<C> &mOutStream;
    T mX;
    std::basic_string<C> mString;
  public:
    foo(std::basic_ostream<C> &os,T x,std::basic_string<C> intro):mOutStream(os),mX(x),mString(intro){}
    void report(T const &y) {
       mX += mX * y + 1;
       std::basic_string<C> asstring = bar<T,std::basic_string<C> >::to_xstring(mX);
       mString = mString + space<C>() + asstring;
       mOutStream << mString << std::endl;
    }
};

int main(int argc,char **argv) {
  foo<int,char> r1(std::cout,7,"intstuff:");
  r1.report(1);
  r1.report(3);
  r1.report(5);
  foo<float,wchar_t> r2(std::wcout,2.11,L"floatstuff");
  r2.report(1.2);
  r2.report(0.18);
  r2.report(3.1415926);
}
