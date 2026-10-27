/* HSTMATCH module=EBOOT.BIN start=0x001c6908 end=0x001c69d8 symbol=FUN_001c6908 lang=c++ helpers=FUN_001c5018@0x001c5018-0x001c5044 */
/* Hand-written reconstruction (port of src/sharing_main/npc_slot_set_001d4d00.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Store an npc pointer at slot idx of the vector at +0x4c after FUN_001c67e8(self, npc): grow it to idx + 1
   entries first (inline resize: out-of-line fill FUN_001ce598 with a zero int and an empty tag, or shrink),
   and log "warning! same npc index %d" when the slot is already taken. */
extern "C" {
static void FUN_001c5018(...) { }
}
struct Tag {};
struct PtrVec;
extern "C" void FUN_001ce598(PtrVec *v, unsigned n, const int &x, Tag);
struct PtrVec {
    int *data;
    unsigned size;
    unsigned cap;
    void resize(unsigned n, int x)
    {
        if (size < n) FUN_001ce598(this, n - size, x, Tag());
        else if (n < size) size -= size - n;
    }
};
struct Self {
    char pad[0x4c];
    PtrVec npcs;
};
extern "C" void FUN_001c67e8(Self *, int);
extern char DAT_002ea68c[];

extern "C" void FUN_001c6908(Self *self, unsigned idx, int npc)
{
    FUN_001c67e8(self, npc);
    if (idx >= self->npcs.size) self->npcs.resize(idx + 1, 0);
    if (self->npcs.data[idx] != 0) FUN_001c5018(DAT_002ea68c, idx);
    self->npcs.data[idx] = npc;
}
