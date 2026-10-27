/* HSTMATCH module=hstp_trans_main.prx start=0x0029f3c0 end=0x0029f4e4 symbol=FUN_0029f3c0 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/initialize_context_0028dbf8.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
extern undefined DAT_003b3080;
extern undefined * DAT_003e1a08;
extern char DAT_003a7e58[];
extern char DAT_003a7e6c[];
extern undefined4 DAT_003b3e6c;
extern undefined4 DAT_003b7ebc;
extern int FUN_00000bcc(int);
extern int FUN_00010184(int,int);
extern void FUN_000104e0(int);
extern void FUN_0001bb2c(void *,unsigned int,unsigned int);
extern void FUN_0001c684(void *,int,void *);
extern void FUN_0001c73c(void *);
extern int FUN_0001c848();
extern undefined4 FUN_0001c8a0();
extern undefined4 * FUN_0001ec44();
extern void FUN_00264244();
extern void FUN_00268744(int);
extern int * FUN_0029f4e4(int,char *);
}

struct Finalizer {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
  virtual void slot4();
  virtual void slot5();
  virtual void finalize();
};

extern "C" undefined4 * FUN_0029f3c0(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b3080);
  param_1[0xf] = 0;
  iVar1 = FUN_00010184(0x40,0x300000);
  FUN_0001bb2c(&DAT_003b3e6c,iVar1,0x300000);
  FUN_0001c684(&DAT_003b7ebc,1,DAT_003a7e58);
  *(undefined4 *)(*(int *)(DAT_003e1a08 + 0x40) + 0x5c) = 1;
  iVar2 = FUN_00000bcc(0x1bc0);
  if (iVar2 != 0) iVar2 = (int)FUN_0029f4e4(iVar2,DAT_003a7e6c);
  param_1[0xf] = iVar2;
  FUN_00264244();
  FUN_0001c73c(&DAT_003b7ebc);
  uVar3 = FUN_0001c848();
  uVar4 = FUN_0001c8a0();
  FUN_0001bb2c(&DAT_003b3e6c,uVar3,uVar4);
  if (iVar1 != 0) {
    FUN_000104e0(iVar1);
  }
  uVar3 = param_1[0xf];
  FUN_00268744(uVar3);
  ((Finalizer *)param_1[0xf])->finalize();
  return param_1;
}
