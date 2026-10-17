/* HSTMATCH module=hstp_trans_main.prx start=0x000f605c end=0x000f61ec symbol=FUN_000f605c lang=c99 */
/* Clone of src/eboot/update_colors_alpha_000f0994.c (hstclone.py tag u1r5s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from Ghidra pseudocode: float to unsigned char alpha unpack into 4 color words; exact match verified; names and types await human review. */

typedef struct Obj {
    char pad0[0x54];
    unsigned char flag;
    char pad1[0x60 - 0x55];
    unsigned int *c0;   /* 0x60 (96) */
    unsigned int *c2;   /* 0x64 (100) */
    unsigned int *c1;   /* 0x68 (104) */
    unsigned int *c3;   /* 0x6c (108) */
    char pad2[0x80 - 0x70];
    float alpha;        /* 0x80 (128) */
} Obj;

extern void FUN_00108a2c(void);

void FUN_000f605c(Obj *o)
{
    if (o->flag == 0) {
        FUN_00108a2c();
        *o->c0 = ((unsigned int)(unsigned char)o->alpha << 24) | (*o->c0 & 0x00ffffff);
        *o->c1 = ((unsigned int)(unsigned char)o->alpha << 24) | (*o->c1 & 0x00ffffff);
        *o->c2 = ((unsigned int)(unsigned char)o->alpha << 24) | (*o->c2 & 0x00ffffff);
        *o->c3 = ((unsigned int)(unsigned char)o->alpha << 24) | (*o->c3 & 0x00ffffff);
    }
}
