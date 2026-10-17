/* HSTMATCH module=hstp_trans_main.prx start=0x00177d20 end=0x00177d40 symbol=FUN_00177d20 */
/* Clone of src/eboot/FUN_0016bb5c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x1054]; int value; } Big1054;
extern Big1054 *FUN_00177d4c(void *a);

int FUN_00177d20(void *a)
{
    return FUN_00177d4c(a)->value;
}
