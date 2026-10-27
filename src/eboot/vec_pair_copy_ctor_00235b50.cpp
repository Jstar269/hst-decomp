/* HSTMATCH module=EBOOT.BIN start=0x00235b50 end=0x00235bd0 symbol=FUN_00235b50 lang=c++ */
/* Clone of src/sharing_main/vec_pair_copy_ctor_00245c7c.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (copy-initialisation of two vectors of shorts through the range-init helper FUN_00236750, modelled on src/sharing_main/vec6_copy_ctor_000dec80.cpp; the tag argument read from a never-written slot `lb a3,28(sp)` / `lb a3,24(sp)` is a tag type deriving from an empty class, fwd_tag : in_tag); exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Vec_00235b50;
extern "C" void FUN_00236750(Vec_00235b50 *, short *, short *, fwd_tag);
struct Vec_00235b50 {
  short *data;
  int size;
  int cap;
  void CopyInit(const Vec_00235b50 &o)
  {
    data = 0;
    size = 0;
    cap = 0;
    FUN_00236750(this, o.data, o.data + o.size, fwd_tag());
  }
};
struct Pair_00235b50 { Vec_00235b50 a; Vec_00235b50 b; };

extern "C" Pair_00235b50 *FUN_00235b50(Pair_00235b50 *p, const Pair_00235b50 *o)
{
  p->a.CopyInit(o->a);
  p->b.CopyInit(o->b);
  return p;
}
