#include <Wire.h>
#include <MultitapKeypad.h>

// Prototypes
//=====================================================
void Serial_Init(void);
void I2C_InitSlave(void);

// Globals
//=====================================================


// creates kpd as MultitapKeypad object
// for matrix 4 x 3 keypad
// MultitapKeypad kpd( ROW0, ROW1, ROW2, ROW3, COL0, COL1, COL2 );
// for matrix 4 x 4 keypad
MultitapKeypad kpd( 2, 3, 4, 5, 6, 7, 8, 9 );
Key key;// key as Key object
const byte BEEP = 13;

byte value = 0xFF;

// Setup
//=====================================================

void setup() {
  Serial_Init();
  I2C_InitSlave();
  //keys
//  Serial.println( F( "Key States Test on Serial Monitor" ) );
//  Serial.println( F( "by ZulNs" ) );
//  Serial.println();
//  Serial.println( F( "Press * key to begin..." ) );
//  // wait until [*] key has been pressed
//  do {
//    key = kpd.getKey();
//  } while ( key.beforeLastCode != NO_KEY || key.lastCode != KEY_ASTERISK || key.code != NO_KEY );
//  tone( BEEP, 4000, 50 );
//  Serial.println();
//  Serial.println( F( "Now you can test any key states..." ) );
//  Serial.println();
  
}

// Loop
//=====================================================
void loop() {
  key = kpd.getKey();
//  Serial.print( F( "Key " ) );
//  if ( key.character > 0 )
//    Serial.print( char( key.character ) );
//  else
//    Serial.print( F( "??" ) );

    
  switch ( key.state ) {
  case KEY_DOWN:
  case MULTI_TAP:
//    Serial.print( F( "Key " ) );
    if ( key.character > 0 )
    {
      value = key.character;
    }
    else
    {
      value = 0xff;
    }
    Serial.print( char( value ) );
    break;
  case LONG_TAP:
//    Serial.println( F( " hold" ) );
    break;
  case MULTI_KEY_DOWN:
//    Serial.println( F( " down" ) );
    break;
  case KEY_UP:
    value = 0xff;
    Serial.print( char( value ) );
    break;
  }

}


// Implementations
//=====================================================

void Serial_Init(void){
  Serial.begin(115200);
  Serial.print("Hello!");
}


void I2C_InitSlave(void){
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(value); // respond with message
  // as expected by master
}
