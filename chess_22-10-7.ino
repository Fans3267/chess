String chess[8][8]={                      //chess陣列對應棋盤上的棋子
  {T,H,B,Q,K,B,H,T},
  {S,S,S,S,S,S,S,S},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {S,S,S,S,S,S,S,S},
  {T,H,B,Q,K,B,H,T}};
int zhi[]={2,3,4,5,6,7,8,9};             //zhi陣列對應掃描端針腳
int hen[]={10,11,12,13,14,15,16,17};     //hen陣列對應輸入端針腳
int led1[]={18,19,20,21,22,23,24,25};    //led1對應縱列LED的輸出針腳
int led2[]={26,27,28,29,30,31,32,33};    //led2對應行列LED的輸出針腳
int num1,num2;                           //設定兩個數字暫存器
String temp;                             //設定一個文字暫存器

void setup() {
  // put your setup code here, to run once:
 for(int f=0;f<9;f++){
 pinMode(zhi[f], OUTPUT);            //設定掃描腳為輸出模式
 digitalWrite(zhi[f],HIGH);          //設定輸出皆為高準位
 pinMode(hen[f],INPUT);              //設定輸入腳為輸入模式
 
 pinMode(led1[f], OUTPUT);           //設定LED縱列的接腳為輸出
 pinMode(led2[f], OUTPUT);           //設定LED行列的接腳為輸出
 digitalWrite(led1[f],LOW);
 digitalWrite(led2[f],LOW);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int r=0;r<9;r++) {
  digitalWrite(zhi[r],LOW);
  for (int c=0;c<9;c++){
    if (digitalRead(hen[c]==LOW){
      delay(20);
      temp = chess[r][c];
      num1=r;
      num2=c;
      
      if(chess[r][c]=="T"){
        bool key1 = true;
        while(1){
          if(chess[r][c]!="0"){
          digitalWrite(led1[r],HIGH);
          digitalWrite(led2[c],HIGH);
          r++;
          }
          else{
            if(key1==true){
              digitalWrite(led1[r],HIGH);
              digitalWrite(led2[c],HIGH);
              key1=false;
              }
            else{
              break;
              }
            }
          }
        
        }
      
      }
    
    
    }
 }
}
  
  
  digitalWrite(zhi[r],HIGH);
  }
}
