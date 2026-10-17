/* HSTMATCH module=hstp_trans_main.prx start=0x001a6794 end=0x001a6900 symbol=FUN_001a6794 lang=c++ */
/* Clone of src/eboot/obj_setup_vcalls_00199e0c.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj58 { virtual void d0(); virtual void v1(int); };
struct Obj54 { virtual void d0(); virtual void v1(int); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void v10();
  char pad[0x118]; short a; short b; };
struct Obj { char pad[0x54]; Obj54 *o54; Obj58 *o58; int f5c; };

extern int DAT_003751d4;
extern int DAT_003eaae0;
extern char DAT_00389258[];
extern char DAT_00389264[];
extern char DAT_00389274[];
extern "C" void FUN_0001dc34(int, int);
extern "C" void FUN_0001de88(int, int, int);
extern "C" void FUN_00105470(void *, int);
extern "C" void *FUN_00108124(Obj58 *, char *);
extern "C" void FUN_00111aa4(Obj54 *, int, int);
extern "C" void FUN_001a6900(Obj *);

extern "C" void FUN_001a6794(Obj *p)
{
  p->f5c = 0;
  FUN_0001dc34(DAT_003751d4, 0x2000);
  FUN_0001de88(DAT_003751d4, 0x2000, 1);
  p->o58->v1(0);
  FUN_00105470(FUN_00108124(p->o58, DAT_00389258), 0);
  FUN_00105470(FUN_00108124(p->o58, DAT_00389264), 1);
  FUN_00105470(FUN_00108124(p->o58, DAT_00389274), 1);
  if (DAT_003eaae0 - 2U < 2) {
    FUN_00105470(FUN_00108124(p->o58, DAT_00389258), 1);
    FUN_00105470(FUN_00108124(p->o58, DAT_00389264), 0);
    FUN_00105470(FUN_00108124(p->o58, DAT_00389274), 1);
  }
  p->o54->v1(0);
  p->o54->v10();
  Obj54 *q = p->o54;
  q->a = -12;
  q->b = 0;
  FUN_00111aa4(p->o54, 0, 2);
  FUN_001a6900(p);
}
