Wagner-Fischer
===================

C implementation of a basic Wagner Fischer algorithm (metric) for calculating distances of string similarity.

This particular implementation is derived from the pseudo-code presented in

"Data Structures and Algorithms in C++", Adam Drozdek, Thomson Learning, 2005.

In particular I've optimized for space constraints as the pseudo-code offered a O( |string1| x |string2| )
computational complexity in space requirements, while I've reduced it to O( |string1| ).  It can further be
optimized I'm sure, but for my purposes that much is overkill (diminishing returns).

It was compiled under the following command:

gcc -std=gnu99 main.c -o &lt;NAME&gt;

with &lt;NAME&gt; being the obvious intended variable name of the binary.

If you find it useful or have suggestions, let me know. Thanks.
