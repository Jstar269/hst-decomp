/* HSTMATCH module=hstp_trans_main.prx start=0x0004c898 end=0x0004c8c0 symbol=__ct__10C_0004c898FRC10C_0004c898 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line memberwise copy constructor of the 16-byte-aligned Vec4, emitted by MWCC after FUN_0004c078 which
   calls it. Names provisional. */

struct C_0004c898 {
    float x, y, z, w;
    C_0004c898(const C_0004c898 &v);
} __attribute__((aligned(16)));

C_0004c898::C_0004c898(const C_0004c898 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
