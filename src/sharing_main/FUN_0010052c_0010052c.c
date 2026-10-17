/* HSTMATCH module=hstp_trans_main.prx start=0x0010052c end=0x001005e0 symbol=FUN_0010052c lang=c99 */
/* Clone of src/eboot/FUN_000fadf0_000fadf0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0a2c;
extern undefined4 DAT_003e1f60;
extern void *FUN_00000bcc(int size);
extern undefined4 * FUN_0001ec44();
extern void FUN_0001ef34();
extern void *FUN_000fcfa0(void *param_1);
extern void *FUN_00101164(void *param_1);
extern void *FUN_0020aa34(void *param_1,int param_2);

undefined4 * FUN_0010052c(undefined4 *param_1)
{
  void *p;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b0a2c);
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  DAT_003e1f60 = (unsigned int)(param_1);
  p = FUN_00000bcc(0x158);
  if (p != 0) p = FUN_000fcfa0(p);
  param_1[0xf] = (unsigned int)p;
  p = FUN_00000bcc(0x60);
  if (p != 0) p = FUN_00101164(p);
  param_1[0x11] = (unsigned int)p;
  p = FUN_00000bcc(0x58);
  if (p != 0) p = FUN_0020aa34(p,0);
  param_1[0x10] = (unsigned int)p;
  FUN_0001ef34(param_1,p);
  FUN_0001ef34(param_1,param_1[0x11]);
  return param_1;
}
