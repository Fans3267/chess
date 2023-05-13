//北科附工 913432樊立康, 913435龎世承 ,913417孫晢志
String chess[8][8]={
  {"BT","BH","BB","BQ","BK","BB","BH","BT"},
  {"BS","BS","BS","BS","BS","BS","BS","BS"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"0","0","0","0","0","0","0","0"},
  {"WS","WS","WS","WS","WS","WS","WS","WS"},
  {"WT","WH","WB","WQ","WK","WB","WH","WT"}
  };
int zhi[]={2,3,4,5,6,7,8,9};
int hen[]={10,11,12,13,14,15,16,17};
int led1[]={18,19,20,21,22,23,24,25};
int led2[]={26,27,28,29,30,31,32,33};
int ledout[8][8], checker[8][8];
int num1,num2;
int color,tookup=0;
String temp;

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
    if(digitalRead(hen[c]) == HIGH){
     
     if(tookup == 1){break;}
     if(chess[r][c] != "0"){
      delay(100);
      tookup = 1;
      temp = chess[r][c];
      ledout[r][c]=1;
      }

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
        else if(chess[num1][num2] != "0"){color = 1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BT" && color == 1){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "WT" && color == 0){ledout[num1][num2] = 1; break;}
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
        else if(chess[num1][num2] != "0"){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BB" && color == 1){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "WB" && color == 0){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BB" && color == 0){break;}
        if(chess[r][c] == "WB" && color == 1){break;}
        }
      }
    }
    
    //馬
    if(chess[r][c] == "BH" || chess[r][c] == "WH"){
      for(int aa=0;aa<8;aa++){
        num1=r;
        num2=c;
        while(1){
        if(aa==0){num1+=2; num2++; if(num1>7 || num2 >7){break;}}
        if(aa==1){num1+=2; num2--; if(num1>7 || num2 <0){break;}}
        if(aa==2){num1++; num2+=2; if(num1>7 || num2 >7){break;}}
        if(aa==3){num1++; num2-=2; if(num1>7 || num2 <0){break;}}
        if(aa==4){num1-=2; num2++; if(num1<0 || num2 >7){break;}}
        if(aa==5){num1-=2; num2--; if(num1<0 || num2 <0){break;}}
        if(aa==6){num1--; num2+=2; if(num1<0 || num2 >7){break;}}
        if(aa==7){num1--; num2-=2; if(num1<0 || num2 <0){break;}}

        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){
          color =0;
        }
        else if(chess[num1][num2] != "0"){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BH" && color == 1){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "WH" && color == 0){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BH" && color == 0){break;}
        if(chess[r][c] == "WH" && color == 1){break;}
       }
      }
    }

    //皇后
    if(chess[r][c] == "BQ" || chess[r][c] == "WQ"){
      for(int aa=0;aa<8;aa++){
        num1=r;
        num2=c;
        while(1){
        if(aa==0){num1++; if(num1==8){break;}}
        if(aa==1){num1--; if(num1<0){break;}}
        if(aa==2){num2++; if(num2==8){break;}}
        if(aa==3){num2--; if(num2<0){break;}}
        if(aa==4){num1++; num2++; if(num1==8 || num2 ==8){break;}}
        if(aa==5){num1--; num2++; if(num1<0 || num2 ==8){break;}}
        if(aa==6){num1++; num2--; if(num1==8 || num2 <0){break;}}
        if(aa==7){num1--; num2--; if(num1<0 || num2 <0){break;}}

        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){
          color =0;
        }
        else if(chess[num1][num2] != "0"){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1;}
        if(chess[r][c] == "BQ" && color == 1){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "WQ" && color == 0){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BQ" && color == 0){break;}
        if(chess[r][c] == "WQ" && color == 1){break;}
        }
      }
    }

    //國王
    if(chess[r][c] == "BK" || chess[r][c] == "WK"){
      for(int aa=0;aa<8;aa++){
        num1=r;
        num2=c;
        while(1){
        if(aa==0){num1++; if(num1==8){break;}}
        if(aa==1){num1--; if(num1<0){break;}}
        if(aa==2){num2++; if(num2==8){break;}}
        if(aa==3){num2--; if(num2<0){break;}}
        if(aa==4){num1++; num2++; if(num1==8 || num2 ==8){break;}}
        if(aa==5){num1--; num2++; if(num1<0 || num2 ==8){break;}}
        if(aa==6){num1++; num2--; if(num1==8 || num2 <0){break;}}
        if(aa==7){num1--; num2--; if(num1<0 || num2 <0){break;}}

        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){
          color =0;
        }
        else if(chess[num1][num2] != "0"){color=1;}
        else{color=2;}

        
        if(color == 2){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BK" && color == 1){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "WK" && color == 0){ledout[num1][num2] = 1; break;}
        if(chess[r][c] == "BK" && color == 0){break;}
        if(chess[r][c] == "WK" && color == 1){break;}
       }
      }
    }

    //黑小兵
    if(chess[r][c] == "BS"){
      int ab = r+1;
        if(r==1){
          if(chess[2][c] == "0" && chess[3][c] == "0"){
              for(int bb=2;bb<4;bb++){
                ledout[bb][c] = 1;
         }}}
        if(chess[ab][c] == "0"){ledout[ab][c] = 1;}
        
        for(int aa=0;aa<2;aa++){
          num1=r;
          num2=c;
        while(1){
        if(aa==0){num1++; num2++; if(num1>7 || num2 >7){break;}}
        if(aa==1){num1++; num2--; if(num1>7 || num2 <0){break;}}
        
        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){break;}
        else if(chess[num1][num2] != "0"){ledout[num1][num2] = 1; break;}
        else{break;}
          }
        }
      }

      //白小兵
    if(chess[r][c] == "WS"){
      int ab = r-1;
        if(r==6){
          if(chess[5][c] == "0" && chess[4][c] == "0"){
              for(int bb=5;bb>3;bb--){
                ledout[bb][c] = 1;
         }}}
        if(chess[ab][c] == "0"){ledout[ab][c] = 1;}
        
        for(int aa=0;aa<2;aa++){
          num1=r;
          num2=c;
        while(1){
        if(aa==0){num1--; num2--; if(num1<0 || num2 <0){break;}}
        if(aa==1){num1--; num2++; if(num1<0 || num2 >7){break;}}
        
        if(chess[num1][num2]=="BT" || chess[num1][num2]=="BH" || chess[num1][num2]=="BB" || chess[num1][num2]=="BQ" || chess[num1][num2]=="BK" || chess[num1][num2]=="BS"){ledout[num1][num2] = 1; break;}
        else if(chess[num1][num2] != "0"){break;}
        else{break;}
          }
        }
      }

    chess[r][c]="0";

      }
    }
  digitalWrite(zhi[r],HIGH);
  }

  if(tookup == 1){
  for(int a=0;a<8;a++){
    for(int b=0;b<8;b++){
      if(chess[a][b] != "0"){
        checker[a][b] = 1;
      }
      else{checker[a][b]=0;}
      }
    }
  }
while(tookup == 1){
 for(int x=0;x<8;x++){
  digitalWrite(zhi[x],LOW);
  for(int y=0;y<8;y++){
    if(ledout[x][y] == 1){
      digitalWrite(led1[x],LOW);
      digitalWrite(led2[y],HIGH);
      delay(1);
      digitalWrite(led1[x],HIGH);
      digitalWrite(led2[y],LOW);
     }
    if(digitalRead(hen[y]) == HIGH){
      if(chess[x][y] != "0" && ledout[x][y] == 1){
         chess[x][y] = "0";
         checker[x][y]=0;
       }
     }
      
    if(digitalRead(hen[y]) == LOW){
      if(checker[x][y] == 0 && ledout[x][y] == 1){
        chess[x][y] = temp;
        tookup = 0;
        }
       }
      
      
    }
    digitalWrite(zhi[x],HIGH);
   }
  }
  if(tookup == 0){
    for(int x=0;x<8;x++){
      for(int y=0;y<8;y++){
        ledout[x][y] = 0;
        }
      }
    }

  
}
