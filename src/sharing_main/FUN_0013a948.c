/* HSTMATCH module=hstp_trans_main.prx start=0x0013a948 end=0x0013a96c symbol=FUN_0013a948 lang=c99 */
/* Clone of src/eboot/FUN_0012f3f0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* View of the camera object that only shows the two four-word blocks this function copies. */
typedef struct CameraWords {
  char pad00[0x70];
  float src[4];   /* 0x70 */
  char pad80[0x10];
  float dst[4];   /* 0x90 */
} CameraWords;

extern void FUN_0013a7a0(CameraWords *);

/* Copy the four words at 0x70 over those at 0x90, then run the camera state update. */
void FUN_0013a948(CameraWords *self)
{
  self->dst[0] = self->src[0];
  self->dst[1] = self->src[1];
  self->dst[2] = self->src[2];
  self->dst[3] = self->src[3];
  FUN_0013a7a0(self);
  return;
}
