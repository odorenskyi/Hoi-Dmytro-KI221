#ifndef MODULESHOI_H_INCLUDED
#define MODULESHOI_H_INCLUDED

#define Pi 3.14159265359

class ClassLab12_Hoi
{
    private:
        float LenA;
        float LenB;

    public:
        ClassLab12_Hoi(const float lenA = 1, const float lenB = 1)
        {
            LenA = lenA;
            LenB = lenB;
        }

        float getS()
        {
            return LenA * LenB * Pi;
        }

        float getLenA()
        {
            return LenA;
        }

        float getLenB()
        {
            return LenB;
        }

        bool changeLenA(float lenA);

        bool changeLenB(float lenB);

};

bool ClassLab12_Hoi::changeLenA(float lenA)
{
    if (lenA >= 0)
    {
        LenA = lenA;
        return true;
    }
    else
    {
        return false;
    }
}

bool ClassLab12_Hoi::changeLenB(float lenB)
{
    if (lenB >= 0)
    {
        LenB = lenB;
        return true;
    }
    else
    {
        return false;
    }
}

#endif // MODULESHOI_H_INCLUDED
