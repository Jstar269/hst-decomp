/* HSTMATCH module=EBOOT.BIN start=0x001522b4 end=0x001523fc symbol=FUN_001522b4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Vec4Path/Float4 structs, float reads (swc1) from the stream helper, (h >> 12) & 0xf field extract (ext), unsigned h for the sltiu range test with -1 as the then value, indexed loop over the point array; readability pass; exact match verified; names and types await human review. */
#include "hst/vec4_path.h"

/* Point-count field of the header word: bits 12..15. */
#define PATH_COUNT_SHIFT 12
#define PATH_COUNT_MASK 0xf
/* Low 12 bits of the header word: values from 0x800 up mean "none" (-1), below it the value itself. */
#define PATH_VALUE_MASK 0xfff
#define PATH_VALUE_NONE_FROM 0x800
#define PATH_VALUE_BITS 0x7ff

extern char DAT_0030840c;
extern char DAT_00308c20;
extern "C" void *FUN_000008d8(void *, void *, int, int, int);
extern "C" void *FUN_00000a90(int);
extern "C" Float4 *FUN_00022418(Float4 *, Float4 *, Float4 *); /* vector add, out first */
extern "C" float FUN_0014f014(void *);
extern "C" unsigned short FUN_0014f050(void *);
extern "C" void FUN_00057344();

/* Constructor: reads the header word, then count points; each point is stored as the sum with the one before it. */
extern "C" Vec4Path *FUN_001522b4(Vec4Path *self, void *stream)
{
  self->vtable = &DAT_0030840c;
  self->unk04 = 0;
  self->vtable = &DAT_00308c20;
  unsigned header = FUN_0014f050(stream);
  self->count = (header >> PATH_COUNT_SHIFT) & PATH_COUNT_MASK;
  self->unk08 = (header & PATH_VALUE_MASK) >= PATH_VALUE_NONE_FROM ? -1 : (header & PATH_VALUE_BITS);
  int n = self->count;
  self->points = (Float4 *)FUN_000008d8(FUN_00000a90(n * 0x10 + 0x10), (void *)FUN_00057344, 0, 0x10, n);
  for (int i = 0; i < self->count; i++) {
    self->points[i].x = FUN_0014f014(stream);
    self->points[i].y = FUN_0014f014(stream);
    self->points[i].z = FUN_0014f014(stream);
    self->points[i].w = 1.0f;
    if (i > 0) FUN_00022418(&self->points[i], &self->points[i], &self->points[i - 1]);
  }
  return self;
}
