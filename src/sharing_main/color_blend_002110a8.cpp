/* HSTMATCH module=hstp_trans_main.prx start=0x002110a8 end=0x00211238 symbol=FUN_002110a8 lang=c++ */
/* Clone of src/eboot/color_blend_002028d8.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* A phase value f10 is scaled by 512/pi into an integer blend factor k (double multiply, truncated by __fixdfsi) and by 2/pi into a float blend factor s (double divide by pi/2, truncated to float); k blends three colour bytes from 0xec.. towards 0xe8.. into 0xf0.., s blends two float pairs, the second result goes to every item whose state is 6. Item array length is a guess (only count items are walked). */
struct Item {
    int state;
    float value;
    int pad[2];
};
struct Obj {
    char pad0[0x10];
    float f10;
    int count;
    char pad18[8];
    Item items[12];
    char pad_e0[8];
    unsigned char c0[3];
    unsigned char padeb;
    unsigned char c1[3];
    unsigned char pad_ef;
    unsigned char out[3];
    char pad_f3[0x380 - 0xf3];
    float f380;
    float f384;
    float f388;
    char pad_38c[0x4dc - 0x38c];
    float f4dc;
    float f4e0;
};
extern "C" void FUN_002110a8(Obj *o)
{
    float t = o->f10;
    int k = (int)(162.97466172610083 * t);
    float s = (float)(t / 1.5707963267948966);
    o->out[0] = o->c1[0] + k * (o->c0[0] - o->c1[0]) / 256;
    o->out[1] = o->c1[1] + k * (o->c0[1] - o->c1[1]) / 256;
    o->out[2] = o->c1[2] + k * (o->c0[2] - o->c1[2]) / 256;
    o->f388 = o->f384 + s * (o->f380 - o->f384);
    float g = o->f4e0 + s * (o->f4dc - o->f4e0);
    for (int i = 0; i < o->count; i++) {
        if (o->items[i].state == 6)
            o->items[i].value = g;
    }
}
