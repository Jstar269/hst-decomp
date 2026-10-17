/* HSTMATCH module=hstp_trans_main.prx start=0x00230c40 end=0x00230d2c symbol=FUN_00230c40 lang=c++ */
/* Clone of src/eboot/init_clamped_entries_002216cc.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern unsigned DAT_0039835c;
extern float DAT_00399160;
extern float DAT_00399194;
extern float DAT_00399198;
extern float DAT_003f3580;
extern float DAT_003f3584;
extern char DAT_003eaad8;
void FUN_00230d64(void *);
void FUN_00108dac(void *);
int FUN_001c0bb0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

struct Ent {
    char pad0[0x60];
    float f60;
    float f64;
    char pad68[0x10];
    float f78;
};

struct Obj {
    char pad0[0x5c];
    unsigned f5c;
    Ent *ents[2];
    char pad68[0xc];
    unsigned char f74;
};

extern "C" void FUN_00230c40(Obj *o)
{
    o->f5c = DAT_0039835c;
    o->f74 = 1;
    FUN_00230d64(o);
    for (int i = 0; i < 2; i++) {
        o->ents[i]->f60 = DAT_003f3580;
        o->ents[i]->f64 = DAT_003f3584;
        o->ents[i]->f78 = Clamp(DAT_00399160, DAT_00399194, DAT_00399198);
    }
    FUN_00108dac(o);
    FUN_001c0bb0(&DAT_003eaad8, 0x21);
}
