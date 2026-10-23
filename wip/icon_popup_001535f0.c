/* HSTMATCH module=EBOOT.BIN start=0x001535f0 end=0x0015371c symbol=FUN_001535f0 lang=c99 */
/* near miss: 70/75 words, 50 differ. Seventh member of the 0x154xxx look-up family (same -1 arm,
   same 100/1000 chain, same tail): everything from the chain onwards is retail's, so the known
   `bgezl a1` guard costs its usual 6 words. Two extra findings: (a) the record must be a typed
   struct (int id at +8, a at +0xc, b at +0x10, unsigned char flag at +0x14) -- with raw
   *(int *)(param+off) args MWCC builds `addiu aN,addr; lw aN,0(aN)` addresses instead of retail's
   direct `lw aN,off(s0)`; (b) the log format choice between DAT_002dc7a8 and DAT_002dc7a4 is a
   plain `beqz` + out-of-line arm in retail and comes out as beqzl in every spelling tried (if/else,
   inverted if/else, both ternaries, preassign+override, one-case switch -- the switch is closest at
   70/75). Ours also emits a duplicate `b` into the join where retail has one. */
typedef struct {
    int pad[2];
    int id;
    int a;
    int b;
    unsigned char flag;
} Rec;

extern unsigned char DAT_003402f0;
extern char DAT_002dc774[];
extern char DAT_002dc7a4[];
extern char DAT_002dc7a8[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int, int, char *);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
extern void FUN_002875f8(int, int, unsigned char, int);

int FUN_001535f0(Rec *param_1, int param_2)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        char *msg;

        FUN_0014d044(param_2);
        switch (param_1->flag) {
        case 0:
            msg = DAT_002dc7a8;
            break;
        default:
            msg = DAT_002dc7a4;
            break;
        }
        FUN_0014fd94(DAT_002dc774, param_1->id, param_1->a, param_1->b, msg);
    }
    id = param_1->id;
    result = *(int *)(param_2 + 0xc);
    if (id == -1) {
        result = (int)DAT_0034a118;
        if (DAT_0034a118 != 0)
            result = (int)DAT_0034a118 + 0xe0;
    } else if (id >= 0) {
        if (id < 100)
            result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = FUN_001c6f70(DAT_0034a114, id, 0);
        else
            result = FUN_001c70c0(DAT_0034a114);
    }
    if (result != 0)
        FUN_002875f8(result, param_1->a, param_1->flag, param_1->b);
    return 0;
}
// near miss from lane fm6 (unreviewed)
