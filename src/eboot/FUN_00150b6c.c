/* HSTMATCH module=EBOOT.BIN start=0x00150b6c end=0x00150c1c symbol=FUN_00150b6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00150b6c.c) corrected by hand: typed the global byte and helper arguments, and reused one materialized resource flag across logging; exact match verified; names and types await human review. */
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

extern undefined DAT_002dc440;
extern unsigned char DAT_003402f0;
extern void *DAT_0034a114;
extern char DAT_002dc424[];
extern char DAT_002dc430[];
extern int *FUN_0014c384(undefined4, int);
extern void FUN_0014d044(undefined4 *);
extern void FUN_0014fd94(char *, char *);
extern void FUN_001cc988(void *, int);

undefined4 FUN_00150b6c(undefined4 param_1,undefined4 *param_2)
{
  undefined4 key = *param_2;
  int value = *FUN_0014c384(key,0xb);
  int has_resource = value != 0;
  char *message;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    if (has_resource) {
      message = DAT_002dc430;
    }
    else {
      message = (char *)(&DAT_002dc440);
    }
    FUN_0014fd94(DAT_002dc424,message);
  }
  FUN_001cc988(DAT_0034a114,has_resource);
  *(undefined1 *)(param_2[3] + 0x5a) = 1;
  *FUN_0014c384(key,0xb) = 0;
  return 0;
}
