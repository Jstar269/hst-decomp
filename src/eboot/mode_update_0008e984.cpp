/* HSTMATCH module=EBOOT.BIN start=0x0008e984 end=0x0008ea50 symbol=FUN_0008e984 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Buffer { int unused; int value; };
extern "C" void FUN_00091080(void *, int, Tag);
extern "C" void FUN_0008e984(char *self, int mode)
{
  if (*(int *)(self + 0x22c) == mode) return;
  *(int *)(self + 0x22c) = mode;
  if (mode == 4) return;
  if (mode == 3) return;
  if (mode == 2) return;
  if (mode != 1) {
    if (mode == 0) return;
    return;
  }
  *(int *)(self + 0x264) = 0;
  *(int *)(self + 0x230) = -1;
  *(int *)(self + 0x234) = -1;
  *(int *)(self + 0x238) = 3;
  *(int *)(self + 0x23c) = 13;
  *(char *)(self + 0x240) = 0;
  *(int *)(self + 0x244) = 0x3f800000;
  *(int *)(self + 0x248) = 0;
  *(int *)(self + 0x268) = 0;
  *(char *)(self + 0x284) = 0;
  *(int *)(self + 0x288) = 0;
  *(int *)(self + 4) = 3;
  *(int *)(self + 0x1d4) = 0;
  FUN_00091080(self + 0x26c, *(int *)(self + 0x270), Tag());
  Buffer *second = (Buffer *)(self + 0x278);
  FUN_00091080(second, second->value, Tag());
}







