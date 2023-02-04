

const int led1 = 7;            //Ledurile 1 si 2, desemnate pentru semnalizarile stanga fata respectiv stanga spate
const int led2 = 8;
const int led3 = 12;            //Ledurile 3 si 4, desemnate pentru semnalizarile 
const int led4 = 13;




void setup() {


pinMode(2, INPUT);     //Desemnam maneta de semnalizare si butonul de avarii ca si input-uri
pinMode(4, INPUT);

pinMode(led1, OUTPUT);          //Desemnam cele 4 leduri ca si output-uri
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

}

void loop() {

//Declaram starile manetei si ale butonului
int TSLeverState = digitalRead(2);
int HazButtonState = digitalRead(4);



if (TSLeverState == HIGH) {
// Daca pozitia switch-ului SPDT folosit pentru semnalizare este HIGH
// atunci ledurile de pe partea stanga intra in operatiune
digitalWrite(led1, HIGH);       // Pornim ledurile de pe partea stanga
digitalWrite(led2, HIGH);
delay(400);                     // Asteptam timpul indicat
digitalWrite(led1, LOW);        // Oprim ledurile de pe partea stanga
digitalWrite(led2, LOW);
delay(400);                     // Asteptam timpul indicat iar procesul se reia
} else {  
// Daca pozitia switch-ului SPDT folosit pentru semnalizare este LOW(0)
// atunci ledurile de pe partea dreapta intra in operatiune
digitalWrite(led3, HIGH);       // Pornim ledurile de pe partea dreapta
digitalWrite(led4, HIGH);
delay(400);                     // Asteptam timpul indicat
digitalWrite(led3, LOW);        // Oprim ledurile de pe partea dreapta
digitalWrite(led4, LOW);
delay(400);                     // Asteptam timpul indicat iar procesul se reia
}




if (HazButtonState == HIGH) {
// Daca pozitia switch-ului SPST folosit pentru avarii este HIGH
// atunci ledurile de pe ambele intra in operatiune  
digitalWrite(led1, HIGH);       // Pornim toate ledurile
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);  
digitalWrite(led4, HIGH);
delay(400);                     // asteptam timpul indicat
digitalWrite(led1, LOW);        // Oprim toate ledurile
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);   
digitalWrite(led4, LOW);
delay(400);                     // asteptam timpul indicat iar procesul se reia
} else {
// Daca pozitia switch-ului SPST folosit pentru avarii este LOW
// atunci ledurile raman stinse  
digitalWrite(led1, LOW);   
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);   
digitalWrite(led4, LOW);
}



}
