char chess[8][8]={                       //chess陣列對應棋盤上的棋子
  {'BT','BH','BB','BQ','BK','BB','BH','BT'},
  {'BS','BS','BS','BS','BS','BS','BS','BS'},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {'WS','WS','WS','WS','WS','WS','WS','WS'},
  {'WT','WH','WB','WQ','WK','WB','WH','WT'}
  };
int checker[8][8];
int ledout1[8],ledout2[8];
int zhi[]={2,3,4,5,6,7,8,9};             //zhi陣列對應掃描端針腳
int hen[]={10,11,12,13,14,15,16,17};     //hen陣列對應輸入端針腳
int led1[]={18,19,20,21,22,23,24,25};    //led1對應縱列LED的輸出針腳 預設HIGH
int led2[]={26,27,28,29,30,31,32,33};    //led2對應行列LED的輸出針腳 預設LOW
int num1,num2,r,c;                           //設定兩個數字暫存器
char temp;                               //設定一個文字暫存器
bool color,tookup = false;

void setup() {
  // put your setup code here, to run once:
 for(int f=0;f<8;f++){
 pinMode(zhi[f], OUTPUT);            //設定掃描腳為輸出模式
 digitalWrite(zhi[f],HIGH);          //設定輸出皆為高準位
 pinMode(hen[f],INPUT);              //設定輸入腳為輸入模式
 
 pinMode(led1[f], OUTPUT);           //設定LED縱列的接腳為輸出
 pinMode(led2[f], OUTPUT);           //設定LED行列的接腳為輸出
 digitalWrite(led1[f],HIGH);
 digitalWrite(led2[f],LOW);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  
 for(r=0;r<8;r++) {
  digitalWrite(zhi[r],LOW);
  for (c=0;c<8;c++){
    if (digitalRead(hen[c]==LOW)){


      if(chess[r][c] != 0 && tookup == false){
        temp = chess[r][c];
        chess[r][c] = 0;
        tookup = true;

        for(int x=0;x<8;x++){
           for(int y=0;y<8;y++){
             if(chess[x][y] != 0){
               checker[x][y] = 1;
               }
             else if(chess[x][y] == 0){
               checker[x][y] = 0;
               }
             }
           }
        }
      
      //城堡
      if(chess[r][c]=='WT' || chess[r][c]=='BT'){
        for(int ff=0;ff<4;ff++){
          num1=r;
          num2=c;
        while(1){
          if(ff==0){num1++;}
          if(ff==1){num1--;}
          if(ff==2){num2++;}
          if(ff==3){num2--;}
          
          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
           
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            }
          else if(chess[r][c]=='BT' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WT' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
           }
          }



      //馬
      if(chess[r][c]=='WH' || chess[r][c]=='BH'){
        for(int ff=0;ff<8;ff++){  
          num1=r;
          num2=c;
        while(1){
          if(ff==0){num1++; num2+2;}
          if(ff==1){num1++; num2-2;}
          if(ff==2){num1--; num2+2;}
          if(ff==3){num1--; num2-2;}
          if(ff==4){num1+2; num2++;}
          if(ff==5){num1+2; num2--;}
          if(ff==6){num1-2; num2++;}
          if(ff==6){num1-2; num2--;}
          
          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
           
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='BH' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WH' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
           }
          }



          //主教
      if(chess[r][c]=='WB' || chess[r][c]=='BB'){
        for(int ff=0;ff<4;ff++){  
          num1=r;
          num2=c;
        while(1){
          if(ff==0){num1++; num2++;}
          if(ff==1){num1++; num2--;}
          if(ff==2){num1--; num2++;}
          if(ff==3){num1--; num2--;}
          
          
          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
           
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            }
          else if(chess[r][c]=='BB' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WB' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
           }
          }



         //女王
      if(chess[r][c]=='WQ' || chess[r][c]=='BQ'){
        for(int ff=0;ff<8;ff++){  
          num1=r;
          num2=c;
        while(1){
          if(ff==0){num1++; num2++;}
          if(ff==1){num1++; num2--;}
          if(ff==2){num1--; num2++;}
          if(ff==3){num1--; num2--;}
          if(ff==4){num1++;}
          if(ff==5){num2++;}
          if(ff==6){num1--;}
          if(ff==7){num2--;}
          
          
          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
          
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            }
          else if(chess[r][c]=='BQ' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WQ' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
           }
          }

         //國王
      if(chess[r][c]=='WK' || chess[r][c]=='BK'){
        for(int ff=0;ff<8;ff++){  
          num1=r;
          num2=c;
        while(1){
          if(ff==0){num1++; num2++;}
          if(ff==1){num1++; num2--;}
          if(ff==2){num1--; num2++;}
          if(ff==3){num1--; num2--;}
          if(ff==4){num1++;}
          if(ff==5){num2++;}
          if(ff==6){num1--;}
          if(ff==7){num2--;}
          
          
          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
           
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='BK' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WK' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
           }
          }



      //士兵
      if(chess[r][c]=='WS' || chess[r][c]=='BS'){
        for(int ff=0;ff<2;ff++){
          num1=r;
          num2=c;
        while(1){
          if(chess[r][c] == 'WS'){
          if(ff==0){num1--; num2--;}
          if(ff==1){num1--; num2++;}
          }
          if(chess[r][c] == 'BS'){
           if(ff==0){num1++; num2--;}
           if(ff==1){num1++; num2++;}
          }

          if(chess[num1][num2]=='BT' || chess[num1][num2]=='BH' || chess[num1][num2]=='BB' ||chess[num1][num2]=='BQ' || chess[num1][num2]=='BK' || chess[num1][num2]=='BS'){
          color = false;
           }
          else if(chess[num1][num2]!=0){
          color = true;
           }
          
          if(chess[num1][num2]==0){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='BS' && color == true){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else if(chess[r][c]=='WS' && color == false){
          ledout1[num1] = 1;
          ledout2[num2] = 1;
            break;
            }
          else{break;}
          
          if(num1>8 || num2>8 || num1<0 || num2<0){ break;}
            }
            }
          }


        }
      }
      digitalWrite(zhi[r],HIGH);
    }

while(tookup==true){
  for(int x=0;x<8;x++) {
     digitalWrite(zhi[x],LOW);
  for (int y=0;y<8;y++){
      if(ledout1[x] == 1 && ledout2[y] == 1){
        digitalWrite(led1[x], LOW);
        digitalWrite(led2[y], HIGH);
        delay(20);
        digitalWrite(led1[x],HIGH);
        digitalWrite(led2[y],LOW);
        }
     if (digitalRead(hen[y]==HIGH)){
      if(checker[x][y] == 0){
        chess[x][y] = temp;
        tookup = false;
        }
      }
      }
      digitalWrite(zhi[x],HIGH);
    }
  }
  
for(int x=0;x<8;x++){
    ledout1[x]=0;
    ledout2[x]=0;
    }




 }
