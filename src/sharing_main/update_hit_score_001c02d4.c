/* HSTMATCH module=hstp_trans_main.prx start=0x001c02d4 end=0x001c0414 symbol=FUN_001c02d4 lang=c99 */
/* Clone of src/eboot/update_hit_score_001b2240.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Queries the game state (FUN_001c04cc) and, when it is available, computes a score (FUN_001c0510),
   reports it scaled by 128 (FUN_00063960), stores it through the optional out pointer, computes a second
   value (FUN_001c0650) and reports that one (FUN_00063980). Returns 0 when the state is not available.
   Matching idioms: the four float arguments must be declared BEFORE the remaining int arguments so that
   the prologue copies the float parameters between the int ones; the two leading pointer arguments are
   copied into their saved registers only in front of the first call. */
typedef int undefined4;
typedef float f32;

extern int FUN_001c04cc(void *a, void *b);
extern f32 FUN_001c0510(void *a, void *b, void *c, f32 d, f32 e, f32 f, f32 g);
extern f32 FUN_001c0650(void *a, void *b, int c, int d);
extern void FUN_00063960(int a, int b, int c);
extern void FUN_00063980(int a, f32 b);

undefined4 FUN_001c02d4(void *self, void *st, int id,
                       f32 f1, f32 f2, f32 f3, f32 f4, f32 *out, int x5, int x6)
{
    f32 v;
    f32 w;

    if (FUN_001c04cc(self, st) == 0) {
        return 0;
    }
    v = FUN_001c0510(self, (void *)id, (void *)x6, f1, f2, f3, f4);
    if (FUN_001c04cc(self, st) != 0) {
        FUN_00063960(*(int *)st, (int)(v * 128.0f), (int)(v * 128.0f));
    }
    if (out != 0) {
        *out = v;
    }
    w = FUN_001c0650(self, (void *)id, x5, x6);
    if (FUN_001c04cc(self, st) == 0) {
        return 0;
    }
    FUN_00063980(*(int *)st, w);
    return 1;
}
