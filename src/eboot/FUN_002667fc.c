/* HSTMATCH module=EBOOT.BIN start=0x002667fc end=0x00266818 symbol=FUN_002667fc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x1f0]; int cur; int prev; } Mode1f0;

void FUN_002667fc(Mode1f0 *m, int v)
{
    if (m->cur != v) {
        m->prev = m->cur;
        m->cur = v;
    }
}
