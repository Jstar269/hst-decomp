/* HSTMATCH module=EBOOT.BIN start=0x002acbf8 end=0x002acd28 symbol=FUN_002acbf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: assigned the allocation result in the null-check expression and shared its return path; exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined DAT_0030779c;
extern char DAT_002cc2b4[];
extern char DAT_002cc2bc[];
extern char DAT_002cc2c4[];
extern int FUN_00000bcc();
extern int FUN_00014934();
extern undefined4 FUN_00056098();
extern undefined4 * FUN_000fbf84();
extern undefined4 * FUN_000fc00c();
extern undefined4 * FUN_000fc0a0();

undefined4 * FUN_002acbf8(int param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00014934(param_2,DAT_002cc2c4);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(param_1 + 0x54) = iVar1 + -1;
    *param_3 = 0 < iVar1;
  }
  else {
    iVar1 = FUN_00014934(param_2,DAT_002cc2bc);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x58);
      *(int *)(param_1 + 0x58) = iVar1 + -1;
      *param_3 = 0 < iVar1;
    }
    else {
      iVar1 = FUN_00014934(param_2,DAT_002cc2b4);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        *param_3 = 0 < iVar1;
      }
      else {
        *param_3 = 0;
      }
    }
  }
  if ((puVar2 = (undefined4 *)FUN_00000bcc(0xd0)) == (undefined4 *)0x0) goto done;
  FUN_000fc0a0(puVar2);
  FUN_00056098(puVar2 + 0xc);
  *puVar2 = (unsigned int)(&DAT_0030779c);
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0xffffffff;
  puVar2[0x1e] = 0x3f800000;
  puVar2[0x1f] = 0x3f800000;
  FUN_00056098(puVar2 + 0x20);
  puVar2[0x30] = param_2;
  FUN_000fc00c(puVar2,&DAT_002bc410);
  FUN_000fbf84(puVar2 + 0x20,&DAT_002bc410);
done:
  return puVar2;
}
