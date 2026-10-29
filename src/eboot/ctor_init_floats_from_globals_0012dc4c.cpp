/* HSTMATCH module=EBOOT.BIN start=0x0012dc4c end=0x0012ddd0 symbol=FUN_0012dc4c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v17c) corrected by hand: the 16 copied words are float (DAT globals declared float -> lwc1/swc1, 1.0f literals), typed object with float arrays, virtual slot 7 takes a float pointer (changes the argument setup order); readability pass; exact match verified; names and types await human review. */
#include "hst/stage_obj.h"

extern "C" {
extern float DAT_002bc410, DAT_002bc414, DAT_002bc418, DAT_002bc41c;
extern float DAT_002bc430, DAT_002bc434, DAT_002bc438, DAT_002bc43c;
extern float DAT_002bc440, DAT_002bc444, DAT_002bc448, DAT_002bc44c;
extern char DAT_00308194;
extern void *DAT_0033b580;  /* the live instance, set by this constructor */
extern int * FUN_000649c0(...);
extern void * FUN_00286790(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(float *); };

extern "C" StageObj * FUN_0012dc4c(StageObj *o)
{
  FUN_00286790();
  o->vtbl = &DAT_00308194;
  o->vec70.x = DAT_002bc440; o->vec70.y = DAT_002bc444; o->vec70.z = DAT_002bc448; o->vec70.w = DAT_002bc44c;
  o->vec80.x = DAT_002bc440; o->vec80.y = DAT_002bc444; o->vec80.z = DAT_002bc448; o->vec80.w = DAT_002bc44c;
  o->vec90.x = DAT_002bc440; o->vec90.y = DAT_002bc444; o->vec90.z = DAT_002bc448; o->vec90.w = DAT_002bc44c;
  o->veca0.x = 0; o->veca0.y = 0; o->veca0.z = 1.0f; o->veca0.w = 1.0f;
  o->vecb0.x = DAT_002bc430; o->vecb0.y = DAT_002bc434; o->vecb0.z = DAT_002bc438; o->vecb0.w = DAT_002bc43c;
  o->vecc0.x = DAT_002bc410; o->vecc0.y = DAT_002bc414; o->vecc0.z = DAT_002bc418; o->vecc0.w = DAT_002bc41c;
  FUN_000649c0(o->sub);
  o->owned = 0;
  o->unke4 = 0;
  o->unke8 = 0;
  o->unkec = 0;
  o->mode = 0;
  o->unkf4 = 0;
  o->entry = 0;
  o->unk240 = 1.0f;
  DAT_0033b580 = o;
  ((VC_0 *)o)->m(&DAT_002bc440);
  return o;
}
