/* HSTMATCH module=EBOOT.BIN start=0x001b61c4 end=0x001b62fc symbol=FUN_001b61c4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Distance check with a random trigger: the global vector DAT_00338760 (its w component at +0xc is
   DAT_0033876c) is only used when that component is above zero, the vector difference against the
   target of FUN_00093838 is taken in the x/z plane and compared with the squared radius
   DAT_002e99c0; when the target is idle (DAT_003386b0->f88->f1d4 == 0) the global LCG is advanced
   and a 1/32768-scaled draw decides whether FUN_001b2bb8 is called with the string at DAT_0034179c
   and the id 187.
   Matching idioms: the vector pointer is a TERNARY ("w > 0.0f ? &DAT_00338760 : 0") and the following
   null test is NOT folded away (the bc1tl plus the "move s0,zero" in the delay slot is retail's);
   the function has a second, unused first parameter (retail reads the target through a1);
   the x and z components have to be read into LOCALS before the flag test - that is what puts the
   lwc1 of z in front of the f88 load and the lwc1 of x into the branch delay slot;
   the random draw is "(float)((seed >> 16) & 0x7fff) * 3.0517578e-05f" and the multiplier is the
   literal 1/32768 (0x38000000), not 0.25f. */
typedef struct { float x, y, z, w; } Vec4;

/* Context object: unk88 is a pointer to an object whose word at 0x1d4 is tested, unk5bc is the target handed to the position query. */
typedef struct {
  char pad88[0x88];
  void *unk88;
  char pad5bc[0x5bc - 0x8c];
  void *unk5bc;
} Ctx;

#define LCG_MUL 0x343fd /* constants of the global random generator */
#define LCG_ADD 0x269ec3
#define RAND_MASK 0x7fff

extern float DAT_0033876c;
extern Vec4 DAT_00338760;
extern Ctx *DAT_003386b0;
extern float DAT_002e99c0;
extern void *DAT_0034179c;
extern Vec4 *FUN_00093838(void *a0);
extern void FUN_00022434(Vec4 *out, Vec4 *a, Vec4 *b);
extern unsigned int *FUN_001b4e08(void);
extern void FUN_001b2bb8(void *a0, int a1);

/* If the position vector is active and close enough to the target, with a random 50% chance calls the
   global manager with id 187. */
void FUN_001b61c4(int unused, Ctx *ctx)
{
  Vec4 *vec = (DAT_0033876c > 0.0f) ? &DAT_00338760 : 0;
  if (vec != 0) {
    Vec4 delta;
    FUN_00022434(&delta, vec, FUN_00093838(ctx->unk5bc));
    float x = delta.x;
    float z = delta.z;
    if (DAT_003386b0->unk88 != 0 && *(int *)((char *)DAT_003386b0->unk88 + 0x1d4) == 0) {
      if (x * x + z * z < DAT_002e99c0 * DAT_002e99c0) {
        unsigned int *state = FUN_001b4e08();
        unsigned int rng = *state;
        rng = rng * LCG_MUL + LCG_ADD;
        *state = rng;
        if ((float)((rng >> 16) & RAND_MASK) * 3.0517578e-05f < 0.5f) {
          FUN_001b2bb8(&DAT_0034179c, 187);
        }
      }
    }
  }
}
