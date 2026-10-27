/* HSTMATCH module=hstp_trans_main.prx start=0x0013bf24 end=0x0013c0c8 symbol=FUN_0013bf24 lang=c++ data=0x0038239c */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: typed the list and object structs, restored the dropped second argument of FUN_001c0010 (the tested handle), wrote the flag as !p2 and swapped the Ghidra if/else arms; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0038239c-0x003823a9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Ent;
struct List { char pad[0xa8]; Ent *fa8; };
struct Obj { char pad[0x120]; int f120; int f124; };

extern "C" {
extern List *DAT_003e19f0;
extern Ent *DAT_003e95c4;
extern Ent *DAT_003e1f60;
extern char DAT_003eaad8[];
extern int FUN_0001f0f0(List *);
extern Ent *FUN_0001f0f8(List *, int);
extern void FUN_0001f664(Ent *, int, bool);
extern int FUN_001c0010(char *, int);
extern void FUN_001c0018(char *, int *);
extern int FUN_001c0984(char *, char *);
extern void FUN_000639c0(int, int);

void FUN_0013bf24(Obj *o, int p2)
{
    if (DAT_003e19f0 != 0) {
        int i = 0;
        if (FUN_0001f0f0(DAT_003e19f0) > 0) {
            do {
                Ent *e = FUN_0001f0f8(DAT_003e19f0, i);
                if (e != 0 && e != DAT_003e95c4 && e != DAT_003e1f60 && e != DAT_003e19f0->fa8) {
                    FUN_0001f664(e, 0, !p2);
                    FUN_0001f664(e, 1, !p2);
                }
                i++;
            } while (i < FUN_0001f0f0(DAT_003e19f0));
        }
    }
    if (p2 != 0) {
        o->f120 = 0;
        if (o->f124 >= 0 && FUN_001c0010(DAT_003eaad8, o->f124) != 0) {
            FUN_001c0018(DAT_003eaad8, &o->f124);
            o->f124 = -1;
        }
        o->f124 = FUN_001c0984(DAT_003eaad8, "matrixcamera");
        FUN_000639c0(o->f124, 10);
    } else {
        o->f120 = -1;
        if (o->f124 >= 0 && FUN_001c0010(DAT_003eaad8, o->f124) != 0) {
            FUN_001c0018(DAT_003eaad8, &o->f124);
            o->f124 = -1;
        }
    }
}
}
