/* HSTMATCH module=hstp_trans_main.prx start=0x0026db2c end=0x0026db70 symbol=FUN_0026db2c lang=c++ */
/* Clone of src/eboot/FUN_0025d580.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00108f54(...);
extern void FUN_0026db70(...);
}
struct Widget { virtual void d0(); virtual void d1(); virtual void m(int); };
struct Holder {
  char pad00[0x68];
  Widget *widget;  /* 0x68 */
};

extern "C" void FUN_0026db2c(Holder *self)
{
  FUN_00108f54(self,1);
  self->widget->m(0);
  FUN_0026db70(self);
}
