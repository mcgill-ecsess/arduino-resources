#define LED 8

struct MorseLetter {
  char letter;         // 'A', 'B', etc.
  const char *code;    // Morse code as a string of 'S' and 'L'
};

const MorseLetter morseDict[] = {
  {'A', "SL"}, {'B', "LSSS"}, {'C', "LSLS"}, {'D', "LSS"}, {'E', "S"},
  {'F', "SSLS"}, {'G', "LLS"}, {'H', "SSSS"}, {'I', "SS"}, {'J', "SLLL"},
  {'K', "LSL"}, {'L', "SLSS"}, {'M', "LL"}, {'N', "LS"}, {'O', "LLL"},
  {'P', "SLLS"}, {'Q', "LLSL"}, {'R', "SLS"}, {'S', "SSS"}, {'T', "L"},
  {'U', "SSL"}, {'V', "SSSL"}, {'W', "SLL"}, {'X', "LSSL"}, {'Y', "LSLL"},
  {'Z', "LLSS"}
};

const int morseDictSize = sizeof(morseDict) / sizeof(MorseLetter);


const char* check(char input) {
  //TODO : iterate over the MorseLetter table to find a match with the input letter
  // If there is a match, return the associated code i.e morseDict[i].code for the ith element 
  // Tip : to find the ith letter use morseDict[i].letter. Use a for loop

  return NULL; // not found
}

void morsetoLED(const char *code) {
  for (const char *p = code; *p != '\0'; p++) {
    if (*p == 'S') {
      //TODO : blink the LED to make a 'S'
    }
    if (*p == 'L') {
      Serial.print("Long");
      //TODO : blink the LED to make a 'L'
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() > 0) {
      char letter = toupper(input[0]);       // take the first character and make it uppercase
      const char* code = check(letter);
      if (code) {
        morsetoLED(code);
      } else {
        Serial.println("Letter not found!");
      }
    }
  }
}
