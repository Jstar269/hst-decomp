/* HSTMATCH module=hstp_trans_main.prx start=0x000903c8 end=0x00090494 symbol=FUN_000903c8 lang=c++ */
/* Clone of src/eboot/mode_update_0008e984.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Buffer { int unused; int value; };
extern "C" void FUN_00092d18(void *, int, Tag);
extern "C" void FUN_000903c8(char *self, int mode)
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
  FUN_00092d18(self + 0x26c, *(int *)(self + 0x270), Tag());
  Buffer *second = (Buffer *)(self + 0x278);
  FUN_00092d18(second, second->value, Tag());
}







