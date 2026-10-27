/* HSTMATCH module=hstp_trans_main.prx start=0x00054e7c end=0x00054ea4 symbol=__ct__10C_00054e7cFRC10C_00054e7c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/vec4_copy_0004c644.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Out-of-line memberwise copy constructor of the 16-byte-aligned Vec4, emitted by MWCC after FUN_0004c078 which
   calls it. Names provisional. */

struct C_00054e7c {
    float x, y, z, w;
    C_00054e7c(const C_00054e7c &v);
} __attribute__((aligned(16)));

C_00054e7c::C_00054e7c(const C_00054e7c &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
