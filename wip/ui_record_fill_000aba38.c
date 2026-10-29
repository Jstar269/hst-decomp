/* HSTMATCH module=EBOOT.BIN start=0x000aba38 end=0x000abc64 symbol=FUN_000aba38 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern int DAT_003386b0;
extern int DAT_00338b44;

typedef struct { float x, y, z, w; } Vec4;

typedef struct {
  Vec4 a;
  Vec4 b;
  int z0;
  int z1;
  int z2;
  int w44;
  char b0 : 1;
  char b1 : 2;
  char b2 : 3;
  short b3 : 3;
  char e : 5;
  char f : 2;
  char h : 1;
  char i : 1;
  char j : 1;
  short g : 8;
  short s52;
  unsigned char c54;
  unsigned char c55;
  char pad[8];
} Rec;

extern void FUN_0008fcd8(int, float *, float *);
extern void FUN_000114c0(void *, int, int);
extern void FUN_00054330(void *, float *);
extern void FUN_000a0400(void *, int);
extern void FUN_001178f0(int, void *, int, int);

void FUN_000aba38(int param_1, int param_2, int param_3)
{
  float va[4];
  float vb[4];
  Rec w;
  int s0;
  int s1;

  *(Vec4 *)va = *(Vec4 *)param_2;
  *(Vec4 *)vb = *(Vec4 *)param_3;
  FUN_0008fcd8(*(int *)(DAT_003386b0 + 0x88), va, vb);
  if (*(int *)(DAT_003386b0 + 0x3c) == 7) return;
  w.w44 = 1;
  FUN_000114c0(&w, 0, 0x40);
  w.b0 = 0;
  s0 = *(short *)(param_1 + 0x144);
  s1 = *(short *)(param_1 + 0x148);
  FUN_00054330(&w, va);
  FUN_00054330(&w.b, vb);
  w.b1 = s0;
  w.b2 = s1;
  w.b3 = 0;
  w.e = 0;
  w.g = 0;
  w.f = 1;
  w.h = 0;
  w.i = 0;
  w.j = 0;
  w.z0 = 0;
  w.z1 = 0;
  w.z2 = 0;
  w.s52 = 0;
  FUN_000a0400((char *)&w + 44, param_1 + 0x168);
  w.c54 = 0;
  w.c55 = 0;
  FUN_001178f0(*(int *)(DAT_003386b0 + 0x9c), &w, !*(unsigned char *)(DAT_00338b44 + 0x5c), 1);
  return;
}

// NEAR (lane sx1): 139/139 words, 9 differ (was 110/139, 99 differ). Only the saved-register naming differs: retail param_1=s2 (ours s0), field-324 value s0
// (ours s2) and the order of the two lh loads (ret loads 328 first, hoisted above the first andi). Levers found: the 64-byte work record is a struct with
// BITFIELDS declared in memory order with plain (signed) char / short container types (signed containers give retail's lb/lh + seb): b0:1 b1:2 b2:3 (byte 64),
// short b3:3, char e:5 f:2 (byte 65), char h:1 i:1 j:1 (byte 66) then short g:8 (bits 3-10 of the halfword at 66); assigned in the order b0,b1,b2,b3,e,g,f,h,i,j
// with every literal 0 kept (mwcc emits `andi r,zero,N` for each); `w.s52 = 0;` BEFORE the FUN_000a0400 call fills its jal slot; `!*(unsigned char *)` for
// the sltu/xori argument. Ruled out for the naming: int self = param_1 / char *self, declaring s0/s1 in either order or at first use, hoisting the loads to the top.
// improved by lane sx1 (unreviewed): 99 -> 9 differing words
