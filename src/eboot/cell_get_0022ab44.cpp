/* HSTMATCH module=EBOOT.BIN start=0x0022ab44 end=0x0022abdc symbol=FUN_0022ab44 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag fm3 wip near miss) corrected by hand: rewritten with a typed table struct (0x3d00 pad, 20-byte rows), full prototype for FUN_0022a9a8 (args passed on), and the column+10 kept in a local; exact match verified; names and types await human review. */
struct Row { unsigned char c[0x14]; };
struct Tab { char pad[0x3d00]; Row r[1]; };
extern Tab *DAT_003415a8;
extern "C" int FUN_0022a9a8(int, int);

extern "C" unsigned char FUN_0022ab44(int param_1, int param_2, int *param_3)
{
    int iVar2 = FUN_0022a9a8(param_1, param_2);
    if (param_3 != 0) {
        *param_3 = iVar2;
    }
    if (iVar2 == 1) {
        int col = param_2 + 10;
        return DAT_003415a8->r[param_1].c[col];
    }
    return DAT_003415a8->r[param_1].c[param_2];
}
