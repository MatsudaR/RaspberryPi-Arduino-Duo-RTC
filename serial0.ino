#include <stdio.h>


char dato[7];
char datt[7];
char dath[7];
char datf[7];
char dat0;
int dat1;
int dat2;
int a_Inq;
int a_Inr;
char num0[5];
char num1[5];


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available() >= 5) {  // 受信バッファに 5文字以上たまったら
    dat0 = Serial.read();
    if(dat0 == 'o'){ 
      for(int i=0; i<5; i++) {      // for文で 4回ループし
        dato[i] = Serial.read();     // 1バイトずつデータを格納
      }
     dato[5] = '\0';                // データの最後に文字の終端コードを入れる
     dat1 = atoi(dato);
     analogWriteResolution(10);
     analogWrite(DAC0,dat1);
    }
    else if(dat0 == 'p'){
      for(int i=0; i<5; i++) {      // for文で 4回ループし
        datt[i] = Serial.read();     // 1バイトずつデータを格納
      }
    datt[5] = '\0';                // データの最後に文字の終端コードを入れる
    dat2 = atoi(datt);
    analogWriteResolution(10);
    analogWrite(DAC1,dat2);
    }
    else if(dat0 == 'q'){ 
      for(int i=0; i<5; i++) {      // for文で 3回ループし
        dath[i] = Serial.read();     // 1バイトずつデータを格納
      }
      //dath = 0;
      a_Inq = analogRead(A0);
      sprintf(num0,"%04d",a_Inq);
      //num0 = num0 + '\0';
      Serial.print(num0);
    }
    else if(dat0 == 'r'){ 
      for(int i=0; i<5; i++) {      // for文で 3回ループし
        datf[i] = Serial.read();     // 1バイトずつデータを格納
      }
      //datf = 0;
      a_Inr = analogRead(A1);
      sprintf(num1,"%04d",a_Inr);
      //num1 = num1 + '\0';
      Serial.print(num1);
    }
  }
  //else {
    //analogWrite(DAC0,dat1);
    //analogWrite(DAC1,dat2);
  //}
}

