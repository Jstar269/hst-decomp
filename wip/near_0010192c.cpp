/* HSTMATCH module=EBOOT.BIN start=0x0010192c end=0x00101c18 symbol=FUN_0010192c lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002d8ad4;
extern undefined DAT_002d8ad8;
extern char DAT_002d8ab4[];
extern char DAT_002d8adc[];
extern char DAT_002d8ae8[];
extern char DAT_002d8af0[];
extern int FUN_00000bcc(int);
extern int FUN_00014a40(int);
extern char * FUN_00014d64(int, void *);
extern void FUN_001006b0(const char *);
extern void FUN_00107130(void *, void *, int);
}
struct Callback {
  virtual void p0() = 0;
  virtual void method_0c(int) = 0;
  virtual void method_10(int) = 0;
  virtual void p14() = 0;
  virtual void method_18() = 0;
};

extern "C" undefined4 * FUN_0010192c(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5, undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined4 uStackX_0, undefined4 uStackX_4,undefined4 uStackX_8,int iStackX_c)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *local_4;
  undefined4 first_value;
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_001006b0(DAT_002d8ab4);
  }
  local_4 = (undefined4 *)FUN_00000bcc(0x2c);
  *(undefined2 *)(local_4 + 1) = param_4;
  *(undefined2 *)((int)local_4 + 6) = param_5;
  *(undefined2 *)(local_4 + 2) = param_6;
  *(undefined2 *)((int)local_4 + 10) = param_7;
  *(undefined2 *)(local_4 + 3) = param_8;
  *(undefined2 *)((int)local_4 + 0xe) = 0;
  local_4[8] = uStackX_8;
  local_4[4] = uStackX_4;
  local_4[5] = 0;
  local_4[6] = 0;
  if (param_2 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + param_2 * 4);
  }
  local_4[7] = uVar3;
  {
    undefined4 *record = local_4;
    *(ushort *)((int)record + 0xe) = *(ushort *)((int)record + 0xe) & 0xfffe;
    if ((Callback *)record[8] != 0) {
      ((Callback *)record[8])->method_0c(0);
    }
  }
  {
    undefined4 *record = local_4;
    *(ushort *)((int)record + 0xe) = *(ushort *)((int)record + 0xe) & 0xfffd;
    if ((Callback *)record[8] != 0) {
      ((Callback *)record[8])->method_10(0);
    }
  }
  first_value = uStackX_0;
  {
    undefined4 *record2 = local_4;
    record2[9] = param_3;
    record2[10] = param_3;
    *record2 = first_value;
  }
  if ((Callback *)local_4[8] != 0) {
    ((Callback *)local_4[8])->method_18();
  }
  if (iStackX_c == 0) {
    uVar4 = *(uint *)(param_1 + 0x14);
  }
  else {
    iVar1 = FUN_00014a40(iStackX_c);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        iVar2 = (int)(FUN_00014d64(iStackX_c,&DAT_002d8ad4));
        if (iVar2 == 0) {
          iVar2 = (int)(FUN_00014d64(iStackX_c,&DAT_002d8ad8));
          if (iVar2 != 0) {
            *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x1000;
          }
        }
        else {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x800;
        }
        iVar2 = (int)(FUN_00014d64(iStackX_c,DAT_002d8adc));
        if (iVar2 == 0) {
          iVar2 = (int)(FUN_00014d64(iStackX_c,DAT_002d8ae8));
          if (iVar2 == 0) {
            iVar2 = (int)(FUN_00014d64(iStackX_c,DAT_002d8af0));
            if (iVar2 != 0) {
              *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x8000;
            }
          }
          else {
            *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x4000;
          }
        }
        else {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x2000;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 2);
    }
    uVar4 = *(uint *)(param_1 + 0x14);
  }
  if (uVar4 < *(uint *)(param_1 + 0x18)) {
    *(uint *)(param_1 + 0x14) = uVar4 + 1;
    *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar4 * 4) = local_4;
  }
  else {
    FUN_00107130((void *)(param_1 + 0x10),&local_4,0);
  }
  *(undefined1 *)(param_1 + 0x1c) = 1;
  return local_4;
}
// Best near miss: 84 differing words remain. The C++ virtual table layout matches all three retail
// jalr slots, and scoped record aliases align both early flag-clear/callback sequences. Remaining
// differences begin in the final record stores and continue through the configuration flag loop.
// Tried C indirect calls, several virtual-slot layouts, direct and scoped virtual calls, record
// aliases, register-pointer variants, and reordered record stores; 84 was the best result.
// near miss from lane km4 (unreviewed)
