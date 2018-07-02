//============================================================================//
// File:          hello.c                                                     //
// Description:  Simple "Hello world" example                                 //
//                                                                            //
// Copyright 2017 MicroControl GmbH & Co. KG                                  //
// 53844 Troisdorf - Germany                                                  //
// www.microcontrol.net                                                       //
//                                                                            //
//----------------------------------------------------------------------------//
// Redistribution and use in source and binary forms, with or without         //
// modification, are permitted provided that the following conditions         //
// are met:                                                                   //
// 1. Redistributions of source code must retain the above copyright          //
//    notice, this list of conditions, the following disclaimer and           //
//    the referenced file 'LICENSE'.                                          //
// 2. Redistributions in binary form must reproduce the above copyright       //
//    notice, this list of conditions and the following disclaimer in the     //
//    documentation and/or other materials provided with the distribution.    //
// 3. Neither the name of MicroControl nor the names of its contributors      //
//    may be used to endorse or promote products derived from this software   //
//    without specific prior written permission.                              //
//                                                                            //
// Licensed under the Apache License, Version 2.0 (the "License");            //
// you may not use this file except in compliance with the License.           //
// You may obtain a copy of the License at                                    //
//                                                                            //
//    http://www.apache.org/licenses/LICENSE-2.0                              //
//                                                                            //
// Unless required by applicable law or agreed to in writing, software        //
// distributed under the License is distributed on an "AS IS" BASIS,          //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   //
// See the License for the specific language governing permissions and        //
// limitations under the License.                                             //
//============================================================================//


/*----------------------------------------------------------------------------*\
** Include files                                                              **
**                                                                            **
\*----------------------------------------------------------------------------*/

#include <stdio.h>           // printf()
#include <stdlib.h>          // exit()
#include <unistd.h>          // sleep()

#include "umic_led.h"        // access to LEDs




//----------------------------------------------------------------------------//
// main()                                                                     //
//                                                                            //
//----------------------------------------------------------------------------//
int main(int argc, char *argv[])
{
   printf("Hello world!\n");

   //----------------------------------------------------------------
   // do some LED blinking with LED 3 and LED 4, make sure that
   // the LEDs are not switched on
   //
   umic_led_clr(eUMIC_LED3_GREEN);
   umic_led_clr(eUMIC_LED3_RED);
   umic_led_clr(eUMIC_LED4_GREEN);
   umic_led_clr(eUMIC_LED4_RED);

   //----------------------------------------------------------------
   // switch LED 3 on for one second
   //
   umic_led_set(eUMIC_LED3_GREEN);
   sleep(1);
   umic_led_clr(eUMIC_LED3_GREEN);

   //----------------------------------------------------------------
   // switch LED 4 on for one second
   //
   umic_led_set(eUMIC_LED4_GREEN);
   sleep(1);
   umic_led_clr(eUMIC_LED4_GREEN);

   printf("Your first program is going to quit.\n");
   exit(0);
}
