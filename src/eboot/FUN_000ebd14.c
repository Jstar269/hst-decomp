/* HSTMATCH module=EBOOT.BIN start=0x000ebd14 end=0x000ebdfc symbol=FUN_000ebd14 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4, float variant) corrected by hand: the int field and the 1.0f constants typed; readability pass; exact match verified; names and types await human review. */
extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern float DAT_002bc420;
extern float DAT_002bc424;
extern float DAT_002bc428;
extern float DAT_002bc42c;
extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;

/* Initialises a record: sixteen floats copied from constants, then a short run of defaults. */
typedef struct ConstRec {
  float init[16]; /* 0x00 copied from the constant table */
  float unk40;    /* 0x40 */
  int unk44;      /* 0x44 */
  float unk48;    /* 0x48 */
  float unk4c;    /* 0x4c */
  float unk50;    /* 0x50 */
  float unk54;    /* 0x54 */
} ConstRec;

ConstRec * FUN_000ebd14(ConstRec *rec)
{
  rec->init[0] = DAT_002bc410;
  rec->init[1] = DAT_002bc414;
  rec->init[2] = DAT_002bc418;
  rec->init[3] = DAT_002bc41c;
  rec->init[4] = DAT_002bc420;
  rec->init[5] = DAT_002bc424;
  rec->init[6] = DAT_002bc428;
  rec->init[7] = DAT_002bc42c;
  rec->init[8] = DAT_002bc430;
  rec->init[9] = DAT_002bc434;
  rec->init[10] = DAT_002bc438;
  rec->init[11] = DAT_002bc43c;
  rec->init[12] = DAT_002bc440;
  rec->init[13] = DAT_002bc444;
  rec->init[14] = DAT_002bc448;
  rec->init[15] = DAT_002bc44c;
  rec->unk40 = 0;
  rec->unk44 = 6;
  rec->unk48 = 1.0f;
  rec->unk4c = 0;
  rec->unk50 = 0;
  rec->unk54 = 1.0f;
  return rec;
}
