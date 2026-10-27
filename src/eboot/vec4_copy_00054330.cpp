/* HSTMATCH module=EBOOT.BIN start=0x00054330 end=0x00054358 symbol=__ct__10C_00054330FRC10C_00054330 lang=c++ */
/* Hand-written reconstruction (port of src/sharing_main/vec4_copy_0004c898.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Out-of-line memberwise copy constructor of the 16-byte-aligned Vec4, emitted by MWCC after FUN_0004be54 which
   calls it. Names provisional. */

struct C_00054330 {
    float x, y, z, w;
    C_00054330(const C_00054330 &v);
} __attribute__((aligned(16)));

C_00054330::C_00054330(const C_00054330 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
