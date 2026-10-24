/* HSTMATCH module=EBOOT.BIN start=0x00204ac8 end=0x00204c80 symbol=FUN_00204ac8 lang=c++ */
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
extern undefined DAT_0034b340;
extern void FUN_00000a00(...);
extern void FUN_00091c48(...);
extern void FUN_00092ff8(...);
extern int * FUN_000b42f8(...);
extern void FUN_00205428(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" int FUN_00204ac8(int param_1,short param_2)
{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    if (*(unsigned char *)(param_1 + 8) == '\0') {
      piVar2 = *(int **)(&DAT_0034b340 + *(int *)(param_1 + 4) * 4);
      if (piVar2 != (int *)0x0) {
        delete ((VC_0 *)(piVar2));
        iVar1 = *(int *)(param_1 + 4);
        *(undefined4 *)(&DAT_0034b340 + iVar1 * 4) = 0;
      }
    }
    else if (*(unsigned char *)(param_1 + 9) == '\0') {
      piVar2 = *(int **)(&DAT_0034b340 + *(int *)(param_1 + 4) * 4);
      if (piVar2 != (int *)0x0) {
        if (piVar2[0x14] == 0) {
          if (piVar2 != (int *)0x0) {
            delete ((VC_1 *)(piVar2));
            iVar1 = *(int *)(param_1 + 4);
            *(undefined4 *)(&DAT_0034b340 + iVar1 * 4) = 0;
          }
        }
        else {
          FUN_00091c48(piVar2,0);
          FUN_00092ff8(*(undefined4 *)(&DAT_0034b340 + *(int *)(param_1 + 4) * 4));
        }
      }
    }
    else {
      piVar2 = *(int **)(&DAT_0034b340 + *(int *)(param_1 + 4) * 4);
      if (piVar2 != (int *)0x0) {
        delete ((VC_2 *)(piVar2));
        iVar1 = *(int *)(param_1 + 4);
        *(undefined4 *)(&DAT_0034b340 + iVar1 * 4) = 0;
      }
    }
    FUN_00205428(param_1);
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_000b42f8(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss: 110/110 words, 53 differ, first at +0x20. The byte fields at +8/+9 must be
// `unsigned char` (retail `lbu`, the draft's `char` gave `lb`). Retail's arm order is
// `if (b8 != 0) { if (b9 == 0) {..} else {..} } else {..}` with the b8==0 arm out of line behind
// `beqzl v0,0x204be0` and `lw v1,4(s1)` (a reload of the slot index) in the delay slot; our
// `if (b8 == 0) A; else if (b9 == 0) B; else C;` compiles to the inverted `bnezl`. Reordering the
// arms by hand did not change the 53 (the reload/schedule of `p->slot` is the real difference).
// near miss from lane fm9 (unreviewed)
