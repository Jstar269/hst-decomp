/* HSTMATCH module=EBOOT.BIN start=0x000aba38 end=0x000abc64 symbol=FUN_000aba38 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
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

extern void FUN_0008fcd8(int, float *, float *);
extern void FUN_000114c0(void *, int, int);
extern void FUN_00054330(void *, float *);
extern void FUN_000a0400(void *, int);
extern void FUN_001178f0(int, void *, int, int);

void FUN_000aba38(int param_1, int param_2, int param_3)
{
  float va[4];
  float vb[4];
  unsigned char w[64];
  int s0;
  int s1;
  char c;

  *(Vec4 *)va = *(Vec4 *)param_2;
  *(Vec4 *)vb = *(Vec4 *)param_3;
  FUN_0008fcd8(*(int *)(DAT_003386b0 + 0x88), va, vb);
  if (*(int *)(DAT_003386b0 + 0x3c) == 7) return;
  *(int *)(w + 44) = 1;
  FUN_000114c0(w, 0, 0x40);
  w[48] = (w[48] & 0xfe) | 1;
  s0 = *(short *)(param_1 + 0x144);
  s1 = *(short *)(param_1 + 0x148);
  FUN_00054330(w, va);
  FUN_00054330(w + 16, vb);
  c = w[48];
  c = (c & 0xf9) | ((s0 & 3) << 1);
  c = (c & 0xc7) | ((s1 & 7) << 3);
  w[48] = c;
  *(short *)(w + 48) = (*(short *)(w + 48) & 0xfe3f) | 0x1c0;
  w[65] = (w[65] & 0xc1) | 0x3e;
  w[65] = (w[65] & 0xbf) | 0x40;
  *(short *)(w + 50) = (*(short *)(w + 50) & 0xf807) | 0x7f8;
  w[66] = w[66] | 7;
  *(int *)(w + 32) = 0;
  *(int *)(w + 36) = 0;
  *(int *)(w + 40) = 0;
  FUN_000a0400(w + 44, param_1 + 0x168);
  *(short *)(w + 52) = 0;
  w[54] = 0;
  w[55] = 0;
  FUN_001178f0(*(int *)(DAT_003386b0 + 0x9c), w, *(char *)(DAT_00338b44 + 0x5c) == '\0', 1);
  return;
}

/* NEAR MISS (first attempt, 104/139 words, 137 differ): the frame and the local layout are established,
   the body needs re-deriving as BITFIELD writes. Retail frame = 112 with ra,s2,s1,s0 saved and s2=param_1
   (my version saves only s0), so the source keeps the record pointer in s2 and does not reload param_1.
   Locals, top down: va[4] floats at sp+96 (copied from param_2), vb[4] floats at sp+80 (param_3), and a
   64-byte work block at sp+16 whose +44 word is set to 1 before FUN_000114c0(w,0,0x40), +48 is the
   bitfield container, +52 a zeroed short, +54/+55 zeroed bytes. The three-step byte updates
   (`li -449/and, li -63/and|0x3e, li -193/and|0x40`, short `and 0xfe3f|0x1c0`, short `and 0xf807|0x7f8`,
   `andi r0,N; sll` for every inserted constant) are mwcc's codegen for plain bitfield assignments on
   `unsigned char`/`unsigned short` members, not for hand-written masks - writing the masks out by hand
   collapses them (see this file) and loses 35 words. FUN_001178f0 (= fm3's history_push_entry) gets
   (handle from DAT_003386b0+0x9c, work, *(char*)(DAT_00338b44+0x5c) == 0, 1). */
// near miss from lane fm4 (unreviewed)
// improved by lane fm10 (unreviewed): 137 -> 99 differing words
