/* HSTMATCH module=hstp_trans_main.prx start=0x001d1ef0 end=0x001d1f38 symbol=FUN_001d1ef0 lang=c++ */
/* Clone of src/eboot/FUN_001c3b64.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };

/* Owner of a polymorphic object at 0x58. */
struct Owner {
  char pad00[0x58];
  VC_0 *obj58;
};

/* Delete the owned object and clear the pointer. */
extern "C" void FUN_001d1ef0(Owner *self)
{
  VC_0 *obj;
  
  obj = self->obj58;
  if (obj != (VC_0 *)0x0) {
    delete obj;
    self->obj58 = 0;
  }
}
