/* HSTMATCH module=EBOOT.BIN start=0x000931ec end=0x00093434 symbol=FUN_000931ec lang=c99 */
typedef struct { int a; int b; int c; } Str12;

extern float DAT_002d283c;
extern char DAT_002d2a70[];
extern char DAT_002d2a7c[];
extern char DAT_002d2a88[];
extern void FUN_00093484(float);
extern void FUN_000143b0(char *, char *, int);
extern void FUN_000031f0(Str12 *, char *);
extern void FUN_00004138(Str12 *, int);
extern unsigned char FUN_000d9b1c(float *, int, Str12 *);
extern void FUN_00057edc(int, float, float *, void *, void *, int);
extern void FUN_00057f30(int, int);
extern void FUN_00093104(void);
extern void FUN_0009312c(void);
extern void FUN_00093194(void);

void FUN_000931ec(int param_1, int param_2, unsigned char *param_3, int param_4)
{
    char buf[64];
    Str12 body_str;
    Str12 head_str;
    Str12 face_str;
    float local[7];
    unsigned int i;
    int iVar2;
    void (*cb)(void);
    unsigned char c;
    int id;

    FUN_00093484(DAT_002d283c);
    if (param_3 != (unsigned char *)0x0) {
        if (*(int *)(param_1 + 0x5c) != 0) {
            *(unsigned char *)(*(int *)(param_1 + 0x5c) + 0x171) = param_3[0];
        }
        if (*(int *)(param_1 + 0x60) != 0) {
            *(unsigned char *)(*(int *)(param_1 + 0x60) + 0x171) = param_3[1];
        }
    }
    for (i = 0; i < 6; i++) {
        if (*(int *)(param_1 + i * 4 + 0x50) != 0 && i != 2) {
            local[0] = 0.0f;
            local[1] = 0.0f;
            local[2] = 0.0f;
            if (i == 3 || i == 4) {
                id = *(int *)(*(int *)(param_1 + i * 4 + 0x50) + 0x1b4);
                if (*(int *)(param_1 + 0x58) != 0) {
                    FUN_000143b0(buf, DAT_002d2a70,
                                 *(int *)(*(int *)(param_1 + 0x58) + 0x1b4));
                    FUN_000031f0(&body_str, buf);
                    c = FUN_000d9b1c(local, (short)id, &body_str);
                    FUN_00004138(&body_str, -1);
                    if (c != 0)
                        goto have;
                }
                if (*(int *)(param_1 + 0x54) != 0) {
                    FUN_000143b0(buf, DAT_002d2a7c,
                                 *(int *)(*(int *)(param_1 + 0x54) + 0x1b4));
                    FUN_000031f0(&head_str, buf);
                    c = FUN_000d9b1c(local, (short)id, &head_str);
                    FUN_00004138(&head_str, -1);
                    if (c != 0)
                        goto have;
                }
                if (*(int *)(param_1 + 0x50) != 0) {
                    FUN_000143b0(buf, DAT_002d2a88, *(int *)(*(int *)(param_1 + 0x50) + 0x1b4));
                    FUN_000031f0(&face_str, buf);
                    FUN_000d9b1c(local, (short)id, &face_str);
                    FUN_00004138(&face_str, -1);
                }
            }
        have:
            iVar2 = *(int *)(param_1 + i * 4 + 0x50);
            cb = (void (*)(void))0;
            if (*(unsigned char *)(iVar2 + 0x171) == 0) {
                if (i == 5 && param_4 != 0) {
                    cb = FUN_00093194;
                }
            } else {
                cb = FUN_0009312c;
                local[0] = -local[0];
            }
            iVar2 = *(int *)(param_1 + i * 4 + 0x50);
            FUN_00057edc(iVar2, 1.0f, local, FUN_00093104, cb,
                         *(int *)(iVar2 + 0x1b0) != 5);
            FUN_00057f30(*(int *)(param_1 + i * 4 + 0x50), *(int *)(param_1 + 0x58));
        }
    }
}
// NEAR (145/146 words, 118 differ). Structure is right (6-slot loop skipping index 2, the
// body/head/face format+check chain with goto have, the cb selection and the 0x57edc/0x57f30 pair);
// the divergence is register/scheduling:
//  - retail's prologue puts `move s0,a2 / move s3,a3 / jal / move s4,a0` (param_1's move in the jal
//    slot); ours puts `move s4,a0` first and s3=a3 in the slot.
//  - retail walks the slot array with s1 (`move s1,s4`, `lw v1,0x50(s1)`) and reuses s0 (param_3's
//    register) for the 0x1b4 id; ours walks with s0 and puts the id in s1. Writing the slot access
//    as `param_1 + i*4 + 0x50` still strength-reduces to a pointer, just in s0.
//  - `if (i == 3 || i == 4)` compiles to a compare-to-mask range test (`addiu s2,-3; sltiu at,..,2`)
//    here; retail has two compares (`li v0,3; beq` then `li v0,4; bnel ...ELSE`). A `switch` with
//    case 3/4 sharing the body is 5 words longer, not the answer. unsigned vs int i makes no
//    difference.
//  - the id must be an int local (`lw` + `seh` at the call), not `(short)` at the load (that folds to
//    a single `lh`).
// near miss from lane fm8 (unreviewed)
