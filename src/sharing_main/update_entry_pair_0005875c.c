/* HSTMATCH module=hstp_trans_main.prx start=0x0005875c end=0x000587ac symbol=FUN_0005875c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Runs the per-entry update FUN_000593fc on entries 0 and 1 (flag 1) with the two given values, then clears
   the flag byte at +0xec (prototype of FUN_000593fc as in update_entry_range_000589c0.c). */
typedef struct {
    char pad[0xec];
    unsigned char flag_ec;
} Obj;

extern void FUN_000593fc(Obj *self, int idx, int flag, float value);

void FUN_0005875c(Obj *self, float a, float b)
{
    FUN_000593fc(self, 0, 1, a);
    FUN_000593fc(self, 1, 1, b);
    self->flag_ec = 0;
}
