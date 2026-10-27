/* HSTMATCH module=hstp_trans_main.prx start=0x00245c7c end=0x00245cfc symbol=FUN_00245c7c lang=c++ */
/* Hand-written reconstruction from the disassembly (copy-initialisation of two vectors of shorts through the range-init helper FUN_002468b4, modelled on src/sharing_main/vec6_copy_ctor_000dec80.cpp; the tag argument read from a never-written slot `lb a3,28(sp)` / `lb a3,24(sp)` is a tag type deriving from an empty class, fwd_tag : in_tag); exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Vec_00245c7c;
extern "C" void FUN_002468b4(Vec_00245c7c *, short *, short *, fwd_tag);
struct Vec_00245c7c {
  short *data;
  int size;
  int cap;
  void CopyInit(const Vec_00245c7c &o)
  {
    data = 0;
    size = 0;
    cap = 0;
    FUN_002468b4(this, o.data, o.data + o.size, fwd_tag());
  }
};
struct Pair_00245c7c { Vec_00245c7c a; Vec_00245c7c b; };

extern "C" Pair_00245c7c *FUN_00245c7c(Pair_00245c7c *p, const Pair_00245c7c *o)
{
  p->a.CopyInit(o->a);
  p->b.CopyInit(o->b);
  return p;
}
