/* HSTMATCH module=EBOOT.BIN start=0x00288e50 end=0x00288f2c symbol=FUN_00288e50 lang=c99 */
/* Hand-written reconstruction; current best is 32/55 words different after seven lane compiles. */

extern char DAT_002feb30[];
extern void FUN_0014c214(void *, int, int, void *);
extern void *FUN_0014c914(void *, void *);
extern int FUN_0014c820(void *, int);
extern int FUN_0014ce38(void *, int);
extern void FUN_00286acc(const char *, int, int, int, int);

struct Stream {
    char pad0[4];
    unsigned int cur;
    char pad1[12];
    unsigned int end;
};

struct Obj {
    char pad0[4];
    int f_4;
    char pad1[4];
    struct Stream *stream;
    char pad2[32];
    int f_30;
    int f_34;
    int f_38;
    int f_3c;
};

void FUN_00288e50(struct Obj *param_1, int param_2)
{
    if (0 < param_2) {
        unsigned int iVar3 = param_1->stream->cur;
        _Bool bVar2 = 0;
        struct Stream *uVar4;
        if (iVar3 != 0) {
            _Bool bVar1;
            if (iVar3 == 0) {
                bVar1 = 0;
            } else {
                bVar1 = (param_1->stream->end != iVar3 + 4);
            }
            if (bVar1) {
                bVar2 = 1;
            }
        }

        if (bVar2) {
            uVar4 = param_1->stream;
        } else {
            if (param_1->f_4 != 0) {
                char buf[36];
                FUN_0014c214(buf, param_1->f_4, param_1->f_3c, param_1);
                FUN_0014c914(param_1->stream, buf);
                FUN_0014c820(buf, -1);
            }
            uVar4 = param_1->stream;
        }

        if (FUN_0014ce38(uVar4, param_2) == 0) {
            FUN_00286acc(DAT_002feb30, param_1->f_30, param_1->f_34, param_1->f_38, param_2);
        }
    }
}
// Retaining the stream result in uVar4 in both bVar2 arms and using _Bool flags moves the warning and
// error-call tail to retail's addresses and reduces the baseline from 48 to 32 differing words. The
// remaining mismatch is concentrated in stream-check conditions/registers and the warning branch's
// delay-slot layout. Unsigned stream fields and nested direct field reads did not change the result;
// simplifying the branch to `if (!bVar2)` regressed to 48 differences.
// improved by lane lnm1 (unreviewed): 48 -> 32 differing words
