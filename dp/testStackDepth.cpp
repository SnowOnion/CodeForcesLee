/**
# Runtime:
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=d:/software/work/mingw/bin/../libexec/gcc/mingw32/4.8.1/lto-
wrapper.exe
Target: mingw32
Configured with: ../gcc-4.8.1/configure --prefix=/mingw --host=mingw32 --build=m
ingw32 --without-pic --enable-shared --enable-static --with-gnu-ld --enable-lto
--enable-libssp --disable-multilib --enable-languages=c,c++,fortran,objc,obj-c++
,ada --disable-sjlj-exceptions --with-dwarf2 --disable-win32-registry --enable-l
ibstdcxx-debug --enable-version-specific-runtime-libs --with-gmp=/usr/src/pkg/gm
p-5.1.2-1-mingw32-src/bld --with-mpc=/usr/src/pkg/mpc-1.0.1-1-mingw32-src/bld --
with-mpfr= --with-system-zlib --with-gnu-as --enable-decimal-float=yes --enable-
libgomp --enable-threads --with-libiconv-prefix=/mingw32 --with-libintl-prefix=/
mingw --disable-bootstrap LDFLAGS=-s CFLAGS=-D_USE_32BIT_TIME_T
Thread model: win32
gcc version 4.8.1 (GCC)

# Result:
0
1
<...>
65088
<crash like a normal windows program do> // my English grammar...
*/

#include<cstdio>

void f(int n){
	printf("%d\n", n);
	f(n+1);
}

int main(){
	f(0);
	return 0;
}