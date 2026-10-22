/* HSTMATCH module=hstp_trans_main.prx start=0x00069174 end=0x000691e4 symbol=FUN_00069174 lang=c++ */
/* Clone of src/eboot/query_levels_00067d20.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Asks the callback twice - once with (0, 255) and once with (128, 0) - and stores the answers in
   the object: the first answer goes to +0x08, +0x04 and +0x00, the second to +0x0c.
   Matching idiom: the callback only takes the three floats (the object pointer is never passed),
   so the first argument register still holds the object when the callback is entered. */
typedef struct {
    float f0;
    float f4;
    float f8;
    float f12;
} Obj;

typedef float (*Fn)(float, float, float);

extern "C" void FUN_00069174(Obj *out, Fn fn, float x)
{
    float v = fn(0.0f, 255.0f, x);
    out->f8 = v;
    out->f4 = v;
    out->f0 = v;
    out->f12 = fn(128.0f, 0.0f, x);
}
