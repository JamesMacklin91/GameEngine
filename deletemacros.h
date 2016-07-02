#ifndef _DELTEMACRO_H
#define _DELETEMACRO_H

//defines
//macro for releasing COM object
#define SafeRelease(x) {if(x){x->Release(); x = nullptr;}}
//macro for deleting objects
//nullptr is assigned when deleting objects because when something is deleted the value becomes invalid
//using nullptr means we can see that something must be wrong

#define SafeDelete(x) {if(x){delete x; x = nullptr;}}

#endif