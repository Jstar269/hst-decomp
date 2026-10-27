/* HSTMATCH module=hstp_trans_main.prx start=0x001d4d00 end=0x001d4dd0 symbol=FUN_001d4d00 lang=c++ helpers=FUN_001d0468@0x001d0468-0x001d0494 */
/* Hand-written reconstruction from the disassembly; exact match verified; the empty variadic log stub FUN_001d0468 is defined static in front of the target (retail keeps idx*4 in a2 across its call) and placed by helpers=; names and types await human review. */
/* Store an npc pointer at slot idx of the vector at +0x4c after FUN_001d4be0(self, npc): grow it to idx + 1
   entries first (inline resize: out-of-line fill FUN_001dcc74 with a zero int and an empty tag, or shrink),
   and log "warning! same npc index %d" when the slot is already taken. */
extern "C" {
static void FUN_001d0468(...) { }
}
struct Tag {};
struct PtrVec;
extern "C" void FUN_001dcc74(PtrVec *v, unsigned n, const int &x, Tag);
struct PtrVec {
    int *data;
    unsigned size;
    unsigned cap;
    void resize(unsigned n, int x)
    {
        if (size < n) FUN_001dcc74(this, n - size, x, Tag());
        else if (n < size) size -= size - n;
    }
};
struct Self {
    char pad[0x4c];
    PtrVec npcs;
};
extern "C" void FUN_001d4be0(Self *, int);
extern char DAT_003923bc[];

extern "C" void FUN_001d4d00(Self *self, unsigned idx, int npc)
{
    FUN_001d4be0(self, npc);
    if (idx >= self->npcs.size) self->npcs.resize(idx + 1, 0);
    if (self->npcs.data[idx] != 0) FUN_001d0468(DAT_003923bc, idx);
    self->npcs.data[idx] = npc;
}
