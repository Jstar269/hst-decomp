/* HSTMATCH module=hstp_trans_main.prx start=0x0017454c end=0x00174574 symbol=FUN_0017454c lang=c99 */
/* Clone of src/eboot/FUN_00168388.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

typedef struct Params {
  int unk00;        /* 0x00 */
  float unk04;      /* 0x04 */
  int unk08;        /* 0x08 */
  float unk0c;      /* 0x0c */
  float unk10;      /* 0x10 */
} Params;

/* Sets the five parameter words to their defaults (0, 1.0, 0, 0.5, 2.0). */
Params * FUN_0017454c(Params *params)
{
  params->unk00 = 0;
  params->unk04 = 1.0f;
  params->unk08 = 0;
  params->unk0c = 0.5f;
  params->unk10 = 2.0f;
  return params;
}
