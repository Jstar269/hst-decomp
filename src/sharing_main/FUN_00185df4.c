/* HSTMATCH module=hstp_trans_main.prx start=0x00185df4 end=0x00185e00 symbol=FUN_00185df4 */
/* Clone of src/eboot/FUN_00179700.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x2e0]; int field; } Inner2e0;
typedef struct { char pad[0x17c]; Inner2e0 *inner; } Outer17c;

int *FUN_00185df4(Outer17c *o)
{
    return &o->inner->field;
}
