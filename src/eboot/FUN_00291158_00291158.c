/* HSTMATCH module=EBOOT.BIN start=0x00291158 end=0x002911b8 symbol=FUN_00291158 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed the float field and used a zero-result switch case; readability pass; exact match verified; names and types await human review. */
extern int FUN_002911b8(void *,int);
extern int FUN_00291280(void *,int,int);

/* Takes a record {id, float level}; when FUN_002911b8 accepts the id, stores the level scaled by 32768. */
int FUN_00291158(void *self,int *record)
{
  int result = FUN_002911b8(self,record[0]);
  switch (result) {
  case 0:
    return 0;
  default: {
    int value = (int)(((float *)record)[1] * 32768.0f);
    return FUN_00291280(self,value,value);
  }
  }
}
