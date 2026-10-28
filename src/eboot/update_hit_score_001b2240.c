/* HSTMATCH module=EBOOT.BIN start=0x001b2240 end=0x001b2380 symbol=FUN_001b2240 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Queries the game state (FUN_001b2438) and, when it is available, computes a score (FUN_001b247c),
   reports it scaled by 128 (FUN_00062a9c), stores it through the optional out pointer, computes a second
   value (FUN_001b25bc) and reports that one (FUN_00062abc). Returns 0 when the state is not available.
   Matching idioms: the four float arguments must be declared BEFORE the remaining int arguments so that
   the prologue copies the float parameters between the int ones; the two leading pointer arguments are
   copied into their saved registers only in front of the first call. */
#include "hst/types.h"
typedef float f32;

extern int FUN_001b2438(void *a, void *b);
extern f32 FUN_001b247c(void *a, void *b, void *c, f32 d, f32 e, f32 f, f32 g);
extern f32 FUN_001b25bc(void *a, void *b, int c, int d);
extern void FUN_00062a9c(int a, int b, int c);
extern void FUN_00062abc(int a, f32 b);

s32 FUN_001b2240(void *self, void *st, int id,
                       f32 f1, f32 f2, f32 f3, f32 f4, f32 *out, int x5, int x6)
{
    f32 v;
    f32 w;

    if (FUN_001b2438(self, st) == 0) {
        return 0;
    }
    v = FUN_001b247c(self, (void *)id, (void *)x6, f1, f2, f3, f4);
    if (FUN_001b2438(self, st) != 0) {
        FUN_00062a9c(*(int *)st, (int)(v * 128.0f), (int)(v * 128.0f));
    }
    if (out != 0) {
        *out = v;
    }
    w = FUN_001b25bc(self, (void *)id, x5, x6);
    if (FUN_001b2438(self, st) == 0) {
        return 0;
    }
    FUN_00062abc(*(int *)st, w);
    return 1;
}
