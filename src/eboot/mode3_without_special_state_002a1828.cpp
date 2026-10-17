/* HSTMATCH module=EBOOT.BIN start=0x002a1828 end=0x002a1898 symbol=FUN_002a1828 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0x1b0];
    int f1b0;
    char pad1[0x34];
    int f1e8;
};

extern "C" int FUN_002a1828(Obj *o)
{
    int flag = 0;
    switch (o->f1e8) {
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1e:
    case 0x20:
        flag = 1;
        break;
    }
    int ok = o->f1b0 == 3;
    if (ok) ok = (flag != 0) ^ 1;
    return ok;
}
