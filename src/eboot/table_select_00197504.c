/* HSTMATCH module=EBOOT.BIN start=0x00197504 end=0x001975d4 symbol=FUN_00197504 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float DAT_002c28e0[][4];
extern float DAT_002c28e4[][4];
extern float DAT_002c28e8[][4];
extern float DAT_002c29b0[][4];
extern float DAT_002c29b4[][4];
extern float DAT_002c29b8[][4];
struct Obj {
    int id;
    char pad04[0xc];
    float col[4];
    float base[4];
    float out[4];
    char pad40[0x48];
    unsigned char alt;
};
extern void FUN_00043004(int, float *);
void FUN_00197504(struct Obj *o, unsigned int param_2)
{
    int idx = param_2 % 0xd;
    float c;
    float b;
    float a;
    float d;

    if (o->alt != 0) {
        a = DAT_002c28e0[idx][0];
        b = DAT_002c28e4[idx][0];
        c = DAT_002c28e8[idx][0];
    } else {
        a = DAT_002c29b0[idx][0];
        b = DAT_002c29b4[idx][0];
        c = DAT_002c29b8[idx][0];
    }
    d = o->col[3];
    o->col[0] = a;
    o->col[1] = b;
    o->col[2] = c;
    o->col[3] = d;
    o->out[0] = a * o->base[0];
    o->out[1] = b * o->base[1];
    o->out[2] = c * o->base[2];
    o->out[3] = d * o->base[3];
    FUN_00043004(o->id, o->out);
}
