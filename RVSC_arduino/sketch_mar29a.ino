//Bluetooth HC-05
int led1 = 10;
int led2 = 9;
void setup() {
  Serial.begin(9600);//esto inicializa la comunicación
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int sensor = analogRead(A0);//lee la entrada analogica 0
  sendAndroid(); //metodo para enviar datos
  delay(250);

  if(sensor >= 409 && sensor <= 612){//condicion de temperatura corporal estable
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else if(sensor >= 613 && sensor <= 816){//condicion de temperatura corporal alta precaucion 
    digitalWrite(led2,HIGH);
    digitalWrite(led1, LOW);
  }
  else if(sensor >= 817 && sensor <=1020){//condicion de temperatura corporal alta peligro
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if(sensor >=205 && sensor <= 408){//condicion de temperatura corporal baja precaución
    digitalWrite(led2,HIGH);
    digitalWrite(led1, LOW);
  }
  else if(sensor >= 0 && sensor <= 204){//condicion de temperatura corporal baja peligro
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
}

void sendAndroid(){//obtiene los datos del sensor y los envia
  int sensor = analogRead(A0);
  Serial.print(sensor);
  Serial.print('~');
  Serial.println();
  delay(50);
}

