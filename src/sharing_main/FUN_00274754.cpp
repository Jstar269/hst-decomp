/* HSTMATCH module=hstp_trans_main.prx start=0x00274754 end=0x002747f8 symbol=FUN_00274754 lang=c++ */
/* Clone of src/eboot/FUN_002638d8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_003a6b38;
extern undefined DAT_003b2d94;
extern char DAT_003a6b3c[];
extern int FUN_00108124(...);
extern int FUN_00109304(...);
extern undefined4 * FUN_00268090(...);
extern int * FUN_0026ec7c(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_00274754(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00268090();
  *param_1 = (int)&DAT_003b2d94;
  FUN_0026ec7c(param_1 + 0x618);
  uVar1 = FUN_00109304(param_1,&DAT_003a6b38,0);
  iVar2 = FUN_00108124(uVar1,DAT_003a6b3c);
  param_1[0x791] = iVar2;
  ((VC_0 *)(param_1))->m();
  *(undefined1 *)(param_1[400] + 0x616) = 0;
  *(undefined1 *)(param_1[400] + 0x736) = 0;
  *(undefined1 *)(param_1[400] + 0x856) = 0;
  *(undefined1 *)(param_1[400] + 0x617) = 0;
  *(undefined1 *)(param_1[400] + 0x737) = 0;
  *(undefined1 *)(param_1[400] + 0x857) = 0;
  return param_1;
}
