Why std::to string is anoying, cumbersome and incomplete.
=========================================================

This directory contains two examples of usage of number to string conversion from a template function.
One using boost::lexical\_cast and one using std::to\_string and std::to\_wstring. 

The anoying thing about std::to\_string is that it:

1) Requires (partial) template specialisation.
2) Requires the use of a class template rather than a function template (as a result of needing partial specialisation.

These examples were made for a discussion on G+ [here](https://plus.google.com/107985477330768591190/posts/ERm34FV2eL7)
