/* HSTMATCH module=hstp_trans_main.prx start=0x00241714 end=0x0024175c symbol=FUN_00241714 lang=c++ */
/* Clone of src/eboot/guarded_virtual_dispatch_00231614.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Target { virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void invoke(); };
struct Entry { Target *target; int guard; };
extern Entry *DAT_003f398c;
extern "C" void FUN_00241714(void)
{
  if (DAT_003f398c != 0) {
    switch (DAT_003f398c->guard) {
    case 0:
      DAT_003f398c->target->invoke();
      break;
    default:
      break;
    }
  }
}
