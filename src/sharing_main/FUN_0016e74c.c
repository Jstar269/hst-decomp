/* HSTMATCH module=hstp_trans_main.prx start=0x0016e74c end=0x0016e76c symbol=FUN_0016e74c lang=c99 */
/* Clone of src/eboot/FUN_001621c0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

typedef struct OffsetObj {
  char pad0[0x16c];
  float base;       /* 0x16c */
  char pad170[0x3c4 - 0x170];
  float extra;      /* 0x3c4 added to base for modes 1 and 2 */
} OffsetObj;

float FUN_0016e74c(OffsetObj *obj,int mode)
{
  float result;
  
  result = obj->base;
  if (mode - 1U < 2) {
    result = result + obj->extra;
  }
  return result;
}
