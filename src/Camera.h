//
// Created by Juan Hurtado on 10/01/24.
//

#ifndef KUY_CAMERA_H
#define KUY_CAMERA_H

class Kuy;

class Camera {
protected:
    Kuy* _engine;
public:
    bool showIndicator;

    Camera(Kuy* engine) : _engine(engine) {
        showIndicator = false;
    };

    virtual void update() = 0;
};

class XAxisCamera: public Camera {
public:
    float x;

    XAxisCamera(Kuy* engine) : Camera(engine){}

    void update() override;
};

#endif //KUY_CAMERA_H
