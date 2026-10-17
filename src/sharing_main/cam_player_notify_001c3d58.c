/* HSTMATCH module=hstp_trans_main.prx start=0x001c3d58 end=0x001c3e7c symbol=FUN_001c3d58 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idioms: `switch (mode) { case 1: ...; break; }` (a plain `if (mode == 1)` lays the blocks out differently); the two f4d9 arms are written nonzero-first; player table read from a char * base at +0x70 for the index-first addu.
typedef struct { float x, y, z, w; } Vec4;
typedef struct { char pad[0x20]; float f20, f24, f28, f2c; char pad1[0x234 - 0x30]; int f234; } Cam;
typedef struct { char pad[0x4d9]; unsigned char f4d9; char pad1[0x5bc - 0x4da]; int f5bc; } Player;
typedef struct { char pad[0x88]; Cam *cam; } Game;
typedef struct { char pad[0x7c]; int f7c; } Self;
extern Game *DAT_003e19f0;
extern int DAT_003e1e84;
extern char DAT_003eaad8;
extern float FUN_00022500(Vec4 *, Vec4 *);
extern void FUN_00022e6c(float);
extern int FUN_000e2c0c(int, int);
extern int FUN_0009575c(int);
extern void FUN_001bfd3c(void *, int, int, int);

void FUN_001c3d58(Self *self, int mode)
{
  Cam *c = DAT_003e19f0->cam;
  Vec4 v;
  int idx;
  Player *p;
  if (c == 0) return;
  v.x = c->f20;
  v.y = c->f24;
  v.z = c->f28;
  v.w = c->f2c;
  FUN_00022e6c(FUN_00022500(&v, &v));
  switch (mode) {
  case 1:
    if (FUN_000e2c0c(DAT_003e1e84, -1)) self->f7c = 1;
    break;
  }
  idx = c->f234;
  if (idx >= 0) {
    /* the player table starts at +0x70 of the same object; indexed from a char * base for retail's index-first addu */
    p = ((Player **)((char *)DAT_003e19f0 + 0x70))[idx];
    if (p != 0) {
      if (p->f4d9 != 0) {
        FUN_001bfd3c(&DAT_003eaad8, 0x56, FUN_0009575c(p->f5bc), 0);
      } else {
        FUN_001bfd3c(&DAT_003eaad8, 0x55, FUN_0009575c(p->f5bc), 0);
      }
    }
  }
}
