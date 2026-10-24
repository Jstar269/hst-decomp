/* HSTMATCH module=EBOOT.BIN start=0x0022d250 end=0x0022d3f0 symbol=FUN_0022d250 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_0030983c;
extern int * DAT_0034b350;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern int FUN_00004138(...);
extern uint * FUN_000462a0(...);
extern undefined4 * FUN_00102ea4(...);
extern int FUN_0015dd9c(...);
extern void FUN_0022ffe4(...);
extern void FUN_00053618(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" undefined4 * FUN_0022d250(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030983c);
    FUN_0022ffe4((int)param_1);
    iVar3 = 0;
    puVar1 = param_1;
    do {
      iVar3 = iVar3 + 1;
      puVar1[0xa5] = 0;
      puVar1[0xd2] = 0;
      puVar1 = puVar1 + 3;
    } while (iVar3 < 0xf);
    if (param_1[0x87] == 0) {
      piVar2 = (int *)param_1[0x88];
    }
    else {
      FUN_0015dd9c(param_1[0x87],1);
      param_1[0x87] = 0;
      piVar2 = (int *)param_1[0x88];
    }
    if (piVar2 != (int *)0x0) {
      delete ((VC_0 *)(piVar2));
      param_1[0x88] = 0;
    }
    if (DAT_0034b350 != (int *)0x0) {
      if (DAT_0034b350 != (int *)0x0) {
        delete ((VC_1 *)(DAT_0034b350));
      }
      DAT_0034b350 = (int *)0x0;
    }
    FUN_00000788((int)(param_1 + 0xd1),FUN_00053618,0xc,0xf);
    FUN_00000788((int)(param_1 + 0xa4),FUN_00053618,0xc,0xf);
    if ((char *)param_1 + 0x88 != (char *)0) {
      FUN_000462a0(param_1 + 0x25,-1);
      FUN_00004138((int)(param_1 + 0x22),0);
    }
    if ((char *)param_1 + 0x70 != (char *)0) {
      FUN_000462a0(param_1 + 0x1f,-1);
      FUN_00004138((int)(param_1 + 0x1c),0);
    }
    if ((char *)param_1 + 0x58 != (char *)0) {
      FUN_000462a0(param_1 + 0x19,-1);
      FUN_00004138((int)(param_1 + 0x16),0);
    }
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss: 104/104 words, 32 differing (destructor of a scene object).
// Blockers:
// 1. FRAME: retail is 32 bytes with ra@12, s1@8, s0@4 - the saves sit at the BOTTOM of the
//    frame and the top 16 bytes are untouched. MWCC puts ra at frame_top-4 (28 for a 32-byte
//    frame), so this is either a 16-byte outgoing/home area or a 16-byte local, and MWCC with
//    the same source gives a 16-byte frame with ra@12/s1@8/s0@4 (i.e. exactly retail minus the
//    top 16 bytes). The `cc=gcc171-O2` profile also compiles it to 16 bytes (and inserts the
//    `seh` on the short parameter that retail does NOT have), so the frame is not explained by
//    switching compilers - it looks like a 16-byte by-value argument or local in the original.
// 2. The loop `puVar1[0xa5] = 0; puVar1[0xd2] = 0;` is retail `lw v1,660(a0); addiu a1,a1,1;
//    slti v0,a1,15; subu v1,v1,v1; sw v1,660(a0)` - the store value is materialised as
//    `v1 - v1` after a redundant load, not `sw zero`; nothing in the draft produces that, and it
//    also keeps a1 as the counter with a0 bumped by 12 (the draft folds the induction into one
//    pointer).
// 3. retail keeps a NULL test (`beqzl a0, ...`) before the delete of param_1[0x88] and a second
//    one for the global, in a different order than the draft's `delete`.
// Not pursued further in this pass; revisit with the frame question first.
// near miss from lane fm9 (unreviewed)
