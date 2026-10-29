/* HSTMATCH module=EBOOT.BIN start=0x00200f48 end=0x00201114 symbol=FUN_00200f48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/quad_config.h"

/* Pane record: only the two words the setup touches. */
struct Pane {
    char pad[0x24];
    int unk24;
    int unk28;
};

/* Entry record the setup reads. */
struct Entry {
    short id;
    char pad2[0x20 - 2];
    unsigned short unk20;
    char pad22[0x68 - 0x22];
    short unk68;
    char pad6a[0x7c - 0x6a];
    unsigned char unk7c;       /* 0x7c value 2 hides the first pane */
    unsigned char table7d;    /* 0x7d start of a stride-3 byte table */
};

extern "C" {
extern QuadConfig *DAT_0034a13c;
extern int FUN_001fea10(int, int, int);
extern void FUN_0010d4a8(void *);
extern int FUN_0016bb98(short, void *);
extern void FUN_000ffb3c(Pane *, int);

/* Note: the slot parameter is reused for the value returned by the first helper call (matching form). */
void FUN_00200f48(int screen, Entry *entry, int slot, int row) {

    Pane **paneA = (Pane **)(screen + slot * 20 + 48);
    Pane **paneB = (Pane **)(screen + (slot + 1) * 20 + 48);
    Pane **paneC = (Pane **)(screen + (slot + 2) * 20 + 48);
    int column = DAT_0034a13c->unk4c;
    slot = FUN_001fea10(7, 0, entry->unk20);
    int rowObj = *(int *)(screen + row * 12 + 0x64c);
    *(int *)(rowObj + 0xf8) = slot;
    *(int *)(rowObj + 0x138) = 1;
    FUN_0010d4a8((void *)rowObj);
    
    Pane *second = *paneB;
    int off = column * 3;
    second->unk24 = second->unk28 + *(unsigned char *)(off + (int)entry + 0x7d);
    
    int kind = FUN_0016bb98(entry->id, &entry->unk68);
    switch (kind) {
    case 1:
        (*paneC)->unk24 = (*paneC)->unk28;
        break;
    case 2:
        (*paneC)->unk24 = (*paneC)->unk28 + 2;
        break;
    case 3:
        (*paneC)->unk24 = (*paneC)->unk28 + 1;
        break;
    case 4:
        (*paneC)->unk24 = (*paneC)->unk28 + 3;
        break;
    case 5:
        (*paneC)->unk24 = (*paneC)->unk28 + 4;
        break;
    default:
        (*paneC)->unk24 = (*paneC)->unk28;
        break;
    }
    
    if (entry->unk7c == 2) {
        FUN_000ffb3c(*paneA, 0);
    } else {
        FUN_000ffb3c(*paneA, 1);
    }

}
}
