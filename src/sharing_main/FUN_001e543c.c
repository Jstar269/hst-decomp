/* HSTMATCH module=hstp_trans_main.prx start=0x001e543c end=0x001e544c symbol=FUN_001e543c lang=c99 */
/* Clone of src/eboot/FUN_001d7690.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct OffsetObj {
  char pad00[0x24];
  int unk24;  /* 0x24 */
  int unk28;  /* 0x28 */
} OffsetObj;

/* unk24 = unk28 + delta */
void FUN_001e543c(OffsetObj *self,int delta)
{
  self->unk24 = self->unk28 + delta;
}
