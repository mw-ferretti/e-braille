//teste com teclado via ps2
#include <PS2Keyboard.h>

PS2Keyboard keyboard;
const int DataPin = 4;
const int IRQpin =  2;

//pinos para formar o braille
const int p[] = {0,11,9,3,10,5,6};

//pino para status
const int pinStatus = 13;

//define o intervalo de tempo entre cada letra (em milisegundo)
const int intervalo = 1000;

//pinos braille
struct br{
  int* b;
};

struct br a[257];

void setup()
{
  delay(50);
  
  pinMode(pinStatus, OUTPUT);
  
  for(int i=1;i<=6;i++){
    pinMode(p[i], OUTPUT);
    delay(1);
  }
  
  delay(50);
  keyboard.begin(DataPin, IRQpin);
  delay(50);
  Serial.begin(9600);
  
  delay(50);
  initDicBraille();
  delay(50);
}
	 
void loop()
{ 
  //apenas para feedback 
  digitalWrite(pinStatus, HIGH);
  delay(500);
  digitalWrite(pinStatus, LOW);
  delay(500);
  
  //escuta o teclado
 if(keyboard.available()){
      delay(1); 
      int dec = keyboard.read();
      delay(1);  
      Escrever(a[dec].b, (char)dec);   
 }
  
  //escuta a porta do computador conectada no arduino
  if(Serial.available()){     
     delay(1);
     int dec = Serial.read(); 
     delay(1);  
     Escrever(a[dec].b, (char)dec);
  }  
}

void Reset()
{  
    for(int i=1;i<=6;i++){
      digitalWrite(p[i], LOW);
      delay(1);
    }
    delay(50);    
}

void Escrever(int* pinos, char c){
  Reset();
  delay(1);
    int i=0;  
    for(i=0;i<6;i++){
         if(pinos[i] != 0)
           digitalWrite(pinos[i], HIGH);
         else
           break;
           
         delay(1);  
     }
  Responder(c,i > 0);     
}

void Responder(char c, boolean ok){ 
    Serial.print("Caracter '");
    delay(100);
    Serial.print(c);
    delay(100);
    if(ok){
      Serial.println("' impresso em braille com sucesso!");
    }else{
      Serial.println("' indisponivel para a interface braille!");
    }
    delay(intervalo);  
}

//inicia o dicionario braille
void initDicBraille(){
  for(int i=0;i<=256;i++){
    a[i].b = (int[]){0,0,0,0,0,0};
    delay(1);
  }
  
//carrega o dicionario braille com base na table ascii
delay(1);
    a[97].b  = (int[]){p[1],p[0],p[0],p[0],p[0],p[0]}; //                     a
delay(1);
    a[98].b  = (int[]){p[1],p[2],p[0],p[0],p[0],p[0]}; //	        b
delay(1);
    a[99].b  = (int[]){p[1],p[4],p[0],p[0],p[0],p[0]}; //	        c
delay(1);
    a[100].b = (int[]){p[1],p[4],p[5],p[0],p[0],p[0]};//	        d
delay(1);
    a[101].b = (int[]){p[1],p[5],p[0],p[0],p[0],p[0]}; //	        e
delay(1);
    a[102].b = (int[]){p[1],p[2],p[4],p[0],p[0],p[0]}; //	        f
delay(1);
    a[103].b = (int[]){p[1],p[2],p[4],p[5],p[0],p[0]}; //	g
delay(1);
    a[104].b = (int[]){p[1],p[2],p[5],p[0],p[0],p[0]}; //	        h
delay(1);
    a[105].b = (int[]){p[2],p[4],p[0],p[0],p[0],p[0]}; //	        i
delay(1);
    a[106].b = (int[]){p[2],p[4],p[5],p[0],p[0],p[0]}; //	        j
delay(1);
    a[107].b = (int[]){p[1],p[3],p[0],p[0],p[0],p[0]}; //	        k
delay(1);
    a[108].b = (int[]){p[1],p[2],p[3],p[0],p[0],p[0]}; //	        l
delay(1);
    a[109].b = (int[]){p[1],p[3],p[4],p[0],p[0],p[0]}; //	        m
delay(1);
    a[110].b = (int[]){p[1],p[3],p[4],p[5],p[0],p[0]}; //	n
delay(1);
    a[111].b = (int[]){p[1],p[3],p[5],p[0],p[0],p[0]}; //	        o
delay(1);
    a[112].b = (int[]){p[1],p[2],p[3],p[4],p[0],p[0]}; //	p
delay(1);
    a[113].b = (int[]){p[1],p[2],p[3],p[4],p[5],p[0]}; //	q
delay(1);
    a[114].b = (int[]){p[1],p[2],p[3],p[5],p[0],p[0]}; //	r
delay(1);
    a[115].b = (int[]){p[2],p[3],p[4],p[0],p[0],p[0]}; //s	
delay(1);        
    a[116].b = (int[]){p[2],p[3],p[4],p[5],p[0],p[0]}; //	t
delay(1);
    a[117].b = (int[]){p[1],p[3],p[6],p[0],p[0],p[0]}; //	        u
delay(1);
    a[118].b = (int[]){p[1],p[2],p[3],p[6],p[0],p[0]}; //	v
delay(1);
    a[119].b = (int[]){p[1],p[3],p[4],p[6],p[0],p[0]};//	x
delay(1);
    a[120].b = (int[]){p[1],p[3],p[4],p[5],p[6],p[0]}; //	y
delay(1);
    a[121].b = (int[]){p[2],p[4],p[5],p[6],p[0],p[0]}; //	w
delay(1);
    a[122].b = (int[]){p[1],p[3],p[5],p[6],p[0],p[0]}; //	z
delay(1);
    
    //maiuscula
    a[65].b = (int[]){p[1],p[0],p[0],p[0],p[0],p[0]}; //                      a
delay(1);
    a[66].b = (int[]){p[1],p[2],p[0],p[0],p[0],p[0]}; //	                b
delay(1);
    a[67].b = (int[]){p[1],p[4],p[0],p[0],p[0],p[0]}; //	                c
delay(1);
    a[68].b = (int[]){p[1],p[4],p[5],p[0],p[0],p[0]};//	        d
delay(1);
    a[69].b = (int[]){p[1],p[5],p[0],p[0],p[0],p[0]}; //	                e
delay(1);
    a[70].b = (int[]){p[1],p[2],p[4],p[0],p[0],p[0]}; //	        f
delay(1);
    a[71].b = (int[]){p[1],p[2],p[4],p[5],p[0],p[0]}; //	g
delay(1);
    a[72].b = (int[]){p[1],p[2],p[5],p[0],p[0],p[0]}; //	        h
delay(1);
    a[73].b = (int[]){p[2],p[4],p[0],p[0],p[0],p[0]}; //	                i
delay(1);
    a[74].b = (int[]){p[2],p[4],p[5],p[0],p[0],p[0]}; //	        j
delay(1);
    a[75].b = (int[]){p[1],p[3],p[0],p[0],p[0],p[0]}; //	                k
delay(1);
    a[76].b = (int[]){p[1],p[2],p[3],p[0],p[0],p[0]}; //	        l
delay(1);
    a[77].b = (int[]){p[1],p[3],p[4],p[0],p[0],p[0]}; //	        m
delay(1);
    a[78].b = (int[]){p[1],p[3],p[4],p[5],p[0],p[0]}; //	n
delay(1);
    a[79].b = (int[]){p[1],p[3],p[5],p[0],p[0],p[0]}; //	        o
delay(1);
    a[80].b = (int[]){p[1],p[2],p[3],p[4],p[0],p[0]}; //	p
delay(1);
    a[81].b = (int[]){p[1],p[2],p[3],p[4],p[5],p[0]}; //	q
delay(1);
    a[82].b = (int[]){p[1],p[2],p[3],p[5],p[0],p[0]}; //	r
delay(1);
    a[83].b = (int[]){p[2],p[3],p[4],p[0],p[0],p[0]}; //	        s
delay(1);
    a[84].b = (int[]){p[2],p[3],p[4],p[5],p[0],p[0]}; //	t
delay(1);
    a[85].b = (int[]){p[1],p[3],p[6],p[0],p[0],p[0]}; //	        u
delay(1);
    a[86].b = (int[]){p[1],p[2],p[3],p[6],p[0],p[0]}; //	v
delay(1);
    a[87].b = (int[]){p[1],p[3],p[4],p[6],p[0],p[0]};//	x
delay(1);
    a[88].b = (int[]){p[1],p[3],p[4],p[5],p[6],p[0]}; //	y
delay(1);
    a[89].b = (int[]){p[2],p[4],p[5],p[6],p[0],p[0]}; //	w
delay(1);
    a[90].b = (int[]){p[1],p[3],p[5],p[6],p[0],p[0]}; //	z
delay(1);
    
    //ascii extendido
    a[135].b = (int[]){p[1],p[2],p[3],p[4],p[6],p[0]};        //ç
delay(1);
    a[160].b = (int[]){p[1],p[2],p[3],p[5],p[6],p[0]};        //á
delay(1);
    a[130].b = (int[]){p[1],p[2],p[3],p[4],p[5],p[6]};   //é
delay(1);
    a[214].b = (int[]){p[3],p[4],p[0],p[0],p[0],p[0]};                       //í
delay(1);
    a[162].b = (int[]){p[3],p[4],p[6],p[0],p[0],p[0]};                  //ó
delay(1);
    a[163].b = (int[]){p[2],p[3],p[4],p[5],p[6],p[0]};        //ú
delay(1);
    a[131].b = (int[]){p[1],p[6],p[0],p[0],p[0],p[0]};                       //â
delay(1);
    a[136].b = (int[]){p[1],p[2],p[6],p[0],p[0],p[0]};                  //ê
delay(1);
    a[147].b = (int[]){p[1],p[4],p[5],p[6],p[0],p[0]};             //ô
delay(1);
    a[198].b = (int[]){p[3],p[4],p[5],p[0],p[0],p[0]};                  //ã
delay(1);
    a[228].b = (int[]){p[2],p[4],p[6],p[0],p[0],p[0]};                  //õ
delay(1);
    a[133].b = (int[]){p[1],p[2],p[4],p[6],p[0],p[0]};             //à
delay(1);
    a[129].b = (int[]){p[1],p[2],p[5],p[6],p[0],p[0]};             //ü
}

