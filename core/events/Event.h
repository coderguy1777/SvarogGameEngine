#pragma once
#ifdef EVENT_H
#define EVENT_H
#endif
using namespace std;

enum EVENT_TYPE {
    nullevt = 0,
    KeyEvent,
    MouseEvent,
    WindowEvent, 
    AudioEvent,
    TextureEvent, 
    InputEvent,
    ErrorEvent, 
};

enum class KEY_EVENT_TYPES {
    KEY_PRESS = 1,
    KEY_RELEASE = 2,
    KEY_DOUBLE_PRESS = 3,
    KEY_HOLD = 4,
};

struct Event{
    EVENT_TYPE typer;
    int PRIOITY;
    const char* cause;
};

template<typename Event>
void printEvent(Event const& event) {
    cout << "Event type: " << event.type << endl;
}

namespace Events { 
    int evtType(int category) {
        return category;
    }

    Event createEvent(EVENT_TYPE type, int PRITORITY, const char* cause) {
        return Event{type, PRITORITY, cause};
    }

    void printEvent(Event event) {
        int eventType = evtType(static_cast<int>(event.typer));
        String eventTypestr;
        switch(eventType) {
            case 1:
                eventTypestr.str = "KEY_EVENT";
                break;
            case 2:
                eventTypestr.str = "MOUSE_EVENT";
                break;
            case 3: 
                eventTypestr.str = "WINDOW_EVENT";
                break;
            case 4: 
                eventTypestr.str = "AUDIO_EVENT";
                break;
            case 5:
                eventTypestr.str = "TEXTURE_EVENT";
                break;
            case 6:
                eventTypestr.str = "INPUT_EVENT";
                break;
            case 7:
                eventTypestr.str = "ERROR_EVENT";
                break;
            default :
                eventTypestr.str = "NULL";
                break;
        }

        cout << "Event type: " << eventTypestr.str << endl;
        cout << '\n';
        cout << "Event Priority: " << event.PRIOITY << endl;
        cout << '\n';
        cout << "Event Cause: " << event.cause << endl;
    }


}