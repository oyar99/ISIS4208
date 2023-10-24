### Tree Edit Distance

Given two node-labeled rooted trees T and T ′ each of size at most n, what is
the minimum number of elementary operations needed to transform T into T?.

This program implements different solutions for the above problem in C++.

Please see the next guides on how to set up GCC on different platforms.

    - Windows: https://code.visualstudio.com/docs/cpp/config-mingw.
    - Linux: https://code.visualstudio.com/docs/cpp/config-linux
    - Mac: https://code.visualstudio.com/docs/cpp/config-clang-mac

## How to compile this program?

```
g++ -o ted.exe -I ./src/models -I ./src/procedures *.cpp src/models/*.cpp src/procedures/*.cpp
```

## How to run this program?

```
ted.exe < data/sample_5_8.in > output/sample_5_8.out
```