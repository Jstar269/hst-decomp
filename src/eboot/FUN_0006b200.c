/* HSTMATCH module=EBOOT.BIN start=0x0006b200 end=0x0006b274 symbol=FUN_0006b200 lang=c99 */
/* Clone of src/sharing_main/FUN_0006c774.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_0006c134();

void FUN_0006b200(int *param_1,char *param_2,int *param_3)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_0006c134(param_2,param_3,*(undefined4 *)(param_2 + 4),param_2 + 4));
  if ((iVar1 == param_2 + 4) || (*param_3 < *(int *)(iVar1 + 0xc))) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)(iVar1);
  }
  return;
}
