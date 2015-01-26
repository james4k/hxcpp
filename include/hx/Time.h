#ifndef HX_TIME_H
#define HX_TIME_H

#ifndef HX_WINDOWS
#include <sys/time.h>
#endif
#include <time.h>

inline double HxTimestamp() {
#ifdef HX_WINDOWS
	return (double)clock()/CLOCKS_PER_SEC;
#else
	struct timeval tv;
	gettimeofday(&tv,0);
	return (double)tv.tv_sec + (double)tv.tv_usec*1e-6;
#endif
}

inline void HxSleep(unsigned int ms) {
#ifdef HX_WINDOWS
#ifndef HX_WINRT
	Sleep(ms);
#else
	// TODO
#endif
#else
	struct timespec t;
	struct timespec tmp;
	t.tv_sec = 0;
	t.tv_nsec = ms * 1000000;
	nanosleep(&t, &tmp);
#endif
}

#endif
