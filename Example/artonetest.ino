#include <Tone1.h>
#include <ToneProjOpts.h>
#include <playext.h>

#include "tfnconst.h"

#define TONE_PIN 3

Tone1 tone1;
PlayControl player = {ns, &tone1, false, 0};


void setup()
{
  // put your setup code here, to run once:
  tone1.begin(TONE_PIN);
  pinMode(TONE_PIN, OUTPUT);
  ResetPlaying(&player);
  player.playing = true;
}

void loop()
{
  // put your main code here, to run repeatedly:
  PlayCheck(&player);
}
