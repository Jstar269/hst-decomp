/* HSTMATCH module=hstp_trans_main.prx start=0x000b74a8 end=0x000b759c symbol=FUN_000b74a8 lang=c++ */
/* Clone of src/eboot/swap_records_000b41b8.cpp (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct Record {
    float f[16];
    int tag;
    Record() {}
    Record(const Record &o)
    {
        f[0] = o.f[0];
        f[1] = o.f[1];
        f[2] = o.f[2];
        f[3] = o.f[3];
        f[4] = o.f[4];
        f[5] = o.f[5];
        f[6] = o.f[6];
        f[7] = o.f[7];
        f[8] = o.f[8];
        f[9] = o.f[9];
        f[10] = o.f[10];
        f[11] = o.f[11];
        f[12] = o.f[12];
        f[13] = o.f[13];
        f[14] = o.f[14];
        f[15] = o.f[15];
        tag = o.tag;
    }
} __attribute__((aligned(16)));

extern "C" void FUN_000b74a8(Record *a, Record *b)
{
    Record tmp = *a;

    *a = *b;
    *b = tmp;
}
