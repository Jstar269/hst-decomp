/* HSTMATCH module=EBOOT.BIN start=0x001c3ae8 end=0x001c3b64 symbol=FUN_001c3ae8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: preserved the nested null check and field reset form that matches the cleanup tail; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();
extern void FUN_000104e0();
extern void FUN_002293d4();
extern void FUN_00229774();

struct OwnerView {
  char pad[0x24];
  unsigned char *child;
};

void FUN_001c3ae8(int param_1)
{
  unsigned char *pcVar1;
  
  FUN_00229774(param_1 + 0x34);
  FUN_002293d4(param_1 + 0x34);
  pcVar1 = (unsigned char *)*(char **)(param_1 + 0x24);
  if (pcVar1 == (unsigned char *)0x0)
    return;
  if (pcVar1 != (unsigned char *)0x0) {
    if ((*pcVar1 != 0) && (*(int *)(pcVar1 + 4) != 0)) {
      FUN_000104e0(*(int *)(pcVar1 + 4));
    }
    FUN_00000a00(pcVar1);
    ((struct OwnerView *)param_1)->child = 0;
  }
  else
    ((struct OwnerView *)param_1)->child = 0;
  return;
}
