/* HSTMATCH module=EBOOT.BIN start=0x002a5ca0 end=0x002a5e3c symbol=FUN_002a5ca0 lang=c99 */
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

extern bool FUN_001fe080();

void FUN_002a5ca0(int param_1)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = FUN_001fe080((uint *)(param_1 + 0x888),0x10,0x300);
  bVar2 = FUN_001fe080((uint *)(param_1 + 0x88c),0x40,0x300);
  bVar3 = FUN_001fe080((uint *)(param_1 + 0x890),0x80,0x300);
  bVar4 = FUN_001fe080((uint *)(param_1 + 0x894),0x20,0x300);
  if (*(char *)(param_1 + 0x17c) != '\0') {
    if (bVar1) {
      uVar5 = *(int *)(param_1 + 0x884) - 1;
      if (uVar5 < 2) {
        *(undefined4 *)(param_1 + 0x884) = 0xd;
      }
      else if (*(int *)(param_1 + 0x884) != 9) {
        *(uint *)(param_1 + 0x884) = uVar5;
      }
    }
    else if (bVar2) {
      iVar6 = *(int *)(param_1 + 0x884);
      if (iVar6 == 0xd) {
        if (*(int *)(param_1 + 0x880) == 1) {
          *(undefined4 *)(param_1 + 0x884) = 2;
        }
        else if (*(int *)(param_1 + 0x880) == 0) {
          *(undefined4 *)(param_1 + 0x884) = 1;
        }
      }
      else if ((iVar6 != 1) && (iVar6 != 7)) {
        *(int *)(param_1 + 0x884) = iVar6 + 1;
      }
    }
    else if (bVar3) {
      if ((*(int *)(param_1 + 0x884) < 9) || (0xd < *(int *)(param_1 + 0x884))) {
        *(undefined4 *)(param_1 + 0x884) = 9;
      }
    }
    else if (bVar4) {
      if (*(int *)(param_1 + 0x884) < 1) {
        iVar6 = *(int *)(param_1 + 0x880);
      }
      else {
        if (*(int *)(param_1 + 0x884) < 8) {
          return;
        }
        iVar6 = *(int *)(param_1 + 0x880);
      }
      if (iVar6 == 1) {
        *(undefined4 *)(param_1 + 0x884) = 2;
      }
      else if (iVar6 == 0) {
        *(undefined4 *)(param_1 + 0x884) = 1;
      }
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
