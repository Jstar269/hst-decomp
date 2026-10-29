/* HSTMATCH module=EBOOT.BIN start=0x0024747c end=0x0024759c symbol=FUN_0024747c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V4 { float x, y, z, w; };
extern void FUN_0024759c(char *self, int on);
extern void FUN_00055044(void *dst, void *src);

void FUN_0024747c(char *self)
{
  FUN_0024759c(self, 1);
  *(char *)(self + 0x464) = 1;
  *(float *)(self + 0x40) = *(float *)(self + 0x50);
  *(float *)(self + 0x44) = *(float *)(self + 0x54);
  *(float *)(self + 0x48) = *(float *)(self + 0x58);
  *(float *)(self + 0x4c) = *(float *)(self + 0x5c);
  *(int *)(self + 0x460) = 0;
  *(struct V4 *)(self + 0xa0) = *(struct V4 *)(self + 0x60);
  *(struct V4 *)(self + 0xb0) = *(struct V4 *)(self + 0x70);
  *(struct V4 *)(self + 0xc0) = *(struct V4 *)(self + 0x80);
  *(struct V4 *)(self + 0xd0) = *(struct V4 *)(self + 0x90);
  *(float *)(self + 0xd0) = *(float *)(self + 0x40);
  *(float *)(self + 0xd4) = *(float *)(self + 0x44);
  *(float *)(self + 0xd8) = *(float *)(self + 0x48);
  *(float *)(self + 0xdc) = *(float *)(self + 0x4c);
  FUN_00055044(self + 0xe0, self + 0xa0);
  FUN_00055044(*(void **)(self + 0x444), self + 0xa0);
  *(char *)(self + 0x465) = 1;
  *(int *)(self + 0x4e0) = 0;
  *(char *)(self + 0x4e8) = 0;
  *(char *)(self + 0x4bc) = 0;
}
