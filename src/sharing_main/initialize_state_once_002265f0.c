/* HSTMATCH module=hstp_trans_main.prx start=0x002265f0 end=0x00226630 symbol=FUN_002265f0 lang=c99 */
/* Clone of src/eboot/initialize_state_once_00217548.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: typed the state fields so the flag store uses direct member addressing; exact match verified; names and types await human review. */
typedef unsigned char byte;
typedef unsigned int uint;

struct State {
    char pad0[8];
    int scale;
    char pad1[0x14];
    unsigned char started;
};

void FUN_002265f0(struct State *self, int x, int y, uint value)
{
    if (self->started == 0) {
        self->started = 1;
        *(int *)((char *)self + 0x28) = -x * self->scale;
        *(int *)((char *)self + 0x2c) = 0;
        *(uint *)((char *)self + 0x30) = value;
        *(int *)((char *)self + 0x24) = -y;
    }
}
