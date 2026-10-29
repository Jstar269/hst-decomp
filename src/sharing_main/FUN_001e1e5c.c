/* HSTMATCH module=hstp_trans_main.prx start=0x001e1e5c end=0x001e1e80 symbol=FUN_001e1e5c lang=c99 */
/* Clone of src/eboot/FUN_001d4058.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct Quad16 {
  char pad0[4];
  short unk4;  /* 0x4 */
  short unk6;  /* 0x6 */
  short unk8;  /* 0x8 */
  short unka;  /* 0xa */
} Quad16;

/* Copy the four halfwords at +4..+0xb from src to dst. */
void FUN_001e1e5c(Quad16 *dst,Quad16 *src)
{
  dst->unk4 = src->unk4;
  dst->unk6 = src->unk6;
  dst->unk8 = src->unk8;
  dst->unka = src->unka;
  return;
}
