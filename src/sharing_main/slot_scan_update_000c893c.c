/* HSTMATCH module=hstp_trans_main.prx start=0x000c893c end=0x000c8a98 symbol=FUN_000c893c lang=c99 */
/* Hand-written reconstruction (port of src/eboot/slot_scan_update_000c4eb8.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
typedef struct Ent { char pad[6]; unsigned char on; } Ent;
typedef struct Obj { char pad0[0x58]; Ent ent[4]; char pad1[0x178 - 0x58 - 28]; unsigned char m178; char pad2[0x198 - 0x179]; int cur; } Obj;
typedef struct Tab { unsigned char first; char pad1[0xdf]; unsigned char flag; char pad2[3]; char x[0x120 - 0xe4]; } Tab;
typedef struct Self { char pad0[0x780]; int m780; void *m784; } Self;

extern Obj *DAT_003e1e04;
extern Tab DAT_003eaaf0[];
extern int FUN_0029754c(void *);
extern void FUN_00297a1c(void *, int, int, void *);
extern void FUN_000be5d8(Obj *);
extern void FUN_000be53c(Obj *, Ent *);
extern void FUN_000c0bf4(Obj *, int);
extern int FUN_000c0e5c(Obj *, int);
extern int FUN_000c0e74(Obj *, int);

void FUN_000c893c(Self *self)
{
    if (DAT_003e1e04 != 0) {
        int cur;
        int n;
        int i;
        if (FUN_0029754c(self->m784) == 0)
            return;
        FUN_000be5d8(DAT_003e1e04);
        cur = DAT_003e1e04->cur;
        if (DAT_003eaaf0[0].first == 0) {
            n = 2;
        } else {
            n = 4;
        }
        for (i = 0; i < n; i++) {
            Obj *g = DAT_003e1e04;
            if (g->ent[i].on != 0) {
                if (i != cur)
                    FUN_000c0bf4(g, i);
            } else if (DAT_003eaaf0[i].flag == 0) {
                int a = FUN_000c0e5c(g, i);
                int b = FUN_000c0e74(g, i);
                FUN_00297a1c(self->m784, a, b, DAT_003eaaf0[i].x);
                if (DAT_003e1e04->m178 != 0)
                    FUN_000be53c(DAT_003e1e04, &DAT_003e1e04->ent[i]);
            }
        }
    }
    self->m780 = self->m780 + 1;
}
