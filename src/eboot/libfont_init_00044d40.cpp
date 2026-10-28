/* HSTMATCH module=EBOOT.BIN start=0x00044d40 end=0x00044e54 symbol=FUN_00044d40 lang=c++ */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
/* Loads and starts libfont.prx (retrying the load while it fails, sleeping through FUN_0001b880 between attempts),
   then creates the "gf_string_allocator" heap whose handle lives in DAT_0030ff7c. Each failure logs through
   FUN_00042dd8 on the reent stderr stream. Matching idiom: `#pragma opt_common_subs off` (the module path
   address is materialised for every load call instead of being kept in a saved register). */
struct Reent {
    char pad[0xc];
    void *err;
};

struct Self {
    void *vt;
    char pad4[0x3c - 4];
    int module;                 /* module handle, also used by FUN_00044f4c */
};

extern "C" {
Reent *FUN_0000fe3c();
void FUN_00042dd8(void *, const char *, ...);
void FUN_0001b880(void);
int FUN_002b7830(const char *, int, int);
int FUN_002b7820(int, int, int, int *, int);
int FUN_000df44c(const char *, int, int, int);
}

extern char DAT_002d0000[];     /* "disc0:/PSP_GAME/USRDIR/module/libfont.prx" */
extern char DAT_002d002c[];     /* "fatal error : can not load Module (libfont.prx)\n" */
extern char DAT_002d0060[];     /* "gf_string_allocator" */
extern char DAT_002d0074[];     /* "fatal error : can not allocate gfstring\n" */
extern char DAT_002cffcc[];     /* "fatal error : sceKernelStartModule failed 0x%08x\n" */
extern int DAT_0030ff7c;        /* gf_string heap handle */

#pragma opt_common_subs off

extern "C" int FUN_00044d40(Self *self)
{
    int status;
    int r;
    int e;
    int heap;

    self->module = FUN_002b7830(DAT_002d0000, 0, 0);
    while (self->module < 0) {
        FUN_0001b880();
        self->module = FUN_002b7830(DAT_002d0000, 0, 0);
    }

    r = FUN_002b7820(self->module, 0, 0, &status, 0);
    if (r < 0) {
        FUN_00042dd8(FUN_0000fe3c()->err, DAT_002cffcc, r);
        e = -1;
    } else {
        e = 0;
    }
    if (e != 0) {
        FUN_00042dd8(FUN_0000fe3c()->err, DAT_002d002c);
        return -1;
    }

    heap = FUN_000df44c(DAT_002d0060, 0x26c00, 0, 0);
    DAT_0030ff7c = heap;
    if (heap == 0) {
        FUN_00042dd8(FUN_0000fe3c()->err, DAT_002d0074);
        return -1;
    }
    return 0;
}
