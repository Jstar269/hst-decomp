/* HSTMATCH module=hstp_trans_main.prx start=0x002b0c34 end=0x002b0ca4 symbol=FUN_002b0c34 lang=c++ */
/* Clone of src/eboot/mode3_without_special_state_002a1828.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0x1b0];
    int f1b0;
    char pad1[0x34];
    int f1e8;
};

extern "C" int FUN_002b0c34(Obj *o)
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
