/* HSTMATCH module=hstp_trans_main.prx start=0x001c3e84 end=0x001c3fbc symbol=FUN_001c3e84 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/check_vector_distance_001b61c4.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Distance check with a random trigger: the global vector DAT_003e1aa0 (its w component at +0xc is
   DAT_003e1aac) is only used when that component is above zero, the vector difference against the
   target of FUN_0009575c is taken in the x/z plane and compared with the squared radius
   DAT_0039157c; when the target is idle (DAT_003e19f0->f88->f1d4 == 0) the global LCG is advanced
   and a 1/32768-scaled draw decides whether FUN_001c0ce8 is called with the string at DAT_003eaad8
   and the id 187.
   Matching idioms: the vector pointer is a TERNARY ("w > 0.0f ? &DAT_003e1aa0 : 0") and the following
   null test is NOT folded away (the bc1tl plus the "move s0,zero" in the delay slot is retail's);
   the function has a second, unused first parameter (retail reads the target through a1);
   the x and z components have to be read into LOCALS before the flag test - that is what puts the
   lwc1 of z in front of the f88 load and the lwc1 of x into the branch delay slot;
   the random draw is "(float)((seed >> 16) & 0x7fff) * 3.0517578e-05f" and the multiplier is the
   literal 1/32768 (0x38000000), not 0.25f. */
typedef struct { float x, y, z, w; } Vec4;

typedef struct {
  char pad88[0x88];
  void *f88;
  char pad5bc[0x5bc - 0x8c];
  void *f5bc;
} Ctx;

extern float DAT_003e1aac;
extern Vec4 DAT_003e1aa0;
extern Ctx *DAT_003e19f0;
extern float DAT_0039157c;
extern void *DAT_003eaad8;
extern Vec4 *FUN_0009575c(void *a0);
extern void FUN_0002245c(Vec4 *out, Vec4 *a, Vec4 *b);
extern unsigned int *FUN_001c2a1c(void);
extern void FUN_001c0ce8(void *a0, int a1);

void FUN_001c3e84(int param_1, Ctx *param_2)
{
  Vec4 *p = (DAT_003e1aac > 0.0f) ? &DAT_003e1aa0 : 0;
  if (p != 0) {
    Vec4 r;
    FUN_0002245c(&r, p, FUN_0009575c(param_2->f5bc));
    float x = r.x;
    float z = r.z;
    if (DAT_003e19f0->f88 != 0 && *(int *)((char *)DAT_003e19f0->f88 + 0x1d4) == 0) {
      if (x * x + z * z < DAT_0039157c * DAT_0039157c) {
        unsigned int *seed = FUN_001c2a1c();
        unsigned int u = *seed;
        u = u * 0x343fd + 0x269ec3;
        *seed = u;
        if ((float)((u >> 16) & 0x7fff) * 3.0517578e-05f < 0.5f) {
          FUN_001c0ce8(&DAT_003eaad8, 187);
        }
      }
    }
  }
}
