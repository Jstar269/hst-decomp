/* HSTMATCH module=EBOOT.BIN start=0x0004c5cc end=0x0004c644 symbol=__ct__10C_0004c5ccFRC10C_0004c5cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line copy constructor of the collision triangle key (three Vec4 vertices, type, id; 64 bytes with
   padding), emitted by MWCC right after FUN_0004be54 which calls it; the Vec4 copies are inlined. Names provisional. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

struct C_0004c5cc {
    Vec4 v[3];
    int type;
    int id;
    C_0004c5cc(const C_0004c5cc &k);
};

C_0004c5cc::C_0004c5cc(const C_0004c5cc &k)
{
    v[0] = k.v[0];
    v[1] = k.v[1];
    v[2] = k.v[2];
    type = k.type;
    id = k.id;
}
