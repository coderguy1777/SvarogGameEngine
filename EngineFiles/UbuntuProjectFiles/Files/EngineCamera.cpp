#include "GameEngineHeader.h"
using namespace std;

class SvarogEngineCamera {
    public:
        double dx = 0.0;
        double dy = 0.0;
        double dz = 0.0;
        vector<double>camerapos;
        vector<double>camerarotation;
        vector<cameradimensions>camera1;

    void initialcamera() {
        int CAMERAHEIGHT;
        int CAMERAWIDTH;
        cout << "What would you like the camera height to be?" << endl;
        int heightvalue;
        cin >> heightvalue;
        cout << "What would you like the camera width to be?" << endl;
        int widthvalue; 
        cin >> widthvalue;
        double i, j, k = 0.0;
        camerapos.push_back(i);
        camerapos.push_back(j);
        camerapos.push_back(k);
        camera1.push_back({CAMERAHEIGHT, CAMERAWIDTH});
    }

    void cameradirection() {
        double cameraposx = 0.0;
        double cameraposy = 0.0;
        double cameraposz = 0.0;
        char directioninput = getchar();

        if(directioninput == 'SPACE') {
            cameraposz += dz + 5.0;
            cameraposy += dy;
            cameraposx += dx;
            camerapos.push_back(cameraposx);
            camerapos.push_back(cameraposy);
            camerapos.push_back(cameraposz);
        }

        else if(directioninput == 'SPACE' && directioninput == 'D') {

        }
    }

};