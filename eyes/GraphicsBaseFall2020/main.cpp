#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;

double eyeAngle(Graphics& g,Vec2d eyePos) {
    double rise = g.mousePos().y - eyePos.y;
    double run = g.mousePos().x - eyePos.x;
    if(run >= 0) {
        return atan(rise/run);
    }
    else {
        return 3.1415 + atan(rise/run);
    }
}

Vec2d pupilPos(Graphics& g,Vec2d eyePos) {
    Vec2d pupilPos;

    if (abs(g.mousePos().x-eyePos.x) <= abs(25*cos(eyeAngle(g,eyePos))) &&
        abs(g.mousePos().y-eyePos.y) <= abs(25*sin(eyeAngle(g,eyePos)))) {
        pupilPos = g.mousePos();
    }
    else {
        pupilPos = {eyePos.x+25*cos(eyeAngle(g,eyePos)),eyePos.y+25*sin(eyeAngle(g,eyePos))};
    }

    return pupilPos;
}

void graphicsMain(Graphics& g)
{
    Vec2d leftEyePos;
    Vec2d rightEyePos;

    Vec2d leftPupilPos;
    Vec2d rightPupilPos;

    while (g.draw()) {
        g.clear();

        leftEyePos = {g.width()/2-100,g.height()/2};
        rightEyePos = {g.width()/2+100,g.height()/2};

        leftPupilPos = pupilPos(g,leftEyePos);
        rightPupilPos = pupilPos(g,rightEyePos);

        g.ellipseC(leftEyePos,100,100,TRANSPARENT,WHITE);
        g.ellipseC(rightEyePos,100,100,TRANSPARENT,WHITE);
        g.ellipseC(leftPupilPos,50,50,TRANSPARENT,BLACK);
        g.ellipseC(rightPupilPos,50,50,TRANSPARENT,BLACK);

        for (const Event& e : g.events())
        {
            switch (e.evtType)
            {
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::MouseWheel:
                break;
            case EvtType::MouseMove:
                break;
            case EvtType::KeyPress:
                break;
            case EvtType::KeyRelease:
                break;
            default:
                break;
            }
        }
    }
}

//void graphicsMain(Graphics& g)
//{
//    TextMetrics textMetrics;

//    string message = "This is a text";

//    Vec2d pos{g.width()/2, g.height()/2};

//    while (g.draw()) {
//        g.clear();

//        // line using x1,y1,x2,y2
//        g.line(50,100,200,300,GREEN);

//        // line using two points
//        Vec2d p1{55,100};
//        Vec2d p2{205,300};
//        g.line(p1,p2,YELLOW);

//        // line with two points more compactly
//        g.line({60,100},{210,300},RED);

//        g.ellipse(20,200,50,50,WHITE);
//        g.ellipse(20,200,150,50,YELLOW);
//        g.ellipse(20,200,50,150,RED);

//        for (int i = 0; i < 100; i++) {
//            double x = g.randomDouble(50,150);
//            double y = g.randomDouble(400,500);
//            g.point(x,y,PURPLE);
//        }

//        g.text(10,g.height()-40,20,"We are using a right-handed coordinate system");
//        g.text(10,g.height()-70,20,"the point (0,0) is in the lower left");
//        g.text(0,0,50,"(0,0)");

//        g.text(pos, 20, message, YELLOW);

//        double w;
//        double h;
//        Vec2d rectPos;

//        textMetrics.rect(pos, message, 20, rectPos, w, h);

//        g.rect(rectPos, w, h, GREEN);


//        for (const Event& e : g.events())
//        {
//            switch (e.evtType)
//            {
//            case EvtType::MousePress:
//                pos = Vec2d{e.x, e.y};
//                message = "MousePress";
//                break;
//            case EvtType::MouseRelease:
//                pos = Vec2d{e.x, e.y};
//                message = "MouseRelease";
//                break;
//            case EvtType::MouseWheel:
//                break;
//            case EvtType::MouseMove:
//                pos = Vec2d{e.x, e.y};
//                message = "MouseMove";
//                break;
//            case EvtType::KeyPress:
//                message = "KeyPress: ";
//                if (isprint(e.arg)) {
//                    message.append(1, char(e.arg));
//                }
//                else {
//                    message.append(to_string(e.arg));
//                }
//                break;
//            case EvtType::KeyRelease:
//                message = "KeyRelease: ";
//                if (isprint(e.arg)) {
//                    message.append(1, char(e.arg));
//                }
//                else {
//                    message.append(to_string(e.arg));
//                }
//                break;
//            default:
//                break;
//            }
//        }
//    }
//}


int main(int /*argc*/, char** /*argv*/)
{
    // main should be empty except for the following line:
    Graphics g("Graphics", 400, 200, graphicsMain);
    return 0;
}



