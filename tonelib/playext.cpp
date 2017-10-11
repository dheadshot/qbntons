#include "playext.h"
#include "Tone1.h"
#include "ToneProjOpts.h"

void StopPlaying(PlayControl *NoteCont)
{
  NoteCont->playing = false;
  (*(NoteCont->toneref)).stop();
}

void ResetPlaying(PlayControl *NoteCont)
{
  NoteCont->playpos = 0;
}

void PlayCheck(PlayControl *NoteCont)  //Call this repeatedly!
{
  if (NoteCont->notearref == (NoteStruct *) 0) return;
  if ((NoteCont->toneref)->isPlaying()) return;
  uint16_t n = NoteCont->playpos;
  if (NoteCont->notearref[n].frequency != 0)
  {
    (NoteCont->toneref)->play(NoteCont->notearref[n].frequency,NoteCont->notearref[n].duration);
    (NoteCont->playpos)++;
  } else NoteCont->playing = false;
}

