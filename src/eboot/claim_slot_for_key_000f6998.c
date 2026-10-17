/* HSTMATCH module=EBOOT.BIN start=0x000f6998 end=0x000f6b0c symbol=FUN_000f6998 lang=c99 */
/* Clone of src/sharing_main/claim_slot_for_key_000fc08c.c (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Scans the 32 slots (64-byte stride, first state byte at +0x30) for an active entry whose four-float key equals the
   argument key and returns if one exists; otherwise claims the first free slot (state 0), stores the id as
   remainder/quotient of a per-manager divisor, the key, the truncated timer twice and a call result.
   Matching idiom: plain C (lang=c99), where `int same = a == b; if (same) same = ...;` keeps the flag unmasked
   (C++ adds andi 0xff per step). Names provisional. */
extern int FUN_0001342c();
typedef struct Slot_fc08c {
    unsigned char state;
    int a;
    int b;
    char pad[0x20 - 0x0c];
    float x, y, z, w;
    int c, d, e;
    char pad2[0x40 - 0x3c];
} Slot_fc08c;
typedef struct Mgr_fc08c {
    char pad0[0x30];
    Slot_fc08c slots[32];
    char pad1[0x83c - 0x830];
    float timer;
    char pad2[0x85c - 0x840];
    int div;
} Mgr_fc08c;
void FUN_000f6998(Mgr_fc08c *self, int id, const float *key)
{
    int freeIdx = -1;
    unsigned i;
    int row, col, t;
    for (i = 0; i < 32; i++) {
        if (self->slots[i].state == 1) {
            int same = key[0] == self->slots[i].x;
            if (same) same = key[1] == self->slots[i].y;
            if (same) same = key[2] == self->slots[i].z;
            if (same) same = key[3] == self->slots[i].w;
            if (same) return;
        } else if (freeIdx < 0 && self->slots[i].state == 0) {
            freeIdx = i;
        }
    }
    row = id / self->div;
    col = id % self->div;
    if (freeIdx >= 0) {
        self->slots[freeIdx].state = 1;
        self->slots[freeIdx].a = col;
        self->slots[freeIdx].b = row;
        self->slots[freeIdx].x = key[0];
        self->slots[freeIdx].y = key[1];
        self->slots[freeIdx].z = key[2];
        self->slots[freeIdx].w = key[3];
        t = (int)self->timer;
        self->slots[freeIdx].c = t;
        self->slots[freeIdx].d = t;
        self->slots[freeIdx].e = FUN_0001342c();
    }
}
