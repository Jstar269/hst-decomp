/* HSTMATCH module=EBOOT.BIN start=0x00231a18 end=0x00231b08 symbol=FUN_00231a18 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: ordered the typed cursor and count locals to match both virtual cleanup walks; exact match verified; names and types await human review. */
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
extern undefined DAT_00309878;
extern void FUN_00000a00(...);
extern undefined4 * FUN_00102ea4(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" undefined4 * FUN_00231a18(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309878);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x5b];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0x5b] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 0xf);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x6a];
      if (piVar1 != (int *)0x0) {
        delete ((VC_1 *)(piVar1));
        puVar2[0x6a] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 10);
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
