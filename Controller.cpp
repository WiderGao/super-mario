#include "Controller.h"

void Controller::welcome()
{
    play_music("welcome");
    while(true)
    {
        show_ui("welcome");
        if(GetAsyncKeyState(VK_RETURN))
            break;
        if(GetAsyncKeyState(VK_ESCAPE))
            exit(0);
    }
}

void Controller::win()
{
    play_music("win");
    show_ui("win");
    while(!GetAsyncKeyState(VK_RETURN));
}

void Controller::lose()
{
    play_music("lose");
    show_ui("lose");
    while(!GetAsyncKeyState(VK_RETURN));
}

void Controller::play_music(string type)
{
    if(type == "welcome") {
        mciSendString(_T("close all"), NULL, 0, NULL);//ֹͣ��������
        mciSendString(_T("open \"assets\\audios\\bg.mp3\" alias welcome"), NULL, 0, NULL);//��ӭ����
        mciSendString(_T("play welcome repeat"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "gaming") {
        mciSendString(_T("close all"), NULL, 0, NULL);//ֹͣ��������
        mciSendString(_T("open \"assets\\audios\\bg.mp3\" alias gaming"), NULL, 0, NULL);//��������
        mciSendString(_T("play gaming"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "accele") {
        mciSendString(_T("stop gaming"), NULL, 0, NULL);//ֹͣ��������
        mciSendString(_T("open \"assets\\audios\\bg_accele.mp3\" alias accele"), NULL, 0, NULL);//�������ּ���
        mciSendString(_T("play accele"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "jump") {
        mciSendString(_T("close jump"), NULL, 0, NULL);
        mciSendString(_T("open \"assets\\audios\\jump.mp3\" alias jump"), NULL, 0, NULL);//��Ծ����
        mciSendString(_T("play jump"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "win") {
        mciSendString(_T("close all"), NULL, 0, NULL);//ֹͣ��������
        mciSendString(_T("open \"assets\\audios\\win.mp3\" alias win"), NULL, 0, NULL);//ʤ������
        mciSendString(_T("play win"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "lose") {
        mciSendString(_T("close all"), NULL, 0, NULL);//ֹͣ��������
        mciSendString(_T("open \"assets\\audios\\mario_death.mp3\" alias lose"), NULL, 0, NULL);//ʧ������
        mciSendString(_T("play lose"), NULL, 0, NULL);//ѭ������
    }
    else if(type == "killenemy") {
        mciSendString(_T("close killenemy"), NULL, 0, NULL);
        mciSendString(_T("open \"assets\\audios\\enemy_death.mp3\" alias killenemy"), NULL, 0, NULL);//Ұ����������
        mciSendString(_T("play killenemy"), NULL, 0, NULL);//ѭ������
    }
}

void Controller::show_ui(string type)
{
    if(type == "welcome") {
        IMAGE bg;
        loadimage(&bg, _T("assets\\images\\map1.png"));
        putimage(0, 0 , &bg);

        setfillcolor(RGB(191, 120, 16));
        setlinecolor(RGB(123, 61, 0));
        setlinestyle(PS_SOLID, 3);
        fillroundrect(60, 60, WINDOWS_WIDTH - 60, WINDOWS_HEIGHT - 120, 16, 16);
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        LOGFONT f;
        gettextstyle(&f);
        f.lfHeight = 64;
        f.lfWidth = 0;
        f.lfWeight = FW_BOLD;
        f.lfQuality = ANTIALIASED_QUALITY;
        wcscpy_s(f.lfFaceName, _T("����"));
        settextstyle(&f);
        RECT r = {60,60,WINDOWS_WIDTH - 60,WINDOWS_HEIGHT - 240};
        drawtext(_T("���������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        f.lfHeight = 18;
        settextstyle(&f);
        r = {60,280,WINDOWS_WIDTH - 60,WINDOWS_HEIGHT - 240};
        drawtext(_T("��Enter����ʼ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        r = {60,360,WINDOWS_WIDTH - 60,WINDOWS_HEIGHT - 240};
        drawtext(_T("��Esc���˳�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else if(type == "lose") {
        setfillcolor(RGB(191, 120, 16));
        setlinecolor(RGB(123, 61, 0));
        setlinestyle(PS_SOLID, 3);
        fillroundrect(60, 60, WINDOWS_WIDTH - 60, WINDOWS_HEIGHT - 240, 16, 16);
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        LOGFONT f;
        gettextstyle(&f);
        f.lfHeight = 64;
        f.lfWidth = 0;
        f.lfWeight = FW_BOLD;
        f.lfQuality = ANTIALIASED_QUALITY;
        wcscpy_s(f.lfFaceName, _T("����"));
        settextstyle(&f);
        RECT r = {60,60,WINDOWS_WIDTH - 60,180};
        drawtext(_T("You Lose!"), &r, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
        f.lfHeight = 18;
        settextstyle(&f);
        r = {60,180,WINDOWS_WIDTH - 60,WINDOWS_HEIGHT - 240};
        drawtext(_T("��Enter������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else if(type == "win") {
        setfillcolor(RGB(191, 120, 16));
        setlinecolor(RGB(123, 61, 0));
        setlinestyle(PS_SOLID, 3);
        fillroundrect(60, 60, WINDOWS_WIDTH - 60, WINDOWS_HEIGHT - 240, 16, 16);
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        LOGFONT f;
        gettextstyle(&f);
        f.lfHeight = 64;
        f.lfWidth = 0;
        f.lfWeight = FW_BOLD;
        f.lfQuality = ANTIALIASED_QUALITY;
        wcscpy_s(f.lfFaceName, _T("����"));
        settextstyle(&f);
        RECT r = {60,60,WINDOWS_WIDTH - 60,180};
        drawtext(_T("You Win!"), &r, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
        f.lfHeight = 18;
        settextstyle(&f);
        r = {60,180,WINDOWS_WIDTH - 60,WINDOWS_HEIGHT - 240};
        drawtext(_T("��Enter������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    FlushBatchDraw();
}
