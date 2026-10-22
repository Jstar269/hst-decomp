/* HSTMATCH module=EBOOT.BIN start=0x00100de8 end=0x00100eb8 symbol=FUN_00100de8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Tag {};
struct Vec { int f0; int *data; unsigned size; unsigned cap; };

extern "C" void FUN_00107034(int **dataField, unsigned n);
extern "C" void FUN_00106ff0(int **dataField, int *value, Tag tag);

extern "C" void FUN_00100de8(Vec *dst, const Vec *src)
{
  if (dst->size == 0) {
    if (src->size > dst->cap) {
      FUN_00107034(&dst->data, src->size);
    }
  }
  for (int i = 0; i < (int)src->size; i++) {
    int v = src->data[i];
    if (dst->size < dst->cap) {
      ++dst->size;
      dst->data[dst->size - 1] = v;
    } else {
      FUN_00106ff0(&dst->data, &v, Tag());
    }
  }
}
