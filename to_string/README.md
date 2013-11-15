Why std::to string is anoying and cumbersome.
=============================================

This directory contains two examples of usage of number to string conversion from a template function.
One using boost::lexical\_cast and one using std::to\_string and std::to\_wstring. 

The anoying thing about std::to\_string is that it:

1) Requires (partial) template specialisation.

2) Requires the use of a class template rather than a function template (as a result of needing partial specialisation.

These examples were made for a discussion on G+ [here](https://plus.google.com/107985477330768591190/posts/ERm34FV2eL7)

With boost::lexical\_cast we can simply do:

 __std::basic_string<C> asstring = boost::lexical_cast<std::basic_string<C> >(mX);__

With std::to\_string we must first write template specialisations of a helper class with a static method before we can 
use the (ugly) equivalent:

__std::basic_string<C> asstring = bar<T,std::basic_string<C> >::to_xstring(mX);__
