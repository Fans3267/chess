int zhi[]={2,3,4,5,6,7,8,9};
int hen[]={10,11,12,13,14,15,16,17};
int led1[]={18,19,20,21,22,23,24,25};
int led2[]={26,27,28,29,30,31,32,33};


void setup() {
  // put your setup code here, to run once:
for(int f=0;f<8;f++){
 pinMode(zhi[f], OUTPUT);
 digitalWrite(zhi[f],HIGH);
 pinMode(hen[f],INPUT);
 digitalWrite(hen[f],HIGH);
 
 pinMode(led1[f], OUTPUT);
 pinMode(led2[f], OUTPUT);
 digitalWrite(led1[f],HIGH);
 digitalWrite(led2[f],LOW);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int r=0;r<8;r++){
  digitalWrite(zhi[r],LOW);
  for(int c=0;c<8;c++){
    if(digitalRead(hen[c]) == LOW){
      digitalWrite(led1[r],LOW);
      digitalWrite(led2[c],HIGH);
      delay(100);
      digitalWrite(led1[r],HIGH);
      digitalWrite(led2[c],LOW);
      }
    }
  digitalWrite(zhi[r],HIGH);
  }
}
