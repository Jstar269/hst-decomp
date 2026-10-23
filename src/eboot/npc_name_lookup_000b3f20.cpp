/* HSTMATCH module=EBOOT.BIN start=0x000b3f20 end=0x000b4024 symbol=FUN_000b3f20 lang=c++ */
/* Hand-written reconstruction from the disassembly (the two name probes are `!= 0` tests that leave `type` undefined on the no-match path as retail does; the skip loop must stay inline as `while (!FUN_0000fe64(*param_2))` so MWCC emits sltu/xori and the rotated loop; the table offset is hoisted into a local so the load schedules after the index multiply); exact match verified; names and types await human review. */
extern "C" char DAT_002d47ac[];
extern "C" char DAT_002d47b4[];
extern "C" int FUN_00014d64(char *, char *);
extern "C" int FUN_0000fe64(int);
extern "C" int FUN_0000d62c(char *);

extern "C" int FUN_000b3f20(int param_1, char *param_2, int param_3, int param_4)
{
    int type;
    int idx;
    int off;

    if (FUN_00014d64(param_2, DAT_002d47ac) != 0)
        type = 0;
    else if (FUN_00014d64(param_2, DAT_002d47b4) != 0)
        type = 1;
    while (!FUN_0000fe64(*param_2))
        param_2++;
    idx = FUN_0000d62c(param_2);
    off = *(int *)(param_1 + type * 0xc) + idx * 0x12;
    return *(char *)(param_4 + off + param_3 * 3) - 1;
}
