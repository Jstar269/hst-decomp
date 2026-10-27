/* HSTMATCH module=hstp_trans_main.prx start=0x002143bc end=0x00214428 symbol=FUN_002143bc lang=c++ helpers=FUN_00214254@0x00214254-0x00214280 */
/* Hand-written reconstruction from the disassembly; same-file static log stub FUN_00214254 defined in front and placed by helpers=; matching idiom: the pending-state store is written in both arms of `state >= 2` (one store before the test is 23 words off); exact match verified; names and types await human review. */
/* Request a new player "active" state: states 0/1 take effect at once (logged as "R:player active %d->%d"),
   others wait for the next update (0x00214428 applies them with the same block). Names provisional. */
extern char DAT_003977b0[];   /* "R:player active %d\x81\xa8%d\n" */

extern "C" {
static void FUN_00214254(...)
{
}
}

struct Player {
    char pad[0x4c];
    int active;
    int nextActive;

    void ApplyNext()
    {
        if (nextActive != 0) {
            FUN_00214254(DAT_003977b0, active, nextActive);
            active = nextActive;
            nextActive = 0;
        }
    }
};

extern "C" void FUN_002143bc(Player *self, int state)
{
    if (state != self->active) {
        if (state >= 2) {
            self->nextActive = state;
        } else {
            self->nextActive = state;
            self->ApplyNext();
        }
    } else {
        if (self->nextActive != 0) {
            self->nextActive = 0;
        }
    }
}
