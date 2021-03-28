#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;

Vec2d secPos(int seconds) {
    double pi = 3.1415;
    int angle = seconds + 15;
    return {-cos(pi*angle/30),sin(pi*angle/30)};
}

Vec2d minPos(int minutes) {
    double pi = 3.1415;
    int angle = minutes + 900;
    return {-cos(pi*angle/1800),sin(pi*angle/1800)};
}

Vec2d hrPos(int hours) {
    double pi = 3.1415;
    int angle = hours + 10800;
    return {-cos(pi*angle/21600),sin(pi*angle/21600)};
}

void graphicsMain(Graphics& g)
{
    Vec2d center;
    int seconds;
    int minutes;
    int hours;

    while (g.draw()) {
        g.clear();

        center = {g.width()/2,g.height()/2};
        seconds = time(nullptr) % 60;
        minutes = time(nullptr) % 3600;
        hours = time(nullptr) % 43200;

        g.ellipseC(center,400,400);
        g.line(center,center+100*hrPos(hours));
        g.line(center,center+150*minPos(minutes));
        g.line(center,center+150*secPos(seconds),RED);

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
    Graphics g("Graphics", 1200, 800, graphicsMain);
    return 0;
}



