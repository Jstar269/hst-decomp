/* HSTMATCH module=EBOOT.BIN start=0x002946b0 end=0x00294840 symbol=FUN_002946b0 lang=c++ */
extern "C" {
extern int DAT_00309e48;
extern int DAT_0034a850;
extern char DAT_002cac94[];
extern char DAT_002caca4[];
extern char DAT_002cacc8[];
extern char DAT_002cae44[];
extern char DAT_002cae5c[];
extern void FUN_00000a00(void *p);
extern void FUN_000104e0(void);
extern void FUN_0001f0f0(void *p, int mode);
extern void FUN_00294684(char *fmt, ...);
extern int FUN_002b7738(int fd);
extern int FUN_002b7768(int fd, void *result);
extern int FUN_002b79a8(void);
}

struct VC_0 { virtual ~VC_0(); };

struct InstallState {
  unsigned char pad00[4];
  int f04;                    /* 0x04 */
  unsigned char pad08[0x1c];
  int thread;                 /* 0x24 */
  unsigned char pad28[0x304];
  int file;                   /* 0x32c */
  unsigned char async;        /* 0x330 */
  unsigned char pad331[3];
  VC_0 *pending;              /* 0x334 */
};

extern "C" int **FUN_002946b0(int **param_1, short param_2)
{
  InstallState *inst;
  int rc;
  int file;
  unsigned char buf[8];

  if (param_1 != 0) {
    *param_1 = &DAT_00309e48;
    inst = (InstallState *)param_1[0xf];
    if (inst != 0) {
      if (inst != 0) {
        if (inst->thread >= 0) {
          rc = FUN_002b79a8();
          if (rc != 0) {
            FUN_00294684(DAT_002cae5c, rc);
          }
          else {
            FUN_00294684(DAT_002cae44, inst->thread);
          }
          inst->thread = -1;
        }
        file = inst->file;
        if (file >= 0) {
          if (inst->async != 0) {
            rc = FUN_002b7768(inst->file, buf);
            if (rc < 0) {
              FUN_00294684(DAT_002cacc8, rc);
            }
            inst->async = 0;
          }
          rc = FUN_002b7738(inst->file);
          if (rc != 0) {
            FUN_00294684(DAT_002caca4, rc);
          }
          inst->file = -1;
        }
        FUN_00294684(DAT_002cac94);
        if (inst->f04 != 0) {
          FUN_000104e0();
          inst->f04 = 0;
        }
        if (inst->pending != 0) {
          delete inst->pending;
          inst->pending = 0;
        }
        FUN_00000a00(inst);
        param_1[0xf] = 0;
      }
      else {
        param_1[0xf] = 0;
      }
    }
    DAT_0034a850 = 0;
    FUN_0001f0f0(param_1, 0);
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// NEAR 36 of 100 words, ours 100 words exactly like retail. The whole body is
// instruction-for-instruction identical; every difference is a 3-cycle of the
// callee-saved registers: retail keeps param_1 in s1, param_2 in s0 and the
// InstallState in s2, ours puts them in s2 / s1 / s0. That also flips the one
// `lw a0,36(s2)` (retail) against `lw v0,36(s0)`.
// Ruled out: the `inst == 0`-first nesting (101 words, 94 differ), an explicit
// dup of the pending null test (107), locals declared in five different orders,
// the buffer as int[2], `0 <= inst->thread`, and `inst` declared inside the if.
// What fixed the rest: writing the inner guard as `if (inst != 0) { body } else
// { param_1[0xf] = 0; }` (100 words, all instructions matching) instead of the
// decompiler's `if (inst == 0) {...} else { body }`.
// near miss from lane fm5 (unreviewed)
