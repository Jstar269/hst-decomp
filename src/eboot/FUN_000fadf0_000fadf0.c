/* HSTMATCH module=EBOOT.BIN start=0x000fadf0 end=0x000faea4 symbol=FUN_000fadf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: kept each allocation result through the constructor and member-store join; exact match verified; names and types await human review. */
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

extern undefined DAT_00307760;
extern undefined4 DAT_00338c20;
extern void *FUN_00000bcc(int size);
extern undefined4 * FUN_0001f06c();
extern void FUN_0001f21c();
extern void *FUN_000f78ac(void *param_1);
extern void *FUN_000fba28(void *param_1);
extern void *FUN_001fc31c(void *param_1,int param_2);

undefined4 * FUN_000fadf0(undefined4 *param_1)
{
  void *p;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307760);
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  DAT_00338c20 = (unsigned int)(param_1);
  p = FUN_00000bcc(0x158);
  if (p != 0) p = FUN_000f78ac(p);
  param_1[0xf] = (unsigned int)p;
  p = FUN_00000bcc(0x60);
  if (p != 0) p = FUN_000fba28(p);
  param_1[0x11] = (unsigned int)p;
  p = FUN_00000bcc(0x58);
  if (p != 0) p = FUN_001fc31c(p,0);
  param_1[0x10] = (unsigned int)p;
  FUN_0001f21c(param_1,p);
  FUN_0001f21c(param_1,param_1[0x11]);
  return param_1;
}
