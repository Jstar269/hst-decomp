/* HSTMATCH module=hstp_trans_main.prx start=0x001dc3f0 end=0x001dc444 symbol=FUN_001dc3f0 lang=c++ */
/* Clone of src/eboot/FUN_001cdd14_001cdd14.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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


struct ResultMethods {
  virtual ~ResultMethods();
  virtual int F0();
  virtual int F1();
  virtual int F2();
  virtual int F3();
  virtual int F4();
  virtual int F5();
  virtual int F6();
  virtual int F7();
  virtual int F8();
  virtual int F9();
  virtual int F10();
};

extern "C" bool FUN_001dc3f0(ResultMethods *param_1)
{
  int iVar2;
  bool bVar1;

  iVar2 = param_1->F10();
  bVar1 = iVar2 == 2;
  if (!bVar1) {
    iVar2 = param_1->F10();
    bVar1 = iVar2 == 3;
  }
  return bVar1;
}
