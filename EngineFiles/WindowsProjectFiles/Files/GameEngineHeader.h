#include<Windows.h>
#include<string>
#include<iostream>
#include<vector>
#include<random>
#include<map>
#include<cstdlib>
#include<Windows.h>
#include<ctime>
#include<cmath>
#include<conio.h>
#include<algorithm>
using namespace std;
constexpr auto ABSOLUTECENTERX = 0;
constexpr auto ABSOLUTECENTERY = 0;
constexpr auto ABSOLUTECENTERZ = 0;

struct veccoordinates {
    double x, y, z;
};

struct squarepoints {
    double point1, point2, point3, point4;
};

struct trianglepoints {
    double point1, point2, point3;  
};