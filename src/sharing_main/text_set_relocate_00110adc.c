/* HSTMATCH module=hstp_trans_main.prx start=0x00110adc end=0x00110be0 symbol=FUN_00110adc lang=c99 */
/* Clone of src/eboot/text_set_relocate_0010ad1c.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Relocates a 'TO1' text-set file in place: entry table at +16, each entry holds a pointer table (rebased) whose words are rebased too. Matching idiom: integer address arithmetic `(int)ctx->entries + off` through int* temporaries, declaration order j,i,off,p,q,q2. */
typedef struct Entry {
    int *ptrs;
    int count;
    int unk8;
} Entry;

typedef struct Header {
    char magic[4];
    int unk4;
    int count;
} Header;

typedef struct Context {
    int unk0;
    char *base;
    Header *header;
    Entry *entries;
} Context;

extern char DAT_0037ff6c[];
extern void FUN_00012ad0(const char *);

int FUN_00110adc(Context *ctx, char *data)
{
    int j;
    int i;
    int off;
    int *p;
    int *q;
    int *q2;

    if (ctx->base != 0) {
        return 0;
    }
    ctx->base = data;
    ctx->header = (Header *)data;
    if (data[0] != 'T' || data[1] != 'O' || data[2] != '1') {
        FUN_00012ad0(DAT_0037ff6c);
        return 0;
    }
    ctx->entries = (Entry *)(ctx->base + 16);
    i = 0;
    if (i < ctx->header->count) {
        off = 0;
        do {
            q = (int *)((int)ctx->entries + off);
            *q = *q + (int)ctx->base;
            q2 = (int *)((int)ctx->entries + off);
            p = (int *)*q2;
            j = 0;
            if (j < q2[1]) {
                do {
                    j++;
                    *p = *p + (int)ctx->base;
                    p++;
                } while (j < *(int *)(off + (int)ctx->entries + 4));
            }
            i++;
            off += 12;
        } while (i < ctx->header->count);
    }
    return 1;
}
