Requirement
===========
In order to run succesffully under MingGW64, the following macro must be defined for GCC to correctly link to `vsnprintf()` that returns the length of buffer needed to write when it fails due to buffer being too small.

Otherwise GCC will use `vsnprintf()` provided by Windows, which will return -1 if it encountered an error [1]. My implementation that uses the function will fail, because it expected the correct length required.

Reference
=========
[1] https://sourceforge.net/p/mingw-w64/mailman/message/31241434/


