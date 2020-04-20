#ifndef TIMER_GLOBAL_h__
#define TIMER_GLOBAL_h__

#ifdef MASTERTIMER_DLL
#ifdef MASTERTIMER_LIB
#define TIMER_EXPORT _declspec(dllexport)
#else
#define TIMER_EXPORT _declspec(dllimport)
#endif
#else
#define TIMER_EXPORT 
#endif
#endif // TIMER_global_h__