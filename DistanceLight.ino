    // defines pins numbers
    const int trigPin = 9;
    const int echoPin = 10;
    // defines variables
    long duration;
    double distance;
    void setup() {
      
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    pinMode(3, OUTPUT);
    
    }
    
    void loop() {
      
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delay(250);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance I think it is cm
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    //Lights the LED when the distance is close enough
    if(distance < 8){
      Serial.println("Close");
      digitalWrite(3, HIGH);
    }
    else{
        Serial.println("Far");
        digitalWrite(3, LOW);
      }
    
    }
