/* HSTMATCH module=hstp_trans_main.prx start=0x0029a85c end=0x0029a8ac symbol=FUN_0029a85c lang=c99 */
/* Clone of src/eboot/validate_handle_002890c0.c (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern undefined DAT_003eaad8;
extern int FUN_001c0010(void *, int);

typedef struct Obj { char pad[0x4c]; int idx; } Obj;

int FUN_0029a85c(Obj *o)
{
  if (o->idx >= 0) {
    if (FUN_001c0010(&DAT_003eaad8, o->idx) == 0) {
      o->idx = -1;
    }
  }
  return o->idx >= 0;
}
