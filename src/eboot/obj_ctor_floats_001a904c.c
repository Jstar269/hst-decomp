/* HSTMATCH module=EBOOT.BIN start=0x001a904c end=0x001a90f8 symbol=FUN_001a904c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the four copied globals and the destination fields are float (lwc1/swc1); exact match verified; names and types await human review. */
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

extern float DAT_002c2f70;
extern float DAT_002c2f74;
extern float DAT_002c2f78;
extern float DAT_002c2f7c;
extern undefined DAT_003092a8;
extern undefined * DAT_003313c4;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();
extern void FUN_0005bc58();

typedef struct O { unsigned int vt; int pad[3]; float a, b, c, d; } O;

O * FUN_001a904c(O *param_1)
{
  int iVar1;
  undefined1 auStack_2c0 [704];
  
  param_1->vt = (unsigned int)(&DAT_003092a8);
  param_1->a = DAT_002c2f70;
  param_1->b = DAT_002c2f74;
  param_1->c = DAT_002c2f78;
  param_1->d = DAT_002c2f7c;
  FUN_0005b670(auStack_2c0);
  FUN_0005ba78(DAT_003313c4,auStack_2c0);
  iVar1 = (int)(DAT_003313c4);
  *(undefined4 *)(DAT_003313c4 + 0x1e0) = 0;
  *(undefined4 *)(iVar1 + 0x1e4) = 0;
  *(undefined4 *)(iVar1 + 0x1e8) = 0xbf800000;
  *(undefined4 *)(iVar1 + 0x1ec) = 0;
  FUN_0005bc58(DAT_003313c4);
  FUN_0005ba00(auStack_2c0,0xffffffff);
  return param_1;
}
