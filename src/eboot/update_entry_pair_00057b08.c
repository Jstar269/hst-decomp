/* HSTMATCH module=EBOOT.BIN start=0x00057b08 end=0x00057b58 symbol=FUN_00057b08 lang=c99 */
/* Clone of src/sharing_main/update_entry_pair_0005875c.c (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Runs the per-entry update FUN_00058748 on entries 0 and 1 (flag 1) with the two given values, then clears
   the flag byte at +0xec (prototype of FUN_00058748 as in update_entry_range_000589c0.c). */
typedef struct {
    char pad[0xec];
    unsigned char flag_ec;
} Obj;

extern void FUN_00058748(Obj *self, int idx, int flag, float value);

void FUN_00057b08(Obj *self, float a, float b)
{
    FUN_00058748(self, 0, 1, a);
    FUN_00058748(self, 1, 1, b);
    self->flag_ec = 0;
}
