#include "GameEngineHeader.h"
using namespace std;

class SvarogEngineCamera {
    public:
        double dx = 0.0;
        double dy = 0.0;
        double dz = 0.0;
        double speedval = 5.0;
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
            cameraposz += dz + speedval;
            cameraposy += dy;
            cameraposx += dx;
            camerapos.push_back(cameraposx);
            camerapos.push_back(cameraposy);
            camerapos.push_back(cameraposz);
        }

        else if(directioninput == 'SPACE' && directioninput == 'D') {
            cameraposz += dz + speedval;
            cameraposy += dy + speedval;
            cameraposx += dx;
            for(unsigned int i = 0; i < camerapos.size(); i++) {
                camerapos.pop_back();
            }
            camerapos.push_back(cameraposx);
            camerapos.push_back(cameraposy);
            camerapos.push_back(cameraposz);
        }
    }

    double camerarot(int axis, double var1, double var2, double var3) {
        double x = var1;
        double y = var2;
        double z = var3;

        double rotx1, rotx2, rotx3;
        double roty1, roty2, roty3;
        double rotz1, rotz2, rotz3;

        vector<veccoordinates>primesofxyz;
        if(axis == 1) {
            rotx1 = cos(x);
            rotx2 = -sin(x);
            rotx3 = 0;
            roty1 = sin(y);
            roty2 = cos(y);
            roty3 = 0;

            rotz1 = 1;
            rotz2 = 0;
            rotz3 = 0;


        }

        if(axis == 2) {


        }

        if(axis == 3) {

            
        }
        return var1;
    }

};