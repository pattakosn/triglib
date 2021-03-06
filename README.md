# triglib
C double precision trigonometry functions originally for Tandy Color Computer (CoCo) OS9.

Written by Al Buist, who passed away in 1985. License is Public Domain. In the 90's I used these routines while implementing a floating point emulator. This code is in K&R C, so some changes would need to be made for use with a modern C compiler. Also, if you use this for anything real, I would double check the constants against the magazine listing. I found this code on an FTP site around 15 years ago, but it's disappeared. I have no idea if it came from a digital archive, or if someone typed it in by hand.

Originally published in Rainbow Magazine, April 1986, page 238:

https://archive.org/details/rainbowmagazine-1986-04/page/n239/mode/2up

Note: The CoCo OS9 double format is different from IEEE doubles. The LSB of the low byte (byte offset 0) contains the sign bit, and the highest byte (offset 7) contains the exponent. The rest is the mantissa:

https://colorcomputerarchive.com/repo/Documents/Manuals/Programming/C%20Compiler%20User's%20Guide%20(nitros9).pdf

Due these differences, the original code won't work as expected on modern machines. Ironically, the old CoCo had more precision in its doubles!
