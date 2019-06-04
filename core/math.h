#pragma once
#ifdef MATH_H
#define MATH_H
#endif
#define PI 3.14
#include <vector>
#include <cmath>
namespace matheq
{
    float square(int fac, float num)
    {
        float result = 0.0f;
        for (int i = 0; i < fac; i++)
        {
            result += num * num;
        }
        return result;
    }

    double square(int fac, double num)
    {
        double result = 0.0;
        for (int i = 0; i < fac; i++)
        {
            result += num * num;
        }
        return result;
    }

    int square(int fac, int num)
    {
        int result = 0;
        for (int i = 0; i < fac; i++)
        {
            result += num * num;
        }
        return result;
    }

    float pow2(float num)
    {
        return num * num;
    }

    int pow2(int num)
    {
        return num * num;
    }

    double pow2(double num)
    {
        return num * num;
    }

    vector<int> gcf(int num, int num2)
    {
        int i = 0;
        vector<int> bothgcf;
        vector<int> gcfs1;
        vector<int> gcfs2;
        while (i < num)
        {
            i++;
            if (num % i == 0)
            {
                gcfs1.push_back(i);
            }
        }

        int j = 0;
        while (j < num2)
        {
            j++;
            if (num2 % j == 0)
            {
                gcfs2.push_back(j);
            }
        }

        for (unsigned int i = 0; i < gcfs1.size(); i++)
        {
            bothgcf.push_back(gcfs1[i]);
        }

        for (unsigned int j = 0; j < gcfs2.size(); j++)
        {
            bothgcf.push_back(gcfs2[j]);
        }
        for (unsigned int k = 0; k < bothgcf.size(); k++)
        {
            cout << bothgcf[k] << endl;
        }
        return bothgcf;
    }

    int floor(int num)
    {
        return floor(num);
    }

    double floor(double num)
    {
        return floor(num);
    }

    float floor(float num)
    {
        return floor(num);
    }

    int abs(int n)
    {
        return (n > 0) ? -n : n;
    }

    double abs(double n)
    {
        return (n > 0) ? -n : n;
    }

    float abs(float n)
    {
        return (n > 0) ? -n : n;
    }

    float cos(float angle)
    {
        float rad_angle, solvedang = 0.0f;
        rad_angle=(angle)*PI / 180;
        return cosf(rad_angle);
    }

} // namespace matheq