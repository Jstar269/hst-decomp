/* HSTMATCH module=hstp_trans_main.prx start=0x00101334 end=0x001013cc symbol=FUN_00101334 lang=c++ */
/* Clone of src/eboot/delete_members_000fbbf8.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: member-array delete loop with the index declared first and self->m[i] access (typed struct, virtual deleting destructors); exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct Obj { char pad[0x3c]; VC_1 *one; VC_0 *m[6]; };

extern "C" void FUN_00101334(Obj *self)
{
  int i;
  VC_0 *p;
  VC_1 *r;

  i = 0;
  do {
    p = self->m[i];
    if (p != 0) {
      delete p;
      self->m[i] = 0;
    }
    i++;
  } while (i < 6);
  r = self->one;
  if (r != 0) {
    delete r;
    self->one = 0;
  }
}
