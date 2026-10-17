/* HSTMATCH module=EBOOT.BIN start=0x001542dc end=0x0015435c symbol=FUN_001542dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), the *param_2 load is hoisted into a local before the value test, and the value is selected with if (x != 0) val else 0 so the branch stays non-likely; exact match verified; names and types await human review. */
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

typedef struct { int pad0; int pad4; int f8; int fc; } S154;
extern unsigned char DAT_003402f0;
extern undefined * DAT_0034a118;
extern char DAT_002dc8a0[];
extern int FUN_0014c384(int a,int b);
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt,int b);

undefined4 FUN_001542dc(S154 *s,int *p)
{
  undefined4 *puVar1;
  undefined4 uVar2;

  if (DAT_003402f0 != '\0') {
    FUN_0014d044(p);
    FUN_0014fd94(DAT_002dc8a0,s->f8);
  }
  int a = *p;
  if (*(int *)(DAT_0034a118 + 0x50) != 0) {
    uVar2 = *(undefined4 *)(*(int *)(DAT_0034a118 + 0x50) + 0x1b4);
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)FUN_0014c384(a,s->f8);
  *puVar1 = uVar2;
  return 0;
}
