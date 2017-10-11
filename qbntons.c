#include <stdio.h>
#include <string.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

const long NoteArray[7][12] = {
{NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1},
{NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2},
{NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3},
{NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4},
{NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5},
{NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6},
{NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7}};


int phnote(long notedec, long notelen)
{
  if (notelen<1 || notedec<0) return 0;
  unsigned long dur = 1000 / notelen;
  char hnotepart[10] = "";
  printf("  {%ld,%lu},\r\n",notedec,dur);
  return 1;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr,"QB Notes to Note Structure 1.01\r\nUsage:\r\n\t%s SNGfile\r\n",argv[0]);
    return 1;
  }
  FILE *afn = fopen(argv[1],"r");
  if (afn == NULL)
  {
    fprintf(stderr,"Could not open \"%s\"!\r\n",argv[1]);
    return 1;
  }
  char buffer[256] = "";
  int n, i;
  char ch, numstr[10] = "";
  int npoint = -10, noct = 0;
  long nlen = 4, outnote = 0, tn = 0;
  printf("NoteStruct ns[] = {\r\n");
  while (fgets(buffer,255,afn))
  {
    n = 0; 
    while (n<strlen(buffer))
    {
      ch = buffer[n];
      switch (ch)
      {
        case '#':
          npoint++;
        break;
        case 'A'...'G':
        case 'a'...'g':
        case 'P':
        case 'p':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          switch (ch)
          { 
            case 'C':
            case 'c':
              npoint = 0;
            break;
            case 'D':
            case 'd':
              npoint = 2;
            break;
            case 'E':
            case 'e': //190
              npoint = 4;
            break;
            case 'F':
            case 'f':
              npoint = 5;
            break;
            case 'G':
            case 'g':
              npoint = 7;
            break;
            case 'A':
            case 'a':
              npoint = 9;
            break;
            case 'B':
            case 'b':
              npoint = 11;
            break;
            case 'P':
            case 'p':
              outnote = NOTE_B0;
              n++;
              i = 0;
              while (buffer[n]>='0' && buffer[n]<='9')
              {
                numstr[i] = buffer[n];
                i++;
                n++;
              }
              numstr[i] = 0;
              n--;
              if (i>0)
              {
                sscanf(numstr,"%ld", &nlen);
                phnote(outnote, nlen);
                npoint = -10;
              }
            break;
          }
        break;
        case 'L':
        case 'l':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          n++;
          i = 0;
          while (buffer[n]>='0' && buffer[n]<='9')
          {
            numstr[i] = buffer[n];
            i++;
            n++;
          }
          numstr[i] = 0;
          n--;
          if (i>0) sscanf(numstr,"%ld", &nlen);
          //fprintf(stderr, "L%ld  ",nlen);
        break;
        case '<':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          noct--;
        break;
        case '>':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          noct++;
        break;
        case 'O':
        case 'o':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          n++;
          i = 0;
          while (buffer[n]>='0' && buffer[n]<='9')
          {
            numstr[i] = buffer[n];
            i++;
            n++;
          }
          numstr[i] = 0;
          n--;
          if (i>0) sscanf(numstr,"%d", &noct);
        break;
        case 'M':
        case 'm':
          //ignore MN, MS & ML
          n++;
        break;
        case 'N':
        case 'n':
          if (npoint>=0 && npoint<12)
          {
            if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
            else outnote = NOTE_B0;
            phnote(outnote, nlen);
            npoint = -10;
          }
          n++;
          i = 0;
          while (buffer[n]>='0' && buffer[n]<='9')
          {
            numstr[i] = buffer[n];
            i++;
            n++;
          }
          numstr[i] = 0;
          n--;
          if (i>0)
          {
            sscanf(numstr,"%d", &tn);
            npoint = (int) (tn % 12);
            noct = (int) (tn / 12);
          }
        break;
        case '\r':
        case '\n':
          //ignore these
        break;
        default:
          fprintf(stderr, "\"%c\" was not expected at this time!\n",ch);
        break;
      }//End Switch (ch)
      n++;
    }//End While (in string)
  }//End While (read)
  if (npoint>=0 && npoint<12)
  {
    if (noct>=0 && noct <7) outnote = NoteArray[noct][npoint];
    else outnote = NOTE_B0;
    phnote(outnote, nlen);
  }
  fclose(afn);
  printf("  {0,0}\r\n};\r\n");
  printf("\r\n");
  return 0;
}
