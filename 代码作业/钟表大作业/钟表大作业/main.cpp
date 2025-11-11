#include <graphics.h>   
#include "mouth.h"
#include "bow_multi.h" 
#include "fleur.h"    
#include <ctime>       
#include <cmath>        
#include <conio.h>      
#include <tchar.h>    
#include<iostream>
#include <vector>   
#define PI 3.1415926
void drawSDFLine(int x1, int y1, int x2, int y2, COLORREF color, double thickness = 1.5)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double len2 = dx * dx + dy * dy;
    if (len2 < 1e-6) {
        putpixel(x1, y1, color);
        return;
    }
    double len = sqrt(len2);
    int minx = (int)fmin(x1, x2) - thickness - 1;
    int maxx = (int)fmax(x1, x2) + thickness + 1;
    int miny = (int)fmin(y1, y2) - thickness - 1;
    int maxy = (int)fmax(y1, y2) + thickness + 1;
    for (int y = miny; y <= maxy; ++y)
    {
        for (int x = minx; x <= maxx; ++x)
        {
            double t = ((x - x1) * dx + (y - y1) * dy) / len2;
            t = fmax(0.0, fmin(1.0, t));
            double px = x1 + t * dx;
            double py = y1 + t * dy;
            double dist = sqrt((x - px) * (x - px) + (y - py) * (y - py));
            double edgeWidth = thickness * 1.2;
            double alpha = fmax(0.0, fmin(1.0, 1.0 - dist / edgeWidth));
            if (alpha > 0.01)
            {
                COLORREF bg = getpixel(x, y);
                int r = (int)(GetRValue(bg) * (1 - alpha) + GetRValue(color) * alpha);
                int g = (int)(GetGValue(bg) * (1 - alpha) + GetGValue(color) * alpha);
                int b = (int)(GetBValue(bg) * (1 - alpha) + GetBValue(color) * alpha);
                putpixel(x, y, RGB(r, g, b));
            }
        }
    }
}

void drawSDFCircle(int cx, int cy, int radius, COLORREF fillColor, COLORREF edgeColor, double edgeThickness = 2.0)
{
    int minx = cx - radius - edgeThickness - 1;
    int maxx = cx + radius + edgeThickness + 1;
    int miny = cy - radius - edgeThickness - 1;
    int maxy = cy + radius + edgeThickness + 1;
    for (int y = miny; y <= maxy; ++y)
    {
        for (int x = minx; x <= maxx; ++x)
        {
            double dist = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
            double diff = radius - dist;
            if (diff >= 0)
            {
                putpixel(x, y, fillColor);
            }
            else if (diff > -edgeThickness) 
            {
                double alpha = 1.0 + diff / edgeThickness; 
                COLORREF bg = getpixel(x, y);
                int r = (int)(GetRValue(bg) * (1 - alpha) + GetRValue(edgeColor) * alpha);
                int g = (int)(GetGValue(bg) * (1 - alpha) + GetGValue(edgeColor) * alpha);
                int b = (int)(GetBValue(bg) * (1 - alpha) + GetBValue(edgeColor) * alpha);
                putpixel(x, y, RGB(r, g, b));
            }
        }
    }
}
void drawFleur(int cx, int cy, double scale) {
    for (int i = 0; i < FLEUR_PIECE_N; ++i) {
        const POINT* src = nullptr;
        int n = 0;
        switch (i) {
        case 0: src = fleur0_Src; n = fleur0_N; break;
        }
        std::vector<POINT> pts(n);
        for (int j = 0; j < n; ++j) {
            pts[j].x = long((src[j].x - 100) * scale + cx);
            pts[j].y = long((src[j].y - 100) * scale + cy);
        }
        setfillcolor(RGB(213, 196, 162)); 
        solidpolygon(pts.data(), n);
        setlinecolor(RGB(0, 25, 90));   
        polyline(pts.data(), n);
    }
}
class Clock
{
private:
    int cx, cy;
    int radius;
public:
    Clock(int x, int y, int r) : cx(x), cy(y), radius(r) {}
    void drawDial()
    {
        drawSDFCircle(320, 70, 145, RGB(244, 247, 84), RGB(145, 173, 200), 0);
        setfillcolor(RGB(244, 247, 84));
        solidpie(760, 900, -120, 40, 1 * PI / 3, 2 * PI / 3);
        setfillcolor(RGB(0, 11, 88));
        solidpie(710, 850, -70, 50, 1 * PI / 3, 2 * PI / 3);
        drawSDFCircle(320, 70, 135, RGB(0, 11, 88), RGB(145, 173, 200), 0);
   //     solidpie(660, 850, -20, -30, 9 * PI / 24, 15 * PI / 24);
        setfillcolor(RGB(244, 247, 84));
        solidpie(660, 950, -20, 120, 1 * PI / 3, 2 * PI / 3);
        setfillcolor(RGB(143, 171, 212));
        solidpie(660, 960, -20, 130, 1 * PI / 3, 2 * PI / 3);
        drawSDFCircle(cx, cy, radius + 15, RGB(19, 29, 79), RGB(74, 112, 169), 3.0);
        drawSDFCircle(cx, cy, radius, RGB(239, 233, 227), RGB(255, 220, 100), 3.0);
        int ax[4] = { 265,335,418,492 };
        int ay[4] = { 172,185,187,172 };
        int bx[4] = { 206,297,428,540 };
        int by[4] = { 315,368,377,334 };
        float scale = 0.6f;
        float offsetX = -35, offsetY = 75;
        POINT mouthPts[MOUTH_N];
        for (int i = 0; i < MOUTH_N; ++i)
        {
            mouthPts[i].x = long((mouthSrc[i].x - 320) * scale + cx + offsetX);
            mouthPts[i].y = long((mouthSrc[i].y - 240) * scale + cy + offsetY);
        }
        setlinestyle(PS_NULL);
        setfillcolor(WHITE);
        fillpolygon(mouthPts, MOUTH_N);
        for (int i = 0; i < MOUTH_N; ++i)
        {
            int next = (i + 1) % MOUTH_N;
            drawSDFLine(mouthPts[i].x, mouthPts[i].y,
                mouthPts[next].x, mouthPts[next].y,
                BLACK, 1.5);
        }
        float offX = 250, offY = 400,sca=1.1f;
        for (size_t piece = 0; piece < BOW_PIECE_N; ++piece)
        {
            size_t n = 0;
            const POINT* src = nullptr;
            switch (piece)
            {
            case 0: n = BOW_0_N; src = bow0Src; break;
            case 1: n = BOW_1_N; src = bow1Src; break;
            case 2: n = BOW_2_N; src = bow2Src; break;
            default: continue;
            }
            std::vector<POINT> pts(n);
            for (size_t i = 0; i < n; ++i)
            {
                pts[i].x = long((src[i].x - 320) * sca + cx + offX);
                pts[i].y = long((src[i].y - 240) * sca + cy + offY);
            }
            setlinestyle(PS_NULL);
            setfillcolor(RED);
            fillpolygon(pts.data(), (int)n);
            for (size_t i = 0; i < n; ++i)
            {
                size_t next = (i + 1) % n;
                drawSDFLine(pts[i].x, pts[i].y,
                    pts[next].x, pts[next].y,
                    BLACK, 2.0);        
            }
        }
        
        for (int i = 0; i < 60; i++)
        {
            double angle = i * 6 * 3.1415926 / 180;
            int x1 = cx + (int)((radius - 10) * sin(angle));
            int y1 = cy - (int)((radius - 10) * cos(angle));
            int x2 = cx + (int)((radius - (i % 5 == 0 ? 25 : 15)) * sin(angle));
            int y2 = cy - (int)((radius - (i % 5 == 0 ? 25 : 15)) * cos(angle));
            drawSDFLine(x1, y1, x2, y2,
                i % 5 == 0 ? RGB(255, 210, 0) : RGB(180, 180, 180),
                i % 5 == 0 ? 2.8 : 1.5);
        }
        for (int i = 0; i < 4; i++)
        {
            int x1 = (int)((ax[i] - 320) * scale + cx + offsetX);
            int y1 = (int)((ay[i] - 240) * scale + cy + offsetY);
            int x2 = (int)((bx[i] - 320) * scale + cx + offsetX);
            int y2 = (int)((by[i] - 240) * scale + cy + offsetY);
         //   std::cout << "dx=" << (bx[i] - ax[i]) << " dy=" << (by[i] - ay[i]) << std::endl;
            drawSDFLine(x1, y1, x2, y2, BLACK, 3.0);
        }
        setfillcolor(WHITE);
        fillellipse(320, 360, 230, 200);
        setlinecolor(BLACK);
        setlinestyle(PS_SOLID, 2);
        ellipse(320, 360, 230, 200);
        fillellipse(410, 360, 320, 200);
        setlinecolor(BLACK);
        ellipse(410, 360, 320, 200);
        setfillcolor(BLACK);
        fillellipse(400, 350, 330, 210);
        fillellipse(310, 350, 240, 210);
        setfillcolor(WHITE);
        solidpie(365, 350, 330, 250, 11 * PI / 12, 13 * PI / 12);
        solidpie(275, 350, 240, 250, 11 * PI / 12, 13 * PI / 12);
        drawFleur(cx+120, cy-150, 2);

    }
    void drawHands(int hour, int minute, int second)
    {
        double rad_hour = ((hour % 12) + minute / 60.0) * 30 * PI / 180;
        double rad_min = (minute + second / 60.0) * 6 * PI / 180;
        double rad_sec = second * 6 * PI / 180;
        int hx = cx + (int)((radius - 80) * sin(rad_hour));
        int hy = cy - (int)((radius - 80) * cos(rad_hour));
        drawSDFLine(cx, cy, hx, hy, RGB(255, 215, 0), 4.0);
        int mx = cx + (int)((radius - 50) * sin(rad_min));
        int my = cy - (int)((radius - 50) * cos(rad_min));
        drawSDFLine(cx, cy, mx, my, RGB(50, 200, 255), 3.0);
        int sx = cx + (int)((radius - 35) * sin(rad_sec));
        int sy = cy - (int)((radius - 35) * cos(rad_sec));
        drawSDFLine(cx, cy, sx, sy, RGB(255, 80, 80), 1.8);
    }
};
int main()
{
    initgraph(640, 580);
    setbkcolor(RGB(143, 171, 212));
    cleardevice();
    BeginBatchDraw();
    Clock myClock(320, 340, 200);
    while (!_kbhit())
    {
        cleardevice();
        time_t now = time(0);
        tm t;
        localtime_s(&t, &now);
        myClock.drawDial();
        myClock.drawHands(t.tm_hour, t.tm_min, t.tm_sec);
        settextcolor(RGB(200, 255, 255));
        settextstyle(20, 0, _T("Consolas"));
        TCHAR buf[32];
        _stprintf_s(buf, _T("%02d:%02d:%02d"), t.tm_hour, t.tm_min, t.tm_sec);
      //  outtextxy(260, 420, buf);
        FlushBatchDraw();
        Sleep(16);
    }
    EndBatchDraw();
    _getch();
    closegraph();
    return 0;
}
