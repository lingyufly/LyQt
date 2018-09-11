#ifndef FUNC_H
#define FUNC_H


#ifdef WIN32
#define EXIM __declspec(dllimport)
#else
#define EXIM
#endif


extern "C"
{
EXIM int func_add(int a, int b);
}
#endif // FUNC_H
