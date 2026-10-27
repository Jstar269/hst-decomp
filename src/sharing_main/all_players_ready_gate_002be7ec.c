/* HSTMATCH module=hstp_trans_main.prx start=0x002be7ec end=0x002be918 symbol=FUN_002be7ec lang=c99 */
/* Hand-written reconstruction (port of src/eboot/all_players_ready_gate_002aef68.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Row {
    char pad0[0xe0];
    unsigned char f_e0;
    char pad1[0x120 - 0xe1];
};
extern unsigned char DAT_003e19f8;
extern int DAT_003e1e30;
extern int DAT_003f39a8;
extern unsigned char DAT_003eaaf6;
extern unsigned char *DAT_003e1e84;
extern struct Row DAT_003eaaf0[];
extern unsigned char *FUN_000c8538(int, int);
extern void FUN_002bde98(int *);

void FUN_002be7ec(int *param_1)
{
    int ok = DAT_003e19f8 != 0;
    if (ok) ok = DAT_003e1e30 != 0;
    if (ok) ok = DAT_003f39a8 == 0x44;
    if (ok) ok = (DAT_003eaaf6 != 0) ^ 1;
    if (!ok || *param_1 == 0)
        return;
    int allReady = 1;
    int i = 0;
    struct Row *p = DAT_003eaaf0;
    while (i < (DAT_003e1e84[0x45] == 0 ? 4 : 2)) {
        if (p->f_e0 == 0) {
            unsigned char *e = FUN_000c8538(DAT_003e1e30, i);
            if (e[0x1cc] != 1) allReady = 0;
        }
        p++;
        i++;
    }
    if (allReady) {
        FUN_002bde98(param_1);
        *param_1 = 0;
    }
}
