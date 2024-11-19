
int i = 0; 
int k = 1; 

void setup() {
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
}

void loop() {
  analogWrite(9,200);
  digitalWrite(10,HIGH);
  delay(990);
  digitalWrite(10,LOW);
  delay(5);
  

//   if (k == 1) { 
//     i -= 1; 
//     if (i <= 0) {
//       k = 0; 
//     }
//   } else { 
//     if (i < 255) { 
//       i += 1; 
//     } else {
//       k = 1; 
//     }
//   }
  }

