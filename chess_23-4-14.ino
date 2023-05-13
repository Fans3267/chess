String chess[8][8]={
  {"0","0","BK","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","BT","0","0","BS","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0",}
  };
int zhi[]={2,3,4,5,6,7,8,9};
int hen[]={10,11,12,13,14,15,16,17};
int led1[]={18,19,20,21,22,23,24,25};
int led2[]={26,27,28,29,30,31,32,33};
int ledout[8][8];
int num1,num2;
int color;

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


      //城堡
      if(chess[r][c] == "BT" || chess[r][c] == "WT"){
      for(int aa=0;aa<4;aa++){
        num1=r;
        num2=c;
        while(1){
        if(aa==0){num1++; if(num1==8){break;}}
        if(aa==1){num1--; if(num1<0){break;}}
        if(aa==2){num2++; if(num2==8){break;}}
        if(aa==3){num2--; if(num2<0){break;}}
        
        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){
          color =0;
        }
        else if(chess[num1][num2] != 0){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BT" && color == 1){ledout[num1][num2] = 1;}
        if(chess[r][c] == "WT" && color == 0){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BT" && color == 0){break;}
        if(chess[r][c] == "WT" && color == 1){break;}
        }
      }
    }


    //主教
    if(chess[r][c] == "BB" || chess[r][c] == "WB"){
      for(int aa=0;aa<4;aa++){
        num1=r;
        num2=c;
        while(1){
        if(aa==0){num1++; num2++; if(num1==8 || num2 ==8){break;}}
        if(aa==1){num1--; num2++; if(num1<0 || num2 ==8){break;}}
        if(aa==2){num1++; num2--; if(num1==8 || num2 <0){break;}}
        if(aa==3){num1--; num2--; if(num1<0 || num2 <0){break;}}

        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){
          color =0;
        }
        else if(chess[num1][num2] != 0){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BB" && color == 1){ledout[num1][num2] = 1;}
        if(chess[r][c] == "WB" && color == 0){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BB" && color == 0){break;}
        if(chess[r][c] == "WB" && color == 1){break;}
        }
      }
    }









    
      }
    }
  digitalWrite(zhi[r],HIGH);
  }

 for(int x=0;x<8;x++){
  for(int y=0;y<8;y++){
    if(ledout[x][y] == 1){
      digitalWrite(led1[x],LOW);
      digitalWrite(led2[y],HIGH);
      delay(1);
      digitalWrite(led1[x],HIGH);
      digitalWrite(led2[y],LOW);
      }
    }
  }
  
}