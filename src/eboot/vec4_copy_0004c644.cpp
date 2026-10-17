/* HSTMATCH module=EBOOT.BIN start=0x0004c644 end=0x0004c66c symbol=__ct__10C_0004c644FRC10C_0004c644 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line memberwise copy constructor of the 16-byte-aligned Vec4, emitted by MWCC after FUN_0004be54 which
   calls it. Names provisional. */

struct C_0004c644 {
    float x, y, z, w;
    C_0004c644(const C_0004c644 &v);
} __attribute__((aligned(16)));

C_0004c644::C_0004c644(const C_0004c644 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
