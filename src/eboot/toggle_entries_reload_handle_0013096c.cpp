/* HSTMATCH module=EBOOT.BIN start=0x0013096c end=0x00130b10 symbol=FUN_0013096c lang=c++ */
/* Clone of src/sharing_main/toggle_entries_reload_handle_0013bf24.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: typed the list and object structs, restored the dropped second argument of FUN_001b1f7c (the tested handle), wrote the flag as !p2 and swapped the Ghidra if/else arms; exact match verified; names and types await human review. */
struct Ent;
struct List { char pad[0xa8]; Ent *fa8; };
struct Obj { char pad[0x120]; int f120; int f124; };

extern "C" {
extern List *DAT_003386b0;
extern Ent *DAT_00340284;
extern Ent *DAT_00338c20;
extern char DAT_0034179c[];
extern char DAT_002db190[];
extern int FUN_0001f2f8(List *);
extern Ent *FUN_0001f300(List *, int);
extern void FUN_0001f63c(Ent *, int, bool);
extern int FUN_001b1f7c(char *, int);
extern void FUN_001b1f84(char *, int *);
extern int FUN_001b28f0(char *, char *);
extern void FUN_00062afc(int, int);

void FUN_0013096c(Obj *o, int p2)
{
    if (DAT_003386b0 != 0) {
        int i = 0;
        if (FUN_0001f2f8(DAT_003386b0) > 0) {
            do {
                Ent *e = FUN_0001f300(DAT_003386b0, i);
                if (e != 0 && e != DAT_00340284 && e != DAT_00338c20 && e != DAT_003386b0->fa8) {
                    FUN_0001f63c(e, 0, !p2);
                    FUN_0001f63c(e, 1, !p2);
                }
                i++;
            } while (i < FUN_0001f2f8(DAT_003386b0));
        }
    }
    if (p2 != 0) {
        o->f120 = 0;
        if (o->f124 >= 0 && FUN_001b1f7c(DAT_0034179c, o->f124) != 0) {
            FUN_001b1f84(DAT_0034179c, &o->f124);
            o->f124 = -1;
        }
        o->f124 = FUN_001b28f0(DAT_0034179c, DAT_002db190);
        FUN_00062afc(o->f124, 10);
    } else {
        o->f120 = -1;
        if (o->f124 >= 0 && FUN_001b1f7c(DAT_0034179c, o->f124) != 0) {
            FUN_001b1f84(DAT_0034179c, &o->f124);
            o->f124 = -1;
        }
    }
}
}
