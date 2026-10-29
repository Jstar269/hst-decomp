/* HSTMATCH module=hstp_trans_main.prx start=0x002af710 end=0x002af744 symbol=FUN_002af710 lang=c++ */
/* Clone of src/eboot/FUN_002a038c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Object whose virtual method 12 takes one int. */
struct Target { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

struct Link {
  char pad[0x1b0];
  Target *target;   /* 0x1b0 */
};

struct Owner {
  char pad[0x3c];
  Link *link;       /* 0x3c */
};

extern "C" void FUN_002af710(Owner *self)
{
  Target *target;
  
  target = self->link->target;
  if (target != 0) {
    target->m(1);
  }
}
