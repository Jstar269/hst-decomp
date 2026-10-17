/* HSTMATCH module=hstp_trans_main.prx start=0x001cf7dc end=0x001cf8c4 symbol=FUN_001cf7dc lang=c99 */
/* Clone of src/eboot/reset_state_001c15c8.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed struct offsets and loop without unrolling; exact match verified; names and types await human review. */

extern char DAT_003f39a8;
extern void FUN_001cf558(void);
extern void FUN_001e818c(void);
extern void FUN_0023ce78(void);
extern void FUN_002441f4(void *);

struct Obj {
    char pad0[32];
    int f_20;
    int f_24;
    int f_28;
    int f_2c;
    int f_30;
    int f_34;
    int f_38;
    int f_3c;
    short f_40;
    char pad42;
    char f_43;
    char pad44[108];
    char f_b0;
    char f_b1;
    char f_b2;
    char f_b3;
    char f_b4;
    char padb5[7];
    char f_bc;
    char f_bd;
    short padbe;
    int f_c0;
    char f_c4;
    char f_c5;
    char f_c6;
    char f_c7;
    char padc8[840];
    short f_410;
    char pad412[32796];
    int f_8430;
    int pad8434;
    int f_8438;
};

void FUN_001cf7dc(struct Obj *param_1)
{
    param_1->f_8438 = 0;
    param_1->f_20 = 0;
    param_1->f_24 = 0;
    param_1->f_28 = 0;
    param_1->f_2c = 0;
    param_1->f_30 = 1;
    param_1->f_34 = 2;
    param_1->f_38 = 0;
    param_1->f_3c = 0;
    param_1->f_40 = 0;
    param_1->f_43 = 0;
    param_1->f_b0 = 0;
    param_1->f_b1 = -1;
    param_1->f_b2 = -1;
    param_1->f_b3 = 0;
    param_1->f_b4 = 0;
    param_1->f_c4 = 0;
    param_1->f_c5 = 0;
    param_1->f_c6 = 0;
    param_1->f_c7 = 0;
    param_1->f_410 = 0;
    FUN_001cf558();

    int i = 0;
    char *v1 = (char *)param_1;
    do {
        *(char *)(v1 + 0x412) = 0;
        i++;
        *(char *)(v1 + 0x413) = 0;
        v1 += 2;
    } while (i < 2);

    param_1->f_bc = 1;
    param_1->f_bd = 0;
    param_1->f_c0 = -1;
    param_1->f_8430 = 0;

    FUN_002441f4(&DAT_003f39a8);
    FUN_001e818c();
    FUN_0023ce78();
}
