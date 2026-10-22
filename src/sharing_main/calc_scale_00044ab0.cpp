/* HSTMATCH module=hstp_trans_main.prx start=0x00044ab0 end=0x00044b18 symbol=FUN_00044ab0 lang=c++ */
/* Clone of src/eboot/calc_scale_0004490c.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Asks FUN_0004401c for a hit and turns it into a scale factor: zero when there is no hit, the
   byte of the configuration at +0x1c converted to float when that byte is set, otherwise the
   float the helper wrote at +4 of its third result multiplied by the configuration float at +0x10.
   Matching idiom: the "byte set" case is the fall-through, so the source tests `v != 0` first. */
typedef struct {
    int i;
    float f;
} Out;

typedef struct {
    char pad[0x10];
    float f10;
    char pad2[8];
    signed char f1c;
} Cfg;

extern "C" int FUN_0004401c(void *a, short b, Out *c, Out *d, Out *e);

extern "C" float FUN_00044ab0(void *a, short b, Cfg *c)
{
    Out o2;
    Out o3;
    Out o0;
    float r = 0.0f;
    if (FUN_0004401c(a, b, &o2, &o3, &o0) != 0) {
        signed char v = c->f1c;
        if (v != 0) {
            r = (float)v;
        } else {
            r = o3.f * c->f10;
        }
    }
    return r;
}
