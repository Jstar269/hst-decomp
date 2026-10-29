/* HSTMATCH module=EBOOT.BIN start=0x002afce0 end=0x002afd2c symbol=FUN_002afce0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct for the global (+0xc int, +0x52 byte), global read into a local for the two stores and re-read for the call, float first argument 203000.0f (0x48463e00); readability pass; exact match verified; names and types await human review. */
typedef struct GlobalObj { char pad0[0xc]; int unk0c; char pad1[0x42]; unsigned char unk52; } GlobalObj;
extern GlobalObj *DAT_00331b84;
extern int DAT_0034b5d8;
extern void FUN_00063478(float, GlobalObj *);
extern void FUN_002b066c(int);

/* Unless keep is set, clear the global object's state and re-arm it; then pass the second global on. */
void FUN_002afce0(int keep)
{
  if (keep == 0) {
    GlobalObj *o = DAT_00331b84;
    o->unk0c = 0;
    o->unk52 = 0;
    FUN_00063478(203000.0f, DAT_00331b84);
  }
  FUN_002b066c(DAT_0034b5d8);
}
