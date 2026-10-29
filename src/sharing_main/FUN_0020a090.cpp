/* HSTMATCH module=hstp_trans_main.prx start=0x0020a090 end=0x0020a0f4 symbol=FUN_0020a090 lang=c++ */
/* Clone of src/eboot/FUN_001ce864.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

struct ValueObj {
  int vtable;       /* 0x00 */
  int value;        /* 0x04 */
  int unk08;        /* 0x08 */
  int unk0c;        /* 0x0c */
  int unk10;        /* 0x10 */
  int prev;         /* 0x14 */
};

/* Replace the value: notify through the first interface, remember the old value, reset the two counters, notify through the second interface. */
extern "C" void FUN_0020a090(ValueObj *self,int value)
{
  ((VC_0 *)(self))->m((int)(self->value));
  self->prev = self->value;
  self->value = value;
  self->unk08 = 0;
  self->unk0c = 0;
  ((VC_1 *)(self))->m((int)(value));
}
