/* HSTMATCH module=hstp_trans_main.prx start=0x00099c98 end=0x00099ed0 symbol=FUN_00099c98 lang=c++ */
/* Clone of src/eboot/assign_00097b2c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Implicit (memberwise) copy assignment of a 0x9c-byte record: the class is non-POD (user-declared
   constructor), so MWCC copies member by member and copies each array as an aligned block (count-down
   loops, two elements per iteration when the count is even). The three shorts at +0x8a are a small struct
   (all loads before the stores). Retail is the out-of-line operator=; the wrapper below inlines it to the
   same code. Field names are offsets; types follow the load widths (lb = char, lbu = unsigned char). */
struct V3s_00099c98 { short x, y, z; };
struct S_00099c98 {
    short a00[6];
    unsigned char b0c, b0d, b0e;
    char s0f[16];
    unsigned short h20, h22;
    unsigned char b24;
    char s25[6];
    unsigned char b2b, b2c;
    char s2d[16];
    short h3e, h40;
    unsigned char b42, b43;
    float f44, f48, f4c;
    short h50, h52;
    char s54[16];
    unsigned char b64, b65, b66, b67;
    char s68[16];
    short h78, h7a;
    unsigned char b7c;
    char s7d[12];
    V3s_00099c98 v8a;
    short a90[5];
    S_00099c98();
};
extern "C" S_00099c98 *FUN_00099c98(S_00099c98 *a, const S_00099c98 *b)
{
    *a = *b;
    return a;
}
