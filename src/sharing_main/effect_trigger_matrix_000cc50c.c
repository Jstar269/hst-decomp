/* HSTMATCH module=hstp_trans_main.prx start=0x000cc50c end=0x000cc718 symbol=FUN_000cc50c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed structs, one && chain for the guards, float compares with the variable on the left (13.0f bounds), the three motion fields read into locals in order mode, f104, f100 (retail's hoisted loads and FPR numbering), effect offset idx * 0x1b0 computed once and re-added per call, the 64-byte matrix copied row by row into a local (batched lwc1/swc1) with the -0.05f row-3 y; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 r0, r1, r2, r3; } Mat4;

typedef struct {
  char pad0[0xc0];
  u8 c0;
  char padc1[3];
  float c4;
  char padc8[8];
  float d0;
} Effect;

typedef struct {
  char pad0[0x30];
  Mat4 m30;
  char pad70[0x80];
  int f0f0;
  char padf4[0xc];
  float f100;
  float f104;
} Motion;

typedef struct {
  char pad0[0x58];
  Motion *f58;
} Holder;

typedef struct {
  char pad0[0x5bc];
  Holder *f5bc;
} Player;

typedef struct {
  char pad0[0x70];
  Player *players[8];
} Mgr;

typedef struct {
  char pad0[0x1d0];
  char *f1d0;
  u8 *f1d4;
} Self;

extern Mgr *DAT_003e19f0;
extern void FUN_00055b64(Effect *, Mat4 *);
extern void FUN_00059ac0(Effect *, u8, int);
extern void FUN_00059ba8(Effect *, int, float);
extern void FUN_00059d68(Effect *, int);
extern int FUN_000b66a8(Player *);

void FUN_000cc50c(Self *self, int idx)
{
  Player *pl;
  Effect *e;
  int off;
  Mat4 m;

  pl = DAT_003e19f0->players[idx];
  if (pl != 0 && self->f1d4 != 0 && self->f1d0 != 0 && FUN_000b66a8(pl) != 0 &&
      self->f1d4[idx] == 0) {
    Motion *mo = pl->f5bc->f58;
    int mode = mo->f0f0;
    float f104 = mo->f104;
    float f100 = mo->f100;
    if (mode != 0x7e && mode != 0x80 && f104 <= 13.0f && f104 + f100 > 13.0f) {
      off = idx * 0x1b0;
      e = (Effect *)(self->f1d0 + off);
      FUN_00059ba8(e, -1, 1.0f);
      e->c4 = 1.0f;
      e = (Effect *)(self->f1d0 + off);
      FUN_00059ac0(e, 0, -1);
      e->c0 = 0;
      e = (Effect *)(self->f1d0 + off);
      FUN_00059d68(e, -1);
      e->d0 = e->c4;
      self->f1d4[idx] = 1;
      m.r0 = mo->m30.r0;
      m.r1 = mo->m30.r1;
      m.r2 = mo->m30.r2;
      m.r3 = mo->m30.r3;
      m.r3.y = -0.05f;
      FUN_00055b64((Effect *)(self->f1d0 + off), &m);
    }
  }
}
