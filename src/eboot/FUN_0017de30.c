/* HSTMATCH module=EBOOT.BIN start=0x0017de30 end=0x0017de50 symbol=FUN_0017de30 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x34]; float t; char pad2[8]; unsigned char dirty; } Timer34;

void FUN_0017de30(Timer34 *t, float dt, int mark)
{
    t->t += dt;
    if (mark) t->dirty = 1;
}
