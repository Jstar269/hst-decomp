/* HSTMATCH module=hstp_trans_main.prx start=0x00110adc end=0x00110be0 symbol=FUN_00110adc lang=c99 */

extern char DAT_0037ff6c[];
extern void FUN_00012ad0(const char *);

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
    int base;
    Header *header;
    Entry *entries;
} Context;

int FUN_00110adc(Context *ctx, Header *header)
{
    int i, j;
    int *ptr;

    if (ctx->base != 0) {
        return 0;
    }
    ctx->base = (int)header;
    ctx->header = header;

    if (header->magic[0] != 'T' || header->magic[1] != 'O' || header->magic[2] != '1') {
        FUN_00012ad0(DAT_0037ff6c);
        return 0;
    }

    ctx->entries = (Entry *)((char *)ctx->base + 16);

    for (i = 0; i < ctx->header->count; i++) {
        ctx->entries[i].ptrs = (int *)(ctx->base + (int)ctx->entries[i].ptrs);
        ptr = ctx->entries[i].ptrs;
        for (j = 0; j < ctx->entries[i].count; j++) {
            *ptr += ctx->base;
            ptr++;
        }
    }

    return 1;
}

// Differing words: 9/65 words differ (56 words match byte-for-byte).
// Frame size: 16 bytes (matches retail).
// Differs at 0x110b5c: retail schedules outer and inner load registers as (v1=entries, a2=base, a1=&entry)
// and inner loop (a1=base, v1=*ptr), whereas MWCC allocates (a1=entries, v1=base, a2=&entry) and (a1=*ptr, v1=base).
// Ruled out: All local declaration permutations, C++ class member methods, local base variables,
// array indexing ptr[j], char* byte indexing.
// near miss from lane ag6 (unreviewed)
