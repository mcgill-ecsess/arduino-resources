#define button 8  

unsigned long timeout;
unsigned long timeout2;
char userSignal[6] = {0,0,0,0,0,0};
struct MorseLetter {
  char letter;         // 'A', 'B', etc.
  const char *code;    // Morse code as a string of 'S' and 'L'
};

// Define your dictionary
const MorseLetter morseDict[] = {
  {'A', "SL"},
  {'B', "LSSS"},
  {'C', "LSLS"},
  {'D', "LSS"},
  {'E', "S"},
  {'F', "SSLS"},
  {'G', "LLS"},
  {'H', "SSSS"},
  {'I', "SS"},
  {'J', "SLLL"},
  {'K', "LSL"},
  {'L', "SLSS"},
  {'M', "LL"},
  {'N', "LS"},
  {'O', "LLL"},
  {'P', "SLLS"},
  {'Q', "LLSL"},
  {'R', "SLS"},
  {'S', "SSS"},
  {'T', "L"},
  {'U', "SSL"},
  {'V', "SSSL"},
  {'W', "SLL"},
  {'X', "LSSL"},
  {'Y', "LSLL"},
  {'Z', "LLSS"}
};

const int morseDictSize = sizeof(morseDict)/sizeof(MorseLetter);

byte i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  Serial.println("Starting code");
}

void loop() {

  if(digitalRead(button)==LOW){
    timeout = millis()/1000;
    while(digitalRead(button)==LOW) { }
    updateuserSignal(millis()/1000 - timeout);
    delay(100);
    timeout2 = millis()/1000;
  }

  if(millis()/1000 - timeout2 > 2 ){ // last button press

      if(check(userSignal)){
      Serial.print("Your morse code decoded : ");
      // print the user input with a for loop
      Serial.print(check(userSignal));
      Serial.println();
    }
    else{
      Serial.println("Invalid Morse code")
    }
    for(int k = 0; k < 6; k++){
      userSignal[k] = 0;
      i = 0;
    }
  }
}

void updateuserSignal(unsigned long timeDiff){
  if(timeDiff < 1){
    userSignal[i++] = 'S';   // fixed
  }
  else{
    userSignal[i++] = 'L';   // fixed
  }
}

// Compare userSignal[] with morseTable entries
char check(char input[]) {
  for (int j = 0; j < morseDictSize; j++) {
    // goes over every morse code and tries to find a match
    // Another way to do would be to proceed by elimination, i.e comparing pairwise and seeing which code remains (if any)
    if (strcmp(morseDict[j].code, input) == 0) {
      return morseDict[j].letter;
    }
  }
  return false; // not found
}

