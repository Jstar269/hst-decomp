/* HSTMATCH module=hstp_trans_main.prx start=0x001066f0 end=0x001067c0 symbol=FUN_001066f0 lang=c++ */
/* Clone of src/eboot/range_append_00100de8.cpp (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Tag {};
struct Vec { int f0; int *data; unsigned size; unsigned cap; };

extern "C" void FUN_0010cdf4(int **dataField, unsigned n);
extern "C" void FUN_0010cdb0(int **dataField, int *value, Tag tag);

extern "C" void FUN_001066f0(Vec *dst, const Vec *src)
{
  if (dst->size == 0) {
    if (src->size > dst->cap) {
      FUN_0010cdf4(&dst->data, src->size);
    }
  }
  for (int i = 0; i < (int)src->size; i++) {
    int v = src->data[i];
    if (dst->size < dst->cap) {
      ++dst->size;
      dst->data[dst->size - 1] = v;
    } else {
      FUN_0010cdb0(&dst->data, &v, Tag());
    }
  }
}
