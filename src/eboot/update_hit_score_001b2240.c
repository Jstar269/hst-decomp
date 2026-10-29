/* HSTMATCH module=EBOOT.BIN start=0x001b2240 end=0x001b2380 symbol=FUN_001b2240 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Positional voice update. When the handle behind handle_ref is still valid, computes a
   distance-based volume (FUN_001b247c), reports it scaled by 128 (FUN_00062a9c), stores it through the
   optional out_volume pointer, computes the signed direction angle (FUN_001b25bc) and reports that as
   the pan (FUN_00062abc). Returns 0 when the handle is not valid.
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

s32 FUN_001b2240(void *self, void *handle_ref, int ref_pos,
                       f32 far_value, f32 near_value, f32 near_dist, f32 far_dist, f32 *out_volume, int fold, int pos)
{
    f32 volume;
    f32 pan;

    if (FUN_001b2438(self, handle_ref) == 0) {
        return 0;
    }
    volume = FUN_001b247c(self, (void *)ref_pos, (void *)pos, far_value, near_value, near_dist, far_dist);
    if (FUN_001b2438(self, handle_ref) != 0) {
        FUN_00062a9c(*(int *)handle_ref, (int)(volume * 128.0f), (int)(volume * 128.0f));
    }
    if (out_volume != 0) {
        *out_volume = volume;
    }
    pan = FUN_001b25bc(self, (void *)ref_pos, fold, pos);
    if (FUN_001b2438(self, handle_ref) == 0) {
        return 0;
    }
    FUN_00062abc(*(int *)handle_ref, pan);
    return 1;
}
