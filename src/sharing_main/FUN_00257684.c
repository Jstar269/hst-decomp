/* HSTMATCH module=hstp_trans_main.prx start=0x00257684 end=0x002577a4 symbol=FUN_00257684 lang=c99 */
/* Clone of src/eboot/FUN_0024747c.c (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V4 { float x, y, z, w; };
extern void FUN_002577a4(char *self, int on);
extern void FUN_00055b64(void *dst, void *src);

void FUN_00257684(char *self)
{
  FUN_002577a4(self, 1);
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
  FUN_00055b64(self + 0xe0, self + 0xa0);
  FUN_00055b64(*(void **)(self + 0x444), self + 0xa0);
  *(char *)(self + 0x465) = 1;
  *(int *)(self + 0x4e0) = 0;
  *(char *)(self + 0x4e8) = 0;
  *(char *)(self + 0x4bc) = 0;
}
