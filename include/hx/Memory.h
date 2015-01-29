#ifndef HX_MEMORY_H
#define HX_MEMORY_H

inline void *HxAlloc(size_t size) {
	return malloc(size);
}

inline void HxFree(void *p) {
	return free(p);
}

#endif
