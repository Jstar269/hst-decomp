/* HSTMATCH module=EBOOT.BIN start=0x00150620 end=0x0015068c symbol=FUN_00150620 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: early `if (FUN(...) == 0) { ...; return 1; } return 0;` shape, int (not bool) return on the gate; exact match verified; names and types await human review. */
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
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_0034a114;
extern int FUN_0014c384();
extern int FUN_001cd150();
extern undefined1 FUN_001cd290();

bool FUN_00150620(int param_1,undefined4 *param_2)
{
  undefined4 v;

  if (FUN_001cd150(DAT_0034a114) == 0) {
    v = *param_2;
    *(undefined4 *)FUN_0014c384(v,*(undefined4 *)(*(int *)(param_1 + 4) + 0xc)) =
         FUN_001cd290(DAT_0034a114) & 0xff;
    return 1;
  }
  return 0;
}
