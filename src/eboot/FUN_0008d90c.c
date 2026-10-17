/* HSTMATCH module=EBOOT.BIN start=0x0008d90c end=0x0008d958 symbol=FUN_0008d90c lang=c99 */
/* Clone of src/sharing_main/FUN_0008f0a4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002d26b0;
extern undefined4 DAT_003386c4;
extern void FUN_00110a78();

void FUN_0008d90c(char *param_1,int param_2)
{
  char *iVar1;
  
  iVar1 = (char *)(*(int *)(param_1 + 0x3c));
  if (*(int *)(iVar1 + 0x9c0) != param_2) {
    *(int *)(iVar1 + 0x9c4) = *(int *)(iVar1 + 0x9c0);
    *(int *)(iVar1 + 0x9c0) = param_2;
    *(undefined1 *)(iVar1 + 0x9c8) = 1;
    FUN_00110a78(DAT_003386c4,&DAT_002d26b0,0);
  }
  return;
}
