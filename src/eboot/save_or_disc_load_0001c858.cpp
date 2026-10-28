/* HSTMATCH module=EBOOT.BIN start=0x0001c858 end=0x0001ca58 symbol=FUN_0001c858 lang=c++ data=0x002cfc34 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002cfc34-0x002cfc83) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
struct Loader {
    char pad[0x1008];
    u8 loaded;
    u8 result;
    u8 use_save;
};
inline void *operator new[](unsigned, void *p) { return p; }
extern int DAT_002cfae4;
extern int DAT_0030abb4;
extern int DAT_0030abb8;
extern char DAT_0030ab9c[];
extern "C" void FUN_000149a8(char *);
extern "C" int FUN_000fcc78(char *, int);
extern "C" int FUN_000fd850(char *, int, int, int *);
extern "C" void FUN_0001c0fc(char *, int);
extern "C" void FUN_000143b0(char *, char *, char *);
extern "C" u8 FUN_0001c010(char *, char *, int);

extern "C" u8 FUN_0001c858(Loader *self)
{
    char name[128];
    char path[128];
    int state;
    new (name) char[128]();
    char *p;
    FUN_000149a8(name);
    for (p = name; *p; p++) {
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;
    }
    if (DAT_002cfae4 == 3) {
        if (self->use_save) {
            self->result = 0;
            state = 0;
            if (FUN_000fcc78("ms0:/PSP/SAVEDATA/UCUS98701GAMEDATA/GAMEDATA.BDL", 0) && FUN_000fd850(name, DAT_0030abb4, DAT_0030abb8, &state)) {
                self->result = 1;
                if (state == 1)
                    self->result = 0;
                else
                    FUN_0001c0fc(DAT_0030ab9c, DAT_0030abb4);
            } else {
                self->use_save = 0;
            }
        }
        if (!self->use_save) {
            FUN_000143b0(path, "/PSP_GAME/USRDIR/xbdata/%s", name);
            self->result = FUN_0001c010(DAT_0030ab9c, path, 0);
        }
    } else {
        if (self->use_save) {
            self->result = 0;
            if (FUN_000fcc78("ms0:/PSP/SAVEDATA/UCUS98701GAMEDATA/GAMEDATA.BDL", 0) && FUN_000fd850(name, DAT_0030abb4, DAT_0030abb8, 0)) {
                self->result = 1;
                FUN_0001c0fc(DAT_0030ab9c, DAT_0030abb4);
            } else {
                self->use_save = 0;
            }
        }
        if (!self->use_save)
            self->result = FUN_0001c010(DAT_0030ab9c, name, 0);
    }
    self->loaded = 1;
    return self->result;
}
