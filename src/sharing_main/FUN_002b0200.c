/* HSTMATCH module=hstp_trans_main.prx start=0x002b0200 end=0x002b0214 symbol=FUN_002b0200 lang=c99 */
/* Clone of src/eboot/FUN_002a0df4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct QuadHolder {
  char pad[0xfc];
  u16 unkfc;   /* 0xfc */
  u16 unkfe;   /* 0xfe */
  u16 unk100;  /* 0x100 */
  u16 unk102;  /* 0x102 */
} QuadHolder;

void FUN_002b0200(QuadHolder *self,u16 a,u16 b,u16 c, u16 d)
{
  self->unkfc = a;
  self->unkfe = b;
  self->unk100 = c;
  self->unk102 = d;
}
