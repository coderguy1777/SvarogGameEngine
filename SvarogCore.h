#include "libs.h"
namespace SvarogEngineCore {
    Application createNewApplication(Window win, bool eState) {
        return Application(win, eState);        
    }

    void runApplication(Application a) {
        a.SvarogAppLoop();
    }
}