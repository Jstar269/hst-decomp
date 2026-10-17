/* HSTMATCH module=EBOOT.BIN start=0x00231614 end=0x0023165c symbol=FUN_00231614 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Target { virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void invoke(); };
struct Entry { Target *target; int guard; };
extern Entry *DAT_0034a65c;
extern "C" void FUN_00231614(void)
{
  if (DAT_0034a65c != 0) {
    switch (DAT_0034a65c->guard) {
    case 0:
      DAT_0034a65c->target->invoke();
      break;
    default:
      break;
    }
  }
}
