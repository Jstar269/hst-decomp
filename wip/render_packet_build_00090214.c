/* HSTMATCH module=EBOOT.BIN start=0x00090214 end=0x0009044c symbol=FUN_00090214 lang=c99 */
/* NEAR MISS 134/142 words, 112 differ, and all of the remaining difference is stack layout:
   retail's 0x1e0-byte snapshot struct sits at sp+0x40 with a 0x220 frame, ours lands at sp+0x30 with 0x210,
   i.e. retail has one more 16-byte slot between the two loop temporaries and the saved registers; every
   displacement in the body is therefore 0x10 low, which is most of the 112 words. The struct itself is right
   (f00/f04, four 16-byte quats at 0x10/0x20/0x30/0x40, three 0x40 matrices at 0x50/0x90/0xd0, nine words at
   0x110, 12 bytes at 0x134, 144 at 0x140, byte 0x1d0, int 0x1d4) - adding an explicit 8-byte tail pad moved the
   base from 0x38 to 0x30 while the frame stayed 0x210, so MWCC is placing the aggregate against the top of the
   frame rather than after the temporaries. Also need: retail holds param_2 in s1 and param_3 in s0 (ours are
   swapped) and loads the four float limits into f22/f23/f20/f21 in that order (ours f23/f22/f21/f20). */
typedef struct Snap {
  void *f00;
  int f04;
  char pad08[8];
  float q10[4];
  float q20[4];
  float q30[4];
  float q40[4];
  char m50[0x40];
  char m90[0x40];
  char mD0[0x40];
  int f110[9];
  char f134[12];
  char f140[144];
  unsigned char f1D0;
  char pad1D1[3];
  int f1D4;
  char pad1D8[8];
} Snap;

extern char DAT_00307424;
extern char *DAT_003402a0;

extern void FUN_0004c644(void *, char *);
extern void FUN_00058694(void *, char *);
extern void FUN_0008da9c(char *);
extern void FUN_0008dba8(char *, int, int, int, float *);
extern void FUN_0008fbc8(void *, char *);
extern void FUN_0008fcc8(void *, char *);
extern void FUN_000c24a8(Snap *, int);
extern void FUN_000c2aa0(int, int, Snap *, int);

void FUN_00090214(char *param_1, int param_2, int param_3)
{
  float lo_x, hi_x, lo_y, hi_y;
  Snap s;
  float a[4];
  float b[4];
  int flag;
  int i;

  lo_x = *(float *)(DAT_003402a0 + 0x1340);
  hi_x = *(float *)(DAT_003402a0 + 0x1348);
  lo_y = *(float *)(DAT_003402a0 + 0x1344);
  hi_y = *(float *)(DAT_003402a0 + 0x134c);
  FUN_0008da9c(param_1 + 0x26c);
  s.f00 = &DAT_00307424;
  s.f04 = *(int *)(param_1 + 4);
  FUN_0004c644(s.q10, param_1 + 0x10);
  FUN_0004c644(s.q20, param_1 + 0x20);
  FUN_0004c644(s.q30, param_1 + 0x30);
  FUN_0004c644(s.q40, param_1 + 0x40);
  FUN_00058694(s.m50, param_1 + 0x50);
  FUN_00058694(s.m90, param_1 + 0x90);
  FUN_00058694(s.mD0, param_1 + 0xd0);
  for (i = 0; i < 9; i++)
    s.f110[i] = *(int *)(param_1 + 0x110 + i * 4);
  FUN_0008fcc8(s.f134, param_1 + 0x134);
  FUN_0008fbc8(s.f140, param_1 + 0x140);
  s.f1D0 = *(unsigned char *)(param_1 + 0x1d0);
  s.f1D4 = *(int *)(param_1 + 0x1d4);
  s.f04 = param_3;
  for (;;) {
    a[0] = s.q10[0];
    a[1] = s.q10[1];
    a[2] = s.q10[2];
    a[3] = s.q10[3];
    flag = 1;
    if (s.q10[0] < lo_x || hi_x < s.q10[0] || s.q10[2] < lo_y || hi_y < s.q10[2])
      flag = 0;
    b[0] = s.q10[0];
    b[1] = s.q10[1];
    b[2] = s.q10[2];
    b[3] = s.q10[3];
    FUN_0008dba8(param_1 + 0x26c, param_2, flag, s.f04, b);
    if (s.f1D4 > 1 || s.f04 == 2 || s.f04 == 3)
      break;
    param_2 = param_2 + 1;
    FUN_000c2aa0(*(int *)(param_1 + 0x244), *(int *)(param_1 + 0x248), &s, 0);
  }
  FUN_000c24a8(&s, -1);
}
// near miss from lane fm7 (unreviewed)
