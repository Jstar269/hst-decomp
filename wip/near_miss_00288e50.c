/* HSTMATCH module=EBOOT.BIN start=0x00288e50 end=0x00288f2c symbol=FUN_00288e50 lang=c99 */
/* Near miss: 53/55 words; lower half and epilogue 100% matched; stream check condition remaining */

extern char DAT_002feb30[];
extern void FUN_0014c214(void *, int, int, void *);
extern void *FUN_0014c914(void *, void *);
extern int FUN_0014c820(void *, int);
extern int FUN_0014ce38(void *, int);
extern void FUN_00286acc(const char *, int, int, int, int);

struct Stream {
    char pad0[4];
    int cur;
    char pad1[12];
    int end;
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
        struct Stream *v1 = param_1->stream;
        int iVar3 = v1->cur;
        int bVar2 = 0;
        if (iVar3 != 0) {
            int bVar1;
            if (iVar3 == 0) {
                bVar1 = 0;
            } else {
                bVar1 = (v1->end != iVar3 + 4);
            }
            if (bVar1) {
                bVar2 = 1;
            }
        }

        if (bVar2) {
        } else {
            if (param_1->f_4 != 0) {
                char buf[36];
                FUN_0014c214(buf, param_1->f_4, param_1->f_3c, param_1);
                FUN_0014c914(param_1->stream, buf);
                FUN_0014c820(buf, -1);
            }
        }

        if (FUN_0014ce38(param_1->stream, param_2) == 0) {
            FUN_00286acc(DAT_002feb30, param_1->f_30, param_1->f_34, param_1->f_38, param_2);
        }
    }
}
// near miss from lane u6fr1-0 (unreviewed)
