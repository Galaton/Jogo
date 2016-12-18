int y1=12,y2=4,y3=5; // leds amarelos
int g1=8,g2=9; //  leds verdes
int r1=10,r2=7,r3=1,r4=6; // leds vermelhos
int botao = 3;// botao que confirma acao
int jx = A1, jy = A2; // joystick

int x = 0 , y = 0 ;
int yb,gb,rb;// backup
int ye = 0 ,g = 0,r = 0;// quantos leds de cada cor ligados

int cont = 0,zerar = 0 ,estadoDeModificacao = 0,numeroEmModificacao = 0;

void setup() {
  pinMode(y1,OUTPUT);
  pinMode(y2,OUTPUT);
  pinMode(y3,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(g2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(jy,INPUT);
  pinMode(jx,INPUT);
  pinMode(botao,INPUT);
}

void loop() {  

  if(zerar == 0)
  inicio();
  
  ligar();
  
  comeco();

if(estadoDeModificacao == 1){

  parte2();

  
}

  delay(1);
}
void inicio(){
  ye = 3;
  g = 2;
  r = 4;

}

void comeco(){

  x = analogRead(jx);
  y = analogRead(jy);
  
switch(posicaoJoystick()){
  
  case 0:
  
  break;
  case 1:
  soAmarelo();
  if(ye >0){
    if(digitalRead(botao)==LOW)
     jogo(1);
  }
  delay(1500);
  break;
  case 2:
  soVerde();
    if(g > 0){
      if(digitalRead(botao)==LOW)
       jogo(2);
    }
  delay(1500);
  break;
  case 3:
  soVermelho();
    if(r > 0){
       if(digitalRead(botao)==LOW)
       jogo(3);
    }
    
  delay(1500);
  break;
  case 4:
  soVerde();
    if(g > 0){
      if(digitalRead(botao)==LOW)
       jogo(2);
    }
  delay(1500);
  break;
}

}
void jogo(int parametro){
  switch(parametro){
    case 1://amarelo
    if(estadoDeModificacao == 0){
    gb = g;
    rb = r;
    }
    r = 0;
    g = 0;
    zerar = 1;
    estadoDeModificacao = 1;
    numeroEmModificacao = 1;
    
    break;
    case 2://verde
      zerar = 1;
      if(estadoDeModificacao == 0){
      yb = ye;
      rb = r;
      }
      ye = 0;
      r =0;
      estadoDeModificacao = 1;
      numeroEmModificacao = 2;
      
    break;
    case 3://vermehlo
      zerar = 1;
      if(estadoDeModificacao == 0){
      gb =g;
      yb = ye;
      }
      ye = 0;
      g = 0;
      estadoDeModificacao = 1;
      numeroEmModificacao = 3;
    
    break;
  }
  
}

void parte2(){
  switch(numeroEmModificacao){
    case 1://amarelo
      if(posicaoJoystick()!=0){
        if(ye == 0)
         break; 
         ye = ye - 1;
        }
      if(digitalRead(botao)==LOW){
      r =rb;
      g = gb;
      estadoDeModificacao = 0;
      numeroEmModificacao = 0;
      }
    break;
    case 2://verde

      if(posicaoJoystick()!=0){
        if(g == 0)
         break; 
          g = g-1;
        }
      if(digitalRead(botao)==LOW){
        
        ye =yb;
        r = rb; 
        estadoDeModificacao = 0;
        numeroEmModificacao = 0;
      }
      
    break;
    case 3://vermelho

      if(posicaoJoystick()!=0 ){
        if(r == 0)
         break; 
        
          r = r-1;
        }
      if(digitalRead(botao)==LOW){
        ye = yb;
        g = gb;
        estadoDeModificacao = 0;
        numeroEmModificacao = 0;
      }

  }
}
int posicaoJoystick(){
  x = analogRead(jx);
  y = analogRead(jy);
  
  if(x > 750){
      return 1;
    }else
    if(x < 100){
      return 2;
       
    }else
    if (y > 750){
    return 3;
    }else
    if(y < 100){
      return 4;
    }else{
  return 0;
    }
  }
void soAmarelo(){

      switch(ye){
  case 0:
      digitalWrite(y1,LOW);
      digitalWrite(y2,LOW);
      digitalWrite(y3,LOW);
  break;
case 1:
      digitalWrite(y1,HIGH);
      digitalWrite(y2,LOW);
      digitalWrite(y3,LOW);
break;
case 2:
    digitalWrite(y1,HIGH);
    digitalWrite(y2,HIGH);
    digitalWrite(y3,LOW);
break;
case 3:
    digitalWrite(y1,HIGH);
    digitalWrite(y2,HIGH);
    digitalWrite(y3,HIGH);
break;
}
    digitalWrite(g1,LOW);
    digitalWrite(g2,LOW);
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
  }
void soVerde(){
  switch(g){
case 0:
    digitalWrite(g1,LOW);
    digitalWrite(g2,LOW);
break;
case 1:
    digitalWrite(g1,LOW);
      digitalWrite(g2,HIGH);
break;
case 2:
      digitalWrite(g1,HIGH);
      digitalWrite(g2,HIGH);
break;
}
      digitalWrite(y1,LOW);
      digitalWrite(y2,LOW);
      digitalWrite(y3,LOW);
      digitalWrite(r1,LOW);
      digitalWrite(r2,LOW);
      digitalWrite(r3,LOW);
      digitalWrite(r4,LOW);
}
void soVermelho(){
  
    switch(r){
case 0:
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 1:
  digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 2:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 3:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
break;
case 4:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
break;

}
  digitalWrite(g1,LOW);
  digitalWrite(g2,LOW);
  digitalWrite(y1,LOW);
  digitalWrite(y2,LOW);
  digitalWrite(y3,LOW);

}

void ligar(){
  switch(ye){
  case 0:
      digitalWrite(y1,LOW);
      digitalWrite(y2,LOW);
      digitalWrite(y3,LOW);
  break;
case 1:
      digitalWrite(y1,HIGH);
      digitalWrite(y2,LOW);
      digitalWrite(y3,LOW);
break;
case 2:
    digitalWrite(y1,HIGH);
    digitalWrite(y2,HIGH);
    digitalWrite(y3,LOW);
break;
case 3:
    digitalWrite(y1,HIGH);
    digitalWrite(y2,HIGH);
    digitalWrite(y3,HIGH);
break;
}
  switch(g){
case 0:
    digitalWrite(g1,LOW);
    digitalWrite(g2,LOW);
break;
case 1:
    digitalWrite(g1,LOW);
      digitalWrite(g2,HIGH);
break;
case 2:
      digitalWrite(g1,HIGH);
      digitalWrite(g2,HIGH);
break;
}
  switch(r){
case 0:
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 1:
  digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 2:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
break;
case 3:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
break;
case 4:
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
break;

}
}

