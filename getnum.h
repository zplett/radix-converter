#include <stdint.h>
#include <ctype.h>

#ifndef COMBINE
#define COMBINE
long combine(const int *, int (*)[], const int *);
#endif

#ifndef DECONSTRUCT_BINARY
#define DECONSTRUCT_BINARY
long deconstructBinary(long);
#endif

#ifndef GETNUMWRAP
#define GETNUMWRAP
void getnumWrap(const uint8_t);
#endif

#ifndef TOBINARY
#define TOBINARY
void tobinary(void);
#endif

#ifndef TODECIMAL
#define TODECIMAL
void todecimal(void);
#endif

#ifndef TOOCTAL
#define TOOCTAL
void tooctal(void);
#endif

#ifndef TOHEX
#define TOHEX
void tohex(void);
#endif

#ifndef FLUSHBUFFER
#define FLUSHBUFFER
long flushBuffer(int (*)[], const int *,  const int *, const int *, const int *, int *);
#endif

#ifndef VALIDATE
#define VALIDATE
int validate(int, int);
#endif
