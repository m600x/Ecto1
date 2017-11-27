/*
* Lego Ecto-1 firmware using arduino Nano.
* See: https://www.eurobricks.com/forum/index.php?/forums/topic/108459-lego-21108-ghostbusters-ecto-1-fully-enlightened/
*/
#define		TIMING				100
#define		PIN_FLASH_RED		5 //Red light on the front roof top
#define		PIN_FLASH_BLUE_1	10 //Front blue light on roof top 1
#define		PIN_FLASH_BLUE_2	11 //Front blue light on roof top 2
#define		PIN_FLASH_BLUE_S	3 //Flasher on the left side, sidemirror
#define		PIN_STROBE_1		2 //Front flashing headlight 1
#define		PIN_STROBE_2		4 //Front flashing headlight 2
#define		PIN_HEADLIGHTS		12 //Headlight
#define		PIN_TAILLIGHTS		13 //Tail light
int			beacon[] = { 6, 7, 8, 9 }; //Beacon on roof top. 4 beacon which make 4 LED per pin.

void Starting_Sequence()
{
	digitalWrite(PIN_TAILLIGHTS, HIGH);
	delay(2000);
	digitalWrite(PIN_HEADLIGHTS, HIGH);
	delay(2000);
	for (int i = 0; i < 6; i++)
	{
		digitalWrite(PIN_HEADLIGHTS, LOW);
		delay(20);
		digitalWrite(PIN_HEADLIGHTS, HIGH);
		delay(150);
	}
	digitalWrite(PIN_STROBE_1, HIGH);
	digitalWrite(PIN_STROBE_2, HIGH);
	delay(1000);
	digitalWrite(PIN_FLASH_BLUE_S, HIGH);
	delay(1000);
	digitalWrite(PIN_FLASH_BLUE_1, HIGH);
	delay(500);
	digitalWrite(PIN_FLASH_BLUE_2, HIGH);
	delay(1000);
	digitalWrite(PIN_FLASH_RED, HIGH);
	delay(1000);
	for (int i = 0; i < 4; i++)
	{
		digitalWrite(beacon[i], HIGH);
		delay(500);
	}
	delay(1500);
}

void set_lights(int a, int b, int c, int d, int strobe)
{
	analogWrite(PIN_FLASH_BLUE_S, a);
	analogWrite(PIN_FLASH_BLUE_1, b);
	analogWrite(PIN_FLASH_BLUE_2, c);
	analogWrite(PIN_FLASH_RED, d);
	digitalWrite(strobe, digitalRead(strobe) == HIGH ? LOW : HIGH);
	delay(25);
}

void setup()
{
	for (int i = 0; i < 4; i++)
	{
		pinMode(beacon[i], OUTPUT);
	}
	pinMode(PIN_FLASH_RED, OUTPUT);
	pinMode(PIN_FLASH_BLUE_1, OUTPUT);
	pinMode(PIN_FLASH_BLUE_2, OUTPUT);
	pinMode(PIN_FLASH_BLUE_S, OUTPUT);
	pinMode(PIN_STROBE_1, OUTPUT);
	pinMode(PIN_STROBE_2, OUTPUT);
	pinMode(PIN_HEADLIGHTS, OUTPUT);
	pinMode(PIN_TAILLIGHTS, OUTPUT);
	Starting_Sequence();
}

void loop()
{
	digitalWrite(beacon[1], HIGH);
	set_lights(0, 250, 0, 0, PIN_STROBE_1);
	set_lights(60, 190, 60, 60, PIN_STROBE_1);
	set_lights(130, 130, 130, 130, PIN_STROBE_2);
	set_lights(190, 60, 190, 190, PIN_STROBE_2);
	set_lights(250, 10, 250, 250, PIN_STROBE_1);
	digitalWrite(beacon[1], LOW);
	for (int i = 2; i < 4; i++) {
		digitalWrite(beacon[i], HIGH);
		delay(TIMING);
		digitalWrite(beacon[i], LOW);}
	for (int i = 3; i >= 0; i--){
		digitalWrite(beacon[i], LOW);}
	digitalWrite(beacon[0], HIGH);
	set_lights(190, 60, 190, 190, PIN_STROBE_1);
	set_lights(130, 130, 130, 130, PIN_STROBE_2);
	set_lights(60, 190, 60, 60, PIN_STROBE_2);
	set_lights(0, 250, 0, 0, PIN_STROBE_1);
	digitalWrite(beacon[0], LOW);
}
