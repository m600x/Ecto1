// Red light on the front roof top
const int	Red_Flasher = 5;
// Two front blue light on roof top
const int	Blue_Flasher_1 = 10;
const int	Blue_Flasher_2 = 11;
// Beacon on roof top. 4 beacon which make 4 LED per pin.
const int	beacon[] = { 6, 7, 8, 9 };
// Flasher on the left side, sidemirror
const int	Blue_Flasher_Side = 3;
// Front flashing headlight
const int	Strobe_1 = 2;
const int	Strobe_2 = 4;
// Headlight
const int	Headlights = 12;
// Tail light
const int	Taillights = 13;

#define		TIMING 100;

void setup()
{
	// Setting every pins to output
	for (int i = 0; i < 4; i++)	{
		pinMode(beacon[i], OUTPUT);}
	pinMode(Red_Flasher, OUTPUT);
	pinMode(Blue_Flasher_1, OUTPUT);
	pinMode(Blue_Flasher_2, OUTPUT);
	pinMode(Blue_Flasher_Side, OUTPUT);
	pinMode(Strobe_1, OUTPUT);
	pinMode(Strobe_2, OUTPUT);
	pinMode(Headlights, OUTPUT);
	pinMode(Taillights, OUTPUT);
	// Launching the starting sequence for one time
	Starting_Sequence();
}

void loop()
{
	digitalWrite(beacon[1], HIGH);

	analogWrite(Blue_Flasher_Side, 0);
	analogWrite(Blue_Flasher_1, 250);
	analogWrite(Blue_Flasher_2, 0);
	analogWrite(Red_Flasher, 0);
	digitalWrite(Strobe_1, HIGH);
	delay(25);
	analogWrite(Blue_Flasher_Side, 60);
	analogWrite(Blue_Flasher_1, 190);
	analogWrite(Blue_Flasher_2, 60);
	analogWrite(Red_Flasher, 60);
	digitalWrite(Strobe_1, LOW);
	delay(25);
	analogWrite(Blue_Flasher_Side, 130);
	analogWrite(Blue_Flasher_1, 130);
	analogWrite(Blue_Flasher_2, 130);
	analogWrite(Red_Flasher, 130);
	digitalWrite(Strobe_2, HIGH);
	delay(25);
	analogWrite(Blue_Flasher_Side, 190);
	analogWrite(Blue_Flasher_1, 60);
	analogWrite(Blue_Flasher_2, 190);
	analogWrite(Red_Flasher, 190);
	digitalWrite(Strobe_2, LOW);
	delay(25);
	analogWrite(Blue_Flasher_Side, 250);
	analogWrite(Blue_Flasher_1, 10);
	analogWrite(Blue_Flasher_2, 250);
	analogWrite(Red_Flasher, 250);

	digitalWrite(beacon[1], LOW);

	for (int i = 2; i < 4; i++) {
		digitalWrite(beacon[i], HIGH);
		delay(TIMING);
		digitalWrite(beacon[i], LOW);}

	for (int i = 3; i >= 0; i--){
		digitalWrite(beacon[i], LOW);}

	digitalWrite(beacon[0], HIGH);

	digitalWrite(Strobe_1, HIGH);
	delay(25);
	analogWrite(Blue_Flasher_Side, 190);
	analogWrite(Blue_Flasher_1, 60);
	analogWrite(Blue_Flasher_2, 190);
	analogWrite(Red_Flasher, 190);
	digitalWrite(Strobe_1, LOW);
	delay(25);
	analogWrite(Blue_Flasher_Side, 130);
	analogWrite(Blue_Flasher_1, 130);
	analogWrite(Blue_Flasher_2, 130);
	analogWrite(Red_Flasher, 130);
	digitalWrite(Strobe_2, HIGH);
	delay(25);
	analogWrite(Blue_Flasher_Side, 60);
	analogWrite(Blue_Flasher_1, 190);
	analogWrite(Blue_Flasher_2, 60);
	analogWrite(Red_Flasher, 60);
	digitalWrite(Strobe_2, LOW);
	delay(25);
	analogWrite(Blue_Flasher_Side, 0);
	analogWrite(Blue_Flasher_1, 250);
	analogWrite(Blue_Flasher_2, 0);
	analogWrite(Red_Flasher, 0);

	digitalWrite(beacon[0], LOW);
}

void Starting_Sequence()
{
	// Turning tailight on
	digitalWrite(Taillights, HIGH);
	delay(2000);
	// Turning headlight on
	digitalWrite(Headlights, HIGH);
	delay(2000);
	// Flickering of the front headlights to simulate a starting car
	for (int i = 0; i < 6; i++){
		digitalWrite(Headlights, LOW);
		delay(20);
		digitalWrite(Headlights, HIGH);
		delay(150);}
	// Turning on the two strobe near the headlight
	digitalWrite(Strobe_1, HIGH);
	digitalWrite(Strobe_2, HIGH);
	delay(1000);
	// Turning on the side mirror flasher
	digitalWrite(Blue_Flasher_Side, HIGH);
	delay(1000);
	// Turning on the two flasher on the front roof top
	digitalWrite(Blue_Flasher_1, HIGH);
	delay(500);
	digitalWrite(Blue_Flasher_2, HIGH);
	delay(1000);
	// Turning on the red flasher on roof top
	digitalWrite(Red_Flasher, HIGH);
	delay(1000);
	// Turning each LED one by one on the beacon
	for (int i = 0; i < 4; i++){
		digitalWrite(beacon[i], HIGH);
		delay(500);}
	delay(1500);
}
