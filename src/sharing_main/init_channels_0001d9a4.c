/* HSTMATCH module=hstp_trans_main.prx start=0x0001d9a4 end=0x0001dbec symbol=FUN_0001d9a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct ChannelBits {
    signed char a:2;
    signed char b:2;
    signed char c:2;
    signed char d:2;
};

void FUN_0001d9a4(char *param_1)
{
    char *puVar6 = param_1 + 12;
    int iVar3 = (int)puVar6 - (int)param_1;
    int iVar4 = 0xc0 - iVar3;
    char *p = puVar6;
    for (int i = 0; i < iVar4; i++) {
        *p++ = 0;
    }

    struct ChannelBits *cb = (struct ChannelBits *)(param_1 + 136);
    cb[0].a = 2; cb[0].b = 2; cb[0].c = 2; cb[0].d = 2;
    cb[1].a = 2; cb[1].b = 2; cb[1].c = 2; cb[1].d = 2;
    cb[2].c = 2; cb[2].d = 2; cb[2].a = 2; cb[2].b = 2;
    cb[3].a = 2; cb[3].b = 2; cb[3].c = 2; cb[3].d = 2;
    cb[4].a = 2; cb[4].b = 2; cb[4].c = 2; cb[4].d = 2;
    cb[5].a = 2; cb[5].b = 2; cb[5].c = 2; cb[5].d = 2;

    *(int *)(param_1 + 132) = 0xffff;
}
